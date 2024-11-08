#include<stdlib.h>
#include<stdio.h>


int concatenatedBinary(int n){
  int res=0;
  int shift = 0;
  for(int i=1;i<=n;i++){
    if((i&(i-1))==0){
      shift++;
    }
    res = ((res<<shift)|i)%1000000007;
  }
  return res;
}

int main(){
  int n;
  printf("Enter the number n:");
  scanf("%d",&n);
  int sum = concatenatedBinary(n);
  printf("%d",sum);
  return 0;
}