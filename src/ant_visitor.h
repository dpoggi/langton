// ant_visitor.h - AntVisitor class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef LANGTON_ANT_VISITOR_H_
#define LANGTON_ANT_VISITOR_H_

#include <cstdlib>
#include "visitor.h"

class AntVisitor : public Visitor {
 public:
  AntVisitor(int steps, int show_progress_step)
      : steps_(steps),
        show_progress_step_(show_progress_step),
        x_(0),
        y_(0),
        x_direction_(0),
        y_direction_(1) {}
        
  virtual void visit(class Grid *grid);
  
 private:
  int steps_, show_progress_step_,
      x_, y_, x_direction_, y_direction_,
      length_, width_;

  void clear() const { system("clear"); }
  
  void turn(int direction);
  int get_new_coordinate(int coordinate, int direction, int limit);
  void move_forward();
  
  void print_current_state(Grid *grid, int iteration);
};

#endif
