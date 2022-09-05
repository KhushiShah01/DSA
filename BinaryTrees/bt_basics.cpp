#include<iostream>
#include<math.h>
#include<utility>
using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// height of binary trees
int height(TreeNode* root){
    if(root == NULL) return 0;
    return max(root->left, root->right) + 1;
}


// diameter of binary trees

int diameterOfBinaryTree(TreeNode* root) { 
    pair<int, int> result = diameter(root);
    return result.first;
}

pair<int, int> diameter(TreeNode* root){
        if(root==NULL){
            return make_pair(0,0);
        }
        // first for diameter and second for height
        pair<int,int> leftd = diameter(root->left);
        pair<int,int> rightd = diameter(root->right);

        int ld = leftd.first;
        int rd = rightd.first;
        int diameter_passing_root = leftd.second + rightd.second ;
        
        pair<int,int> ans;
        ans.first = max(max(ld,rd), diameter_passing_root);
        ans.second = max(leftd.second, rightd.second) +1;
        return ans;
        
        
}