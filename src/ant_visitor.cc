// ant_visitor.cc - AntVisitor class implementation
// Langton Copyright (C) 2011 Dan Poggi

#include "src/ant_visitor.h"

#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "src/grid.h"

void AntVisitor::Turn(int direction) {
  if (x_direction_ == 0) {
    x_direction_ = (y_direction_ < 0) ? direction : -direction;
    y_direction_ = 0;
  } else {
    y_direction_ = (x_direction_ < 0) ? -direction : direction;
    x_direction_ = 0;
  }
}

int AntVisitor::GetNewCoordinate(int coordinate, int direction, int limit) {
  int return_value;
  int new_coordinate = coordinate + direction;

  if (new_coordinate < 0)
    return_value = 0;
  else if (new_coordinate >= limit)
    return_value = limit - 1;
  else
    return_value = new_coordinate;

  return return_value;
}

void AntVisitor::MoveForward() {
  x_ = GetNewCoordinate(x_, x_direction_, width_);
  y_ = GetNewCoordinate(y_, y_direction_, length_);
}

void AntVisitor::PrintCurrentState(Grid *grid, int iteration) {
  Clear();
  grid->Print();

  int percent_completed = floor((static_cast<double>(iteration) /
        static_cast<double>(steps_)) * 100.0);
  printf("Iteration %d out of %d (%i%%)\n",
      iteration,
      steps_,
      percent_completed);

  putchar('<');
  for (int i = 0; i < 100; ++i)
    putchar((i == percent_completed - 1) ? '%' : '-');
  printf(">\n");
}

void AntVisitor::Visit(Grid *grid) {
  length_ = grid->length();
  width_ = grid->width();
  x_ = width_ / 2;
  y_ = length_ / 2;

  for (int i = 0; i < steps_; ++i) {
    Turn(grid->node(x_, y_) ? -1 : 1);

    grid->FlipNode(x_, y_);
    MoveForward();

    if (i + 1 >= show_progress_step_) {
      PrintCurrentState(grid, i + 1);
      usleep(30000);
    }
  }

  if (show_progress_step_ > steps_)
    grid->Print();
}
