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
 if(balance > 1 && GetBalanceFactor(root->left)>=0){
    return RightRotate(root);
  }
  if(balance < -1 && GetBalanceFactor(root->right) <=0){
    return LeftRotate(root);
  }
  if(balance >1 && GetBalanceFactor(root->left)<0){
    root->left = LeftRotate(root->left);
    return RightRotate(root);
  }
  if(balance<-1 && GetBalanceFactor(root->right)>0){
    root->right = RightRotate(root->right);
    return LeftRotate(root);
  }
  return root;
}

TreeNode* GetSuccessor(TreeNode* curr){
  curr = curr->right;
  while(curr!=NULL && curr->left!=NULL){
    curr = curr->left;
  }
  return curr;
}

TreeNode* DeleteNode(TreeNode* root,int data){
  if(root == NULL){
    return root;
  }
  if(data < root->data){
    root->left = DeleteNode(root->left , data);
  }
  else if(data > root->data){
    root->right = DeleteNode(root->right , data);
  }
  else{
    if(root->left == NULL){
      TreeNode* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      TreeNode* temp = root->left;
      free(root);
      return temp;
    }
    else{
      TreeNode* succ = GetSuccessor(root);
      root->data = succ->data;
      root->right = DeleteNode(root->right , succ->data);
    }
  }
  UpdateHeight(root);
  int balance = GetBalanceFactor(root);
  if(balance > 1 && GetBalanceFactor(root->left)>=0){
    return RightRotate(root);
  }
  if(balance < -1 && GetBalanceFactor(root->right) <=0){
    return LeftRotate(root);
  }
  if(balance >1 && GetBalanceFactor(root->left)<0){
    root->left = LeftRotate(root->left);
    return RightRotate(root);
  }
  if(balance<-1 && GetBalanceFactor(root->right)>0){
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
  int arr[] = {40,20,10,25,30,22,50,60,55,70,65,80};
  int len = sizeof(arr)/4;
  for(int i=0;i<len;i++){
    root = InsertNode(root , arr[i]);
  }
  PreOrderTraversal(root);
  printf("\n");
  InOrderTraversal(root);
  return 0;
}
