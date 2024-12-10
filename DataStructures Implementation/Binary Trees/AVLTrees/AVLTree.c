#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
  int data;
  int height;
  struct TreeNode* left;
  struct TreeNode* right;
}TreeNode;

int GetHeight(TreeNode* node){
  if(node == NULL) return 0;
  return node->height;
}

int GetBalanceFactor(TreeNode* node){
  if(node == NULL) return 0;
  return GetHeight(node->left) - GetHeight(node->right);
}

void UpdateHeight(TreeNode* node){
  int left_height = GetHeight(node->left);
  int right_height = GetHeight(node->right);
  node->height = (left_height>right_height?left_height:right_height) +1;
}

TreeNode* RightRotate(TreeNode* y){
  TreeNode* x = y->left;
  TreeNode* T2 = x->right;
  x->right = y;
  y->left = T2;
  UpdateHeight(y);
  UpdateHeight(x);
  return x;
}

TreeNode* LeftRotate(TreeNode* y){
  TreeNode* x = y->right;
  TreeNode* T2 = x->left;
  x->left = y;
  y->right = T2;
  UpdateHeight(y);
  UpdateHeight(x);
  return x;
}

TreeNode* Createnode(int data){
  TreeNode* newnode = (TreeNode*)malloc(sizeof(TreeNode));
  newnode->data = data;
  newnode->height = 1;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

TreeNode* InsertNode(TreeNode* root , int data){
  if(root == NULL){
    return Createnode(data);
  }
  if(data < root->data){
    root->left = InsertNode(root->left , data);
  }
  else if(data > root->data){
    root->right = InsertNode(root->right , data);
  }
  else{
    return root;
  }
  UpdateHeight(root);
  int balance = GetBalanceFactor(root);
  if(balance>1 && data < root->left->data){
    return RightRotate(root);
  }
  if(balance<-1 && data > root->right->data){
    return LeftRotate(root);
  }
  if(balance>1 && data>root->left->data){
    root->left = LeftRotate(root->left);
    return RightRotate(root);
  }
  if(balance<-1 && data < root->right->data){
    root->right = RightRotate(root->right);
    return LeftRotate(root);
  }
  return root;
}

void PreOrderTraversal(TreeNode* root){
  if(root == NULL){
    return;
  }
  printf("%d ",root->data);
  PreOrderTraversal(root->left);
  PreOrderTraversal(root->right);
}

void InOrderTraversal(TreeNode* root){
  if(root == NULL){
    return;
  }
  InOrderTraversal(root->left);
  printf("%d ",root->data);
  InOrderTraversal(root->right);
}

int main() {
    TreeNode* root = NULL;
    root = InsertNode(root , 10);
    root = InsertNode(root , 20);
    root = InsertNode(root , 30);
    root = InsertNode(root , 40);
    root = InsertNode(root , 0);
    root = InsertNode(root , 5);
    root = InsertNode(root , 12);
    root = InsertNode(root , 3);
    root = InsertNode(root , 5);
    root = InsertNode(root , 60);

    PreOrderTraversal(root);
    printf("\n");
    InOrderTraversal(root);
    return 0;
}
