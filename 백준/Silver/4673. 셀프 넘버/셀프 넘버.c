#include <stdio.h>

int judge(int a);
int L[10000];

int main(void) {
  
  
  
  for (int i=0;i<10000;i++){
    L[i]=i+1;
  }

  for (int i=0;i<10000;i++){
    if(L[i]==0) continue;
    judge(L[i]);
    printf("%d\n",L[i]);
    
    }
  
  return 0;
}

int judge(int a){
  int sum = a;
  while (sum<=10000){
    int sub1 = sum;
    int sub2 = 0;
    while (sub1>0){
      int j = sub1%10;
      sub2+=j;
      sub1-=j;
      sub1/=10;
      
    }
    sum+=sub2;
    L[sum-1]=0;
  }
}