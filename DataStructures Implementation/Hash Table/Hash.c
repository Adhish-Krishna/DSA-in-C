#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int Len(int num){
  int count = 0;
  while(num>0){
    count++;
    num = num/10;
  }
  return count;
}

int DivisionMethod(int val, int table_size){
  return (val%table_size);
}

int MultiplicationMethod(int val, int table_size){
  double A = 0.618033;
  int key = (int)(table_size*(fmod((val*A),1)));
  return key;
}

int MidSquareMethod(int key, int table_size) {
    long long int square = (long long int)key * (long long int)key; // Use long long for larger keys
    int num_digits = (int)log10(square) + 1; // Count number of digits in the square
    // Pad the number to have at least 4 digits if it's less than 4 digits
    if (num_digits < 4) {
        square *= pow(10, 4 - num_digits); // Add leading zeros conceptually
        num_digits = 4; // Now consider it as a 4-digit number
    }
    // Extract middle 2 digits
    int mid = num_digits / 2; // Middle position
    int divisor = pow(10, mid - 1); // Divide to bring middle to the end
    int middle_digits = (square / divisor) % 100; // Extract 2 middle digits
    // Return hash value within table size
    return middle_digits % table_size;
}
