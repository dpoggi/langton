// grid.h - Grid class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef GRID_H_
#define GRID_H_

#include "src/visitor.h"

class Grid {
 public:
  Grid(int length, int width) : length_(length), width_(width) { init(); }
  ~Grid();

  int length() const { return length_; }
  int width() const { return width_; }

  bool node(int x, int y) const { return grid_[y][x] == ' '; }
  void flip_node(int x, int y) { grid_[y][x] = node(x, y) ? '#' : ' '; }

  void accept(Visitor *visitor) { visitor->visit(this); }

  void print() const;

 private:
  int length_, width_;
  char **grid_;

  void init();
};

#endif  // GRID_H_
