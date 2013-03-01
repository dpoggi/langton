// grid.h - Grid class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef GRID_H_
#define GRID_H_

#include "src/visitor.h"

class Grid {
 public:
  Grid(int length, int width) : length_(length), width_(width) { Init(); }
  ~Grid();

  int length() const { return length_; }
  int width() const { return width_; }

  bool node(int x, int y) const { return grid_[y][x] == ' '; }
  void FlipNode(int x, int y) { grid_[y][x] = node(x, y) ? '#' : ' '; }

  void Accept(Visitor *visitor) { visitor->Visit(this); }

  void Print() const;

 private:
  int length_, width_;
  char **grid_;

  void Init();
};

#endif  // GRID_H_
