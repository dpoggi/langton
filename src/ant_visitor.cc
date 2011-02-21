// ant_visitor.cc - AntVisitor class implementation
// Langton Copyright (C) 2011 Dan Poggi

#include "ant_visitor.h"
#include <cstdio>
#include <cmath>
#include "grid.h"

void AntVisitor::turn(int direction)
{
  if (x_direction_ == 0) {
    x_direction_ = (y_direction_ < 0) ? direction : -direction;
    y_direction_ = 0;
  } else {
    y_direction_ = (x_direction_ < 0) ? -direction : direction;
    x_direction_ = 0;
  }
}

int AntVisitor::get_new_coordinate(int coordinate, int direction, int limit) {
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

void AntVisitor::move_forward() {
  x_ = get_new_coordinate(x_, x_direction_, width_);
  y_ = get_new_coordinate(y_, y_direction_, length_);
}

void AntVisitor::print_current_state(Grid *grid, int iteration) {
  clear();
  grid->print();
  
  int percent_completed = floor((static_cast<double>(iteration) / static_cast<double>(steps_)) * 100.0);
  printf("Iteration %d out of %d (%i%%)\n", iteration, steps_, percent_completed);

  putchar('<');
  for (int i = 0; i < 100; ++i)
    putchar((i == percent_completed - 1) ? '%' : '-');
  printf(">\n");
}

void AntVisitor::visit(Grid *grid) {
  length_ = grid->length();
  width_ = grid->width();
  x_ = width_ / 2;
  y_ = length_ / 2;
  
  for (int i = 0; i < steps_; ++i) {
    turn(grid->node(x_, y_) ? -1 : 1);
      
    grid->flip_node(x_, y_);
    move_forward();

    if (i + 1 >= show_progress_step_) {
      print_current_state(grid, i + 1);
      usleep(30000);
    }
  }
  
  if (show_progress_step_ > steps_)
    grid->print();
}
