/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
void preorder(TreeNode* root,unordered_set<int> &s,vector<TreeNode*> &ans,TreeNode* parent)
{
    if(root==NULL)
    return;
    else
    {
        if(s.find(root->val)!=s.end())
        {
            if(root->left && s.find(root->left->val)==s.end())
            ans.push_back(root->left);
            if(root->right && s.find(root->right->val)==s.end())
            ans.push_back(root->right);
            preorder(root->left,s,ans,root);
            preorder(root->right,s,ans,root);
            if(parent!=NULL)
            {
                if(parent->left==root)
                parent->left=NULL;
                else
                parent->right=NULL;
            }
            root->left=NULL;
            root->right=NULL;
            delete root;
        }
        else
        {
            
           preorder(root->left,s,ans,root);
            preorder(root->right,s,ans,root);
        }
    }
}
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s(to_delete.begin(),to_delete.end());
        vector<TreeNode*> ans;
        if(root && s.find(root->val)==s.end())
        ans.push_back(root);
        preorder(root,s,ans,nullptr);
        return ans;
    }
};