// visitor.h - Visitor class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef LANGTON_VISITOR_H_
#define LANGTON_VISITOR_H_

class Visitor {
 public:
  virtual void visit(class Grid *grid) = 0;
};

#endif
