#include "direction.h"
#include <iostream>
#include <random>

Direction Direction::operator-(const Direction &d) {
    if (d.m_car == UP) {
      return Direction{DOWN};
    }
    if (d.m_car == DOWN) {
      return Direction{UP};
    }
    if (d.m_car == LEFT) {
      return Direction{RIGHT};
    }
    if (d.m_car == RIGHT) {
      return Direction{LEFT};
    } else {
      throw std::invalid_argument("No valid direction");
    }
  }

Direction Direction::getRandom(){
    int intListP[]{0,1,2,3};

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, 3);

    return Direction{Direction::Cardinals(intListP[distr(eng)])};
}

std::ostream &operator<<(std::ostream &out, const Direction &d){
    if (d.m_car == Direction::DOWN)
        std::cout << "down";
    if (d.m_car == Direction::UP)
        std::cout << "up";
    if (d.m_car == Direction::LEFT)
        std::cout << "left";
    if (d.m_car == Direction::RIGHT)
        std::cout << "right";
    return out;
};
