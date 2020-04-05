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



int mps(node* root,int &res){
    if(root == nullptr){
        return 0;
    }

    int l = mps(root->left,res);
    int r = mps(root->right,res);

    int temp = max(max(l,r)+root->data,root->data);
    int ans = max(temp,root->data+l+r);
    res = max(res,ans);
return temp;
}

int mps_main(node* root){

    int res = INT_MIN;
    mps(root,res);
    return res;

}

int main(){
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  
 
  
  printf("Maximum path of the given binary tree is %d\n", mps_main(root)); 
    return 0;
}