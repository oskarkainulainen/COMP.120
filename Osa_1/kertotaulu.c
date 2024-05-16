#include <stdio.h>

int main(void) {
  int i, j;

  printf("%4s", "x");
  for (i = 1; i <= 15; i++) {
    printf("%4d", i);
  }
  printf("\n");

  for (i = 1; i <= 15; i++) {
    printf("%4d", i);
    for (j = 1; j <= 15; j++) {
      printf("%4d", i * j);
    }
    printf("\n");
  }
  return 0;
}
