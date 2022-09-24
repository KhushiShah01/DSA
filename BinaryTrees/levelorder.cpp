#include<iostream>
#include<math.h>
#include<utility>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Method 1
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL){
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    vector<int> level;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        
        if(temp!=NULL){
            level.push_back(temp->val);
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else{ 
            ans.push_back(level);
            level.clear();
            if(!q.empty()){
                q.push(NULL);
            }
      
        }
    }
    return ans;
}

// Method 2
vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL){
        return {};
    }
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int s = q.size();
        vector<int> level(s);
        for(int i=0;i<s;i++){
            TreeNode* temp = q.front();
            q.pop();
            level[i] = temp->val;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
       ans.push_back(level);
    }
    return ans;
}