#include<bits/stdc++.h>
using namespace std;

struct node 
{ 
    int data; 
    struct node* left, *right; 
};
struct node* newNode(int data) 
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
  
  return(node); 
}



int diameter(node* root,int& res){
    if(root == nullptr){
        return 0;
    }

    int l = diameter(root->left,res);
    int r = diameter(root->right,res);

    int temp = 1+max(l,r);
    int ans = max(temp,1+l+r);
    res = max(res,ans);
return temp;
}

int diameter_utill(node* root){
    int res = INT_MIN;
    diameter(root,res);
    return res;
}

int main(){
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5); 
  
  printf("Diameter of the given binary tree is %d\n", diameter_utill(root)); 
    return 0;
}