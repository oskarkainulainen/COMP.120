#include <stdio.h>

int main(void) {
  int i;
  int first =1;

  for (i = 1; i <= 100; i++){
    if (i % 2 != 0 && i % 3 != 0 && i % 5 != 0) {
      if (!first) {
        printf(" ");
      }
      printf("%d",i);
      first = 0;
    }
  }
  printf("\n");
  
  return 0;
}
