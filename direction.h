#ifndef DIRECTION_H_
#define DIRECTION_H_

#include <exception>
#include <ostream>
#include <stdexcept>
class Direction {
public:
  enum Cardinals {
    UP,
    LEFT,
    DOWN,
    RIGHT,
  };

  Cardinals m_car{};

public:
  Direction(Cardinals car) : m_car(car) {};
  Direction operator-(const Direction &d);
  Direction getRandom();
  friend std::ostream &operator<<(std::ostream &out, const Direction &d);
};

#endif // DIRECTION_H_
