// visitor.h - Visitor class definition
// Langton Copyright (C) 2011 Dan Poggi

#ifndef VISITOR_H_
#define VISITOR_H_

class Visitor {
 public:
  virtual ~Visitor() {}
  virtual void visit(class Grid *grid) = 0;
};

#endif  // VISITOR_H_
