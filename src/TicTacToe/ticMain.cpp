#include <string>

#include "TicTacToe/State.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
  if (argc == 5) {
    short i = stoi(argv[1]);
    short j = stoi(argv[2]);
    const unsigned char tile =
        static_cast<unsigned char>(*argv[3]);
    int depth = stoi(argv[4]);

    Player player((tile == 'O') ? true : false);
    Position pos{i, j};

    State initial(player, pos);
    Game myGame(initial, depth);
    myGame.start();
  }
  return 0;
}
