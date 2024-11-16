#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* left;
  struct node* right;
}node;

node* CreateNode(int data){
  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = data;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

node* InsertNode(node* root , int data){
  node* newnode = CreateNode(data);
  node* curr = root;
  if(root == NULL){
    root = newnode;
    return root;
  }
  else{
    while(curr!=NULL){
      if(newnode->data<curr->data){
        if(curr->left!=NULL){
          curr = curr->left;
        }
        else{
          curr->left = newnode;
          return root;
        }
      }
      else{
        if(curr->right!=NULL){
          curr = curr->right;
        }
        else{
          curr->right = newnode;
          return root;
        }
      }
    }
  }
  return root;
}

node* GetSuccessor(node* curr){
  curr = curr->right;
  while(curr!=NULL && curr->left!=NULL){
    curr = curr->left;
  }
  return curr;
}

node* DeleteNode(node* root , int val){
  if(root == NULL){
    return root;
  }
  if(val < root->data){
    root->left = DeleteNode(root->left , val);
  }
  else if(val > root->data){
    root->right = DeleteNode(root->right , val);
  }
  else{
    if(root->left == NULL){
      node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      node* temp = root->left;
      free(root);
      return temp;
    }
    else{
      node* succ = GetSuccessor(root);
      root->data = succ->data;
      root->right = DeleteNode(root->right, succ->data);
    }
  }
  return root;
}

int Search(node* root , int value){
  int count = 0;
  node* curr = root;
  if(root == NULL){
    return -1;
  }
  while(curr != NULL){
    count++;
    if(curr->data == value){
      printf("No of lookups: %d",count);
      return 1;
    }
    else if(value > curr->data){
      if(curr->right!=NULL){
        curr = curr->right;
      }
      else{
        printf("No of lookups: %d",count);
        return -1;
      }
    }
    else if(value < curr->data){
      if(curr->left!=NULL){
      curr = curr->left;
      }else{
        printf("No of lookups: %d",count);
        return -1;
      }
    }
  }
  printf("No of lookups: %d",count);
  return -1;
}

void InOrderTraversal(node* root){
  // left - root - right
  if(root == NULL){
    return;
  }
  InOrderTraversal(root->left);
  printf("%d ",root->data);
  InOrderTraversal(root->right);
}

void PreOrderTraversal(node* root){
  // root - left - right
  if(root == NULL){
    return;
  }
  printf("%d ",root->data);
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}

void PostOrderTraversal(node* root){
  //left - right - root
  if(root == NULL){
    return;
  }
  PostOrderTraversal(root->left);
  PostOrderTraversal(root->right);
  printf("%d ",root->data);
}

void TransfromToGST(node* root , int* sum){
  if(root == NULL){
    return;
  }
  TransfromToGST(root->right , sum);
  *sum +=root->data;
  root->data = *sum;
  TransfromToGST(root->left,sum);
}

void ReverseInOrderTraversal(node* root){
  if(root == NULL){
    return;
  }
  ReverseInOrderTraversal(root->right);
  printf("%d ",root->data);
  ReverseInOrderTraversal(root->left);
}

