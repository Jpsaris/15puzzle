#ifndef BOARD_H_
#define BOARD_H_
#include <array>
#include <iostream>
#include <ostream>
#include <vector>

#include "direction.h"

constexpr int g_consoleLines{25};
constexpr int g_rows{4};
constexpr int g_cols{4};

class Tile {
  int m_value{0};

public:
  Tile() = default;
  explicit Tile(int value) : m_value(value) {};

  bool isEmpty() const;
  int getNum() const;
  friend std::ostream &operator<<(std::ostream &out, const Tile &tile);
};

struct Point {
  int m_x{};
  int m_y{};

  Point(int x, int y) : m_x{x}, m_y{y} {};
  Point getAdjacentPoint(const Direction &d);
  bool isValid();
  friend bool operator==(const Point &a, const Point &b);
  friend bool operator!=(const Point &a, const Point &b);
};

class Board {
  Tile m_array[g_rows][g_cols];
  Point m_empty{g_rows - 1, g_cols - 1};

public:
  Board();
  void moveTile(const Direction &d);
  bool winStatus();
  friend std::ostream &operator<<(std::ostream &out, const Board &board);
};

#endif // BOARD_H_
