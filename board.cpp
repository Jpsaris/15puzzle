#include "board.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <ostream>
#include <random>
#include <vector>

Point Point::getAdjacentPoint(const Direction &d) {
  switch (d.m_car) {
  case Direction::UP:
    return Point{m_x - 1, m_y};
  case Direction::DOWN:
    return Point{m_x + 1, m_y};
  case Direction::LEFT:
    return Point{m_x, m_y - 1};
  case Direction::RIGHT:
    return Point{m_x, m_y + 1};
  default:
    return *this;
  }
}

bool Point::isValid(){
    return (m_x >= 0) && (m_x < g_rows) && (m_y >= 0) && (m_y < g_cols);
  }

bool operator==(const Point &a, const Point &b) {
  return a.m_x == b.m_x && a.m_y == b.m_y;
}

bool operator!=(const Point &a, const Point &b) { return !(operator==(a, b)); }
Board::Board() {
  Point m_empty{};
  std::vector<int> intList(16);
  std::iota(intList.begin(), intList.end(), 1);
  std::random_device rd;
  std::mt19937 eng(rd());
  std::shuffle(intList.begin(), intList.end(), eng);
  for (int i{1}; i < 16; ++i) {
    int row{i / 4};
    int col{i % 4};
    int value = intList[i];
    if (value == 0){
      m_empty = {row, col};
    }
    m_array[row][col - 1] = Tile(intList[i]);
  }
}

bool Board::winStatus(){
  for (int i{1}; i < 16; ++i) {
    int row{i / 4};
    int col{i % 4};
    if(m_array[row][col - 1].getNum() != Tile(i % 16).getNum()) return false;
  }
  return true;
};

void Board::moveTile(const Direction &d) {
    Point toMove{m_empty.getAdjacentPoint(d)};
    if (toMove.isValid()){
      std::cout << "valid";
      m_array[m_empty.m_x][m_empty.m_y] = m_array[toMove.m_x][toMove.m_y];
      m_array[toMove.m_x][toMove.m_y] = Tile{0};
      m_empty = {toMove.m_x, toMove.m_y};
    }
  }


std::ostream &operator<<(std::ostream &out, const Board &board) {
  for (int i{0}; i < g_consoleLines; ++i) {
    std::cout << '\n';
  }
  for (auto &r : board.m_array) {
    for (auto &c : r) {
      std::cout << c;
    }
    std::cout << '\n';
  }
  return out;
}

bool Tile::isEmpty() const { return m_value == 0; }

int Tile::getNum() const { return m_value; }

std::ostream &operator<<(std::ostream &out, const Tile &tile) {
  if (tile.getNum() > 9)
    out << " " << tile.getNum() << " ";
  else if (tile.getNum() > 0)
    out << "  " << tile.getNum() << " ";
  else if (tile.getNum() == 0)
    out << "    ";
  return out;
}
