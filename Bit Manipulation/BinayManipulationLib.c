#include<stdio.h>
#include<stdlib.h>
#include <math.h>

void Decimal2Binary(int num){
  char *bin = (char*)malloc(32*sizeof(char)); //Allocating memory as char for saving memory space.
  for(int i=0;i<32;i++){
    bin[i]=0;
  }
  int i=0;
  while(num!=0){
    int bindigit = num%2;
    num = num/2;
    bin[i] = bindigit;
    i++;
  }
  for(int i=31;i>=0;i--){
    printf("%d",bin[i]);
  }
  free(bin);
}

void Decimal2Octal(int num){
  char *octal = (char*)malloc(32*sizeof(char));
  int i=0;
  for(int i=0;i<32;i++){
    octal[i] = 0;
  }
  while(num!=0){
    int octaldigit = num%8;
    octal[i] = octaldigit;
    num = num/8;
    i++;
   }
   for(int i=31;i>=0;i--){
    printf("%d",octal[i]);
   }
   free(octal);

}

void Decimal2HexaDecimal(int num){
  char *hexdeci = (char*)malloc(32*sizeof(char));
  for(int i=0;i<32;i++){
    hexdeci[i] = '0';
  }
  int i=0;
  while(num!=0){
    int hexdigit = num%16;
    switch(hexdigit){
      case 0:
        hexdeci[i] = '0';
        break;
      case 1:
        hexdeci[i] = '1';
        break;
      case 2:
        hexdeci[i] = '2';
        break;
      case 3:
        hexdeci[i] = '3';
        break;
      case 4:
        hexdeci[i] = '4';
        break;
      case 5:
        hexdeci[i] = '5';
        break;
      case 6:
        hexdeci[i] = '6';
        break;
      case 7:
        hexdeci[i] = '7';
        break;
      case 8:
        hexdeci[i] = '8';
        break;
      case 9:
        hexdeci[i] = '9';
        break;
      case 10:
        hexdeci[i] = 'A';
        break;
      case 11:
        hexdeci[i] = 'B';
        break;
      case 12:
        hexdeci[i] = 'C';
        break;
      case 13:
        hexdeci[i] = 'D';
        break;
      case 14:
        hexdeci[i] = 'E';
        break;
      case 15:
        hexdeci[i] = 'F';
        break;
      default:
        hexdeci[i] = hexdigit;
    }
    num = num/16;
    i++;
  }
  for(int i=31;i>=0;i--){
    printf("%c",hexdeci[i]);
  }
  free(hexdeci);
}

void Decimal2BaseN(int num , int base){
  if(base>10 || base<2){
    printf("Error: Base must be within 2 and 10");
    return;
  }
  char *baseN = (char*)malloc(32*sizeof(char));
  for(int i=0;i<32;i++){
    *(baseN+i) = 0;
  }
  int i=0;
  while(num!=0){
    int baseNdigit = num%base;
    num = num/base;
    baseN[i] = baseNdigit;
    i++;
  }
  for(int i=31;i>=0;i--){
    printf("%d",baseN[i]);
  }
  free(baseN);
}

int Multiply(int n1 , int n2){
  int res = 0;
  int power2 = 0;
  while(n2>0){
    if(n2&1){
      res += n1<<power2;
    }
    power2++;
    n2 = n2>>1;
  }
  return res;
}

int FindUniqueOccurence2(int *arr , int len){
  int unique = 0;
  for(int i=0;i<len;i++){
    unique = unique^arr[i];
  }
  return unique;
}

void Finding_ith_Bit(int num , int i){
  int res = (num>>(i-1))&1;
  Decimal2Binary(num);
  printf("\n%d",res);
}

void Set_ith_Bit(int num , int i){
  int mask = 1<<(i-1);
  int set = num|mask;
  Decimal2Binary(num);
  printf("\n");
  Decimal2Binary(set);
}

void Reset_ith_Bit(int num , int i){
  int mask = ~(1<<(i-1));
  int set = num&mask;
  Decimal2Binary(num);
  printf("\n");
  Decimal2Binary(set);
}

void FindRightmostSetBit(int num){
  Decimal2Binary(num);
  int count=0;
  while((num&1)==0){
    num = num>>1;
    count++;
  }
  printf("\n%d",count);
}

int FindUniqueOccurence3(int *arr , int len){
  int unique=0;
  for(int i=0;i<32;i++){
    int sum = 0;
    for(int j=0;j<len;j++){
      if(arr[j]&((long long int)1<<i)){
        sum++;
      }
    }
    if(sum%3!=0){
      unique = unique|((long long int)1<<i);
    }
  }
  return unique;
}

void FindNthMagicNumber(int N , int base){
  int basenum = base;
  long long int magicnum = 0;
  while(N>0){
    if(N&1){
      magicnum = magicnum + basenum;
    }
    basenum = basenum*base;
    N = N>>1;
  }
  printf("%lld",magicnum);
}

int isPowerOf2(int num){
  if(num>0){
    if((num&(num-1))==0){
      return 1;
    }
  }
  return 0;
}

int NoOfDigits(int num){
  int len = (int)log2(num) + 1;
  return len;
}

int SumOfNthRowinPascalsTriangle(int N){
  return 1<<(N-1);
}

int PowerOf(int a , int b){
  int res = 1;
  int mul = 1;
  while(b>0){
    int ldigit = b&1;
    mul = mul*a;
    if(ldigit){
      res = res*mul;
    }
    b = b>>1;
  }
  return res;
}

int NoOfSetBits(int num){
  int count=0;
  while(num>0){
    if((num&1)==1){
      count++;
    }
    num = num>>1;
  }
  return count;
}

int RangeXOR(int a){
  if(a%4==0){
    return a;
  }
  else if(a%4==1){
    return 1;
  }
  else if(a%4==2){
    return a+1;
  }
  return 0;
}

