#include <stdio.h>

int main() {
  // declaring variable and asking for input
  int x=0;
  printf("enter a number and I'll double it: ");
  scanf("%d", &x);
  // displaying the input 
  printf("twice %d is %d\n", x, 2*x);
  return 0;
}
