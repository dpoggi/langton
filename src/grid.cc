// grid.cc - Grid class implementation
// Langton Copyright (C) 2011 Dan Poggi

#include "grid.h"
#include <cstdio>

void Grid::init() {
  grid_ = new char*[length_];
  for (int i = 0; i < length_; ++i)
    grid_[i] = new char[width_];
  
  for (int i = 0; i < length_; ++i) {
    for (int j = 0; j < width_; ++j)
      grid_[i][j] = '#';
  }
}

Grid::~Grid() {
  for (int i = 0; i < length_; ++i)
    delete[] grid_[i];
  delete[] grid_;
}

void Grid::print() const {
  for (int i = 0; i < length_; ++i) {
    for (int j = 0; j < width_; ++j) {
      putchar(grid_[i][j]);
    }
    putchar('\n');
  }

  putchar('\n');
}
