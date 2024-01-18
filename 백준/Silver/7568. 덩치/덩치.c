#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int N;
  scanf("%d",&N);
  int *x = malloc(sizeof(int) * N);
  int *y = malloc(sizeof(int) * N);
  for (int i=0;i<N;i++){
    scanf("%d %d",&x[i],&y[i]);
  }

  int *O = malloc(sizeof(int) *N );

  for (int i=0;i<N;i++){
    int o=1;
    for (int j=0;j<N;j++){
      if (i==j){
        continue;
      }
      if (x[i]<x[j]){
        if (y[i]<y[j]){
          o++;
        }
      }


    }
    O[i]=o;
  }
  
  for (int i=0;i<N;i++){
    printf("%d ",O[i]);
  }

  free(x);
  free(y);
  free(O);
  return 0;
}