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
   if (root==NULL) return 0; 
    if (!root->left && !root->right) return root->data; 
  
    // Find maximum sum in left and right subtree. Also 
    // find maximum root to leaf sums in left and right 
    // subtrees and store them in ls and rs 
    int ls = mps(root->left, res); 
    int rs = mps(root->right, res); 
  
  
    // If both left and right children exist 
    if (root->left && root->right) 
    { 
        // Update result if needed 
        res = max(res, ls + rs + root->data); 
  
        // Return maxium possible value for root being 
        // on one side 
        return max(ls, rs) + root->data; 
    } 
  
    // If any of the two children is empty, return 
    // root sum for root being on one side 
    return (!root->left)? rs + root->data: 
                          ls + root->data;
}

int mps_main(node* root){

    int res = INT_MIN;
    mps(root,res);
    return res;

}

int main(){
  struct node *root = newNode(1); 
  root->left        = newNode(-2); 
  root->right       = newNode(-3); 
  
 
  
  printf("Maximum path of the given binary tree is %d\n", mps_main(root)); 
    return 0;
}