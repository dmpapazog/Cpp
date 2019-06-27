#ifndef STATE_HPP
#define STATE_HPP

#include <array>
#include <limits>
#include <list>
#include <memory>
#include <vector>

namespace std {
enum class Tile : unsigned char { X = 'X', O = 'O', b = ' ' };

struct Position {
  short i{-1};
  short j{-1};
};

enum class Final : unsigned char { MaxWin, MinWin, Draw, Continue };

struct Equation {
  short X_1{0};
  short X_2{0};
  bool X_3{false};

  short O_1{0};
  short O_2{0};
  bool O_3{false};

  Equation() = default;
  void setTerms(short& countX, short& countO);
  short int evaluate() const;
};

class Player
{
 private:
  bool player{true};

 public:
  Player() = default;
  Player(bool isMax) : player(isMax) {}

  bool isMax() const { return player; }
  void setPlayer(bool t_player) { player = t_player; }
};

class Board
{
  using T = Tile;

 private:
  array<T, 9> board{{T::b, T::b, T::b, T::b, T::b, T::b, T::b, T::b, T::b}};

 public:
  Board() = default;
  Board(const Position& start, const Tile& tile);

  bool isFull() const;

  void checkRows(Equation& eq) const;
  void checkCols(Equation& eq) const;
  void checkLeftDiag(Equation& eq) const;
  void checkRightDiag(Equation& eq) const;

  void print() const;

  T& operator[](const Position& pos);
};

class State
{
 private:
  Board board{};
  Player player{};
  Final state{Final::Continue};
  unsigned int height{0};
  State* parent{nullptr};
  int estimation{INT32_MAX};

 public:
  State() = default;
  State(const Player& t_player, const Position& position);

  void evalEstimate();
  vector<State> expand();

  Board  getBoard()      const { return board;      }
  Player getPlayer()     const { return player;     }
  Final  getState()      const { return state;      }
  int    getHeight()     const { return height;     }
  State* getParent()     const { return parent;     }
  int    getEstimation() const { return estimation; }
  Tile   getTile(Position pos) { return board[pos]; }

  void setPlayer(bool t_player) { player.setPlayer(t_player); }
  void setHeight(int temp)              { height = temp;     }
  void setEstimation(int temp)          { estimation = temp; }
  void SetTile(Position pos, Tile tile) { board[pos] = tile; }
  void setState()
  {
    evalEstimate();
    estimation = INT32_MAX;
  }

};

class Game
{
 private:
  list<State> game{0};
  const int depth{2};

  void setGrade(State& last, State& parent);
  void Minimax();

 public:
  Game(State& initial, int depth);
  void start();

  void round(State& current);
  void MiniMax(State& current);
};
}  // namespace std

#endif  // STATE_HPP>