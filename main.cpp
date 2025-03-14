#include "board.h"
#include "direction.h"
#include <array>
#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

namespace UserInput {
Direction getDirection(char d) {
  if (d == 'w')
    return Direction{Direction::UP};
  if (d == 's')
    return Direction{Direction::DOWN};
  if (d == 'a')
    return Direction{Direction::LEFT};
  if (d == 'd')
    return Direction{Direction::RIGHT};
  throw std::invalid_argument("Invalid input");
}
char getCommandFromUser() {
  char line = std::getchar();
  if (line != EOF && (line == 'w' || line == 'a' || line == 's' ||
                      line == 'd' || line == 'q')) {
    return line;
  }
  return ' ';
}
}; // namespace UserInput

int main() {
  Board board{};
  std::cout << board;
  std::string line;
  std::array validCommands{"w", "a", "s", "d", "q"};
  while (true) {
    char cmd{UserInput::getCommandFromUser()};
    if (cmd == 'q')
      break;
    if (cmd != ' ') {
      Direction d{UserInput::getDirection(cmd)};
      std::cout << "You entered direction: " << (d) << '\n';
      board.moveTile(d);
      std::cout << board;
      if (board.winStatus()) {
        std::cout << "You won!";
        break;
      }
    }
  }
  std::cout << "\n\nBye!\n\n";
  return 0;
}
