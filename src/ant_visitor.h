// ant_visitor.h - AntVisitor class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef ANT_VISITOR_H_
#define ANT_VISITOR_H_

#include <stdlib.h>

#include "src/visitor.h"

class AntVisitor : public Visitor {
 public:
  AntVisitor(int steps, int show_progress_step)
      : steps_(steps),
        show_progress_step_(show_progress_step),
        x_(0),
        y_(0),
        x_direction_(0),
        y_direction_(1) {}

  virtual void Visit(class Grid *grid);

 private:
  int steps_, show_progress_step_,
      x_, y_, x_direction_, y_direction_,
      length_, width_;

  void Clear() const { system("clear"); }
  void Turn(int direction);
  int GetNewCoordinate(int coordinate, int direction, int limit);
  void MoveForward();
  void PrintCurrentState(Grid *grid, int iteration);
};

#endif  // ANT_VISITOR_H_
