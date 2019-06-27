#include "State.hpp"

#include <algorithm>
#include <array>
#include <iostream>
#include <stack>

using namespace std;

template <typename Enumeration>
auto asIs(Enumeration const& value) ->
    typename underlying_type<Enumeration>::type
{
  return static_cast<typename underlying_type<Enumeration>::type>(value);
}

void Equation::setTerms(short& countX, short& countO)
{
  if (countO == 0) {
    switch (countX) {
      case 1: ++X_1; break;
      case 2: ++X_2; break;
      case 3: X_3 = true;
    }
  } else if (countX == 0) {
    switch (countO) {
      case 1: ++O_1; break;
      case 2: ++O_2; break;
      case 3: O_3 = true;
    }
  }
}

short Equation::evaluate() const { return 3 * X_2 + X_1 - (3 * O_2 + O_1); }

Tile& Board::operator[](const Position& pos)
{
  return board[pos.i * 3 + pos.j];
}

Board::Board(const Position& start, const Tile& tile)
{
  board[start.i * 3 + start.j] = tile;
}

bool Board::isFull() const
{
  for (short i = 0; i < 9; ++i) {
    if (board[i] == Tile::b) {
      return false;
    }
  }
  return true;
}

void Board::checkRows(Equation& eq) const
{
  short countX = 0, countO = 0;
  for (short i = 0; i < 3; ++i) {
    for (short j = 0; j < 3; ++j) {
      switch (board[i * 3 + j]) {
        case Tile::X: ++countX; break;
        case Tile::O: ++countO; break;
        case Tile::b: continue;
      }
    }
    eq.setTerms(countX, countO);
    countO = countX = 0;
  }
}

void Board::checkCols(Equation& eq) const
{
  short countX = 0, countO = 0;
  for (int j = 0; j < 3; ++j) {
    for (int i = 0; i < 3; ++i) {
      switch (board[i * 3 + j]) {
        case Tile::X: ++countX; break;
        case Tile::O: ++countO; break;
        case Tile::b: continue;
      }
    }
    eq.setTerms(countX, countO);
    countO = countX = 0;
  }
}

void Board::checkLeftDiag(Equation& eq) const
{
  short countX = 0, countO = 0;
  for (int i = 0, j = 0; i < 3; ++i, ++j) {
    switch (board[i * 3 + j]) {
      case Tile::X: ++countX; break;
      case Tile::O: ++countO; break;
      case Tile::b: continue;
    }
  }
  eq.setTerms(countX, countO);
}

void Board::checkRightDiag(Equation& eq) const
{
  short countX = 0, countO = 0;
  for (int i = 0, j = 2; i < 3; ++i, --j) {
    switch (board[i * 3 + j]) {
      case Tile::X: ++countX; break;
      case Tile::O: ++countO; break;
      case Tile::b: continue;
    }
  }
  eq.setTerms(countX, countO);
}

void Board::print() const
{
  for (short i = 0; i < 3; ++i) {
    cout << "| ";
    for (short j = 0; j < 3; ++j) { cout << asIs(board[i * 3 + j]) << " |"; }
    cout << '\n';
  }
}

State::State(const Player& t_player, const Position& position)
    : board(position, t_player.isMax() ? Tile::O : Tile::X), player(t_player)
{
}

void State::evalEstimate()
{
  Equation eq;

  board.checkRows(eq);
  board.checkCols(eq);
  board.checkLeftDiag(eq);
  board.checkRightDiag(eq);

  estimation = eq.evaluate();
  if (eq.X_3) {
    state = Final::MaxWin;
  } else if (eq.O_3) {
    state = Final::MinWin;
  } else if (board.isFull()) {
    state = Final::Draw;
  } else {
    state = Final::Continue;
  }
}

vector<State> State::expand()
{
  Tile fillTile = player.isMax() ? Tile::X : Tile::O;
  vector<State> children;

  for (short i = 0; i < 3; ++i) {
    for (short j = 0; j < 3; ++j) {
      Position pos{i, j};
      if (board[pos] == Tile::b) {
        children.emplace_back(*this);
        State* child = &children.back();

        child->SetTile(pos, fillTile);
        child->setPlayer(!player.isMax());
        ++child->height;
        child->parent = this;
      }
    }
  }
  return children;
}

Game::Game(State& initial, int t_depth) : depth(t_depth)
{
  game.emplace_back(initial);
}

void Game::start()
{
  State* current = &game.back();
  Final isFinished = current->getState();
  current->getBoard().print();

  while (isFinished == Final::Continue) {
    round(*current);
    current = &game.back();
    isFinished = current->getState();
    current->getBoard().print();
  }

  switch (isFinished) {
    case Final::Draw: cout << "It's a Draw\n"; break;
    case Final::MaxWin: cout << "Max Win\n"; break;
    case Final::MinWin: cout << "Min Win\n";
  }
}

void Game::round(State& current)
{
  if (current.getPlayer().isMax()) {
    MiniMax(current);
  } else {
    short count = 0;
    short i, j;
    do {
      fflush(stdin);
      if (count > 0) {
        cout << "Wrong move. Check again.\n";
      }
      cout << "Which tile do you want to fill? ";
      cin >> i >> j;
      ++count;
    } while (!(current.getTile({i, j}) == Tile::b));

    game.emplace_back(current);
    State* newState = &game.back();

    newState->setPlayer(true);
    newState->SetTile({i, j}, Tile::O);
    newState->setState();
    newState->setHeight(current.getHeight() + 1);
  }
}

void Game::MiniMax(State& current)
{
  list<State> gameTree;
  gameTree.push_back(current);
  auto iter = gameTree.begin();

  while (iter->getHeight() - current.getHeight() < depth) {
    vector<State> children = iter->expand();
    if (iter->getHeight() - current.getHeight() == depth - 1) {
      for_each(children.begin(), children.end(),
               [](auto& child) { child.evalEstimate(); });
    }
    copy(children.begin(), children.end(), back_inserter(gameTree));
    ++iter;
  }

  gameTree.pop_front();
  for_each(gameTree.rbegin(), gameTree.rend(), [this](auto& state) {
    if (state.getParent()) {
      setGrade(state, *state.getParent());
    }
  });

  for (auto& state : gameTree) {
    if (state.getEstimation() == current.getEstimation()) {
      game.push_back(state);
      game.back().setEstimation(INT32_MAX);
      break;
    }
  }
}

void Game::setGrade(State& last, State& parent)
{
  if (parent.getEstimation() == INT32_MAX) {
    parent.setEstimation(last.getEstimation());
  } else {
    bool parentIsMax = parent.getPlayer().isMax();
    int temp = parent.getEstimation();
    int estimation = last.getEstimation();

    if (parentIsMax && estimation > temp) {
      parent.setEstimation(estimation);
    } else if (!parentIsMax && estimation < temp) {
      parent.setEstimation(estimation);
    }
  }
}