#include<stdio.h>
#include<stdlib.h>
#include"BST.c"

int main(){
  int arr[] = {6,4,8,5,0,9,7,1,3,4};
  int len = sizeof(arr)/4;
  node* root = NULL;
  for(int i=0;i<len;i++){
    root = InsertNode(root,arr[i]);
  }
  printf("\nInorder Traversal:\n");
  InOrderTraversal(root);
  return 0;
}