// main.cc
// Langton Copyright (C) 2011 Dan Poggi

#include <cstdio>
#include "grid.h"
#include "ant_visitor.h"

int main(int argc, char *argv[]) {
  int length, width, iterations, show_progress_step;

  printf("Length: ");
  scanf("%d", &length);

  printf("Width: ");
  scanf("%d", &width);

  printf("Iterations: ");
  scanf("%d", &iterations);

  printf("Iteration to start showing progress: ");
  scanf("%d", &show_progress_step);

  Grid grid(length, width);
  AntVisitor ant(iterations, show_progress_step);
  grid.accept(&ant);
  
  return 0;
}
