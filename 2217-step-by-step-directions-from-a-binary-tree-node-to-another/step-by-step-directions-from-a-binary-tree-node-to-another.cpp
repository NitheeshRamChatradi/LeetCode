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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode *src,*dest;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto temp=q.front();
            q.pop();
            if(temp->val==startValue)
            src=temp;
            if(temp->val==destValue)
            dest=temp;
            if(temp->left){
            parent[temp->left]=temp;
            q.push(temp->left);
            }
            if(temp->right){
            parent[temp->right]=temp;
            q.push(temp->right);
            }
        }
        vector<int> pt(parent.size()+2,1e9);
        vector<char> dist(parent.size()+2);
        queue<pair<TreeNode*,int>> qe;
        pt[src->val]=src->val;
        qe.push({src,0});
        while(!qe.empty())
        {
            auto temp=qe.front();
            qe.pop();
            
            if(temp.first->left && pt[temp.first->left->val]==1e9){
            pt[temp.first->left->val]=temp.first->val;
            dist[temp.first->left->val]='L';
            if(temp.first->left->val==destValue)
            break;
            qe.push({temp.first->left,temp.second+1});
            }
            if(temp.first->right && pt[temp.first->right->val]==1e9){
            pt[temp.first->right->val]=temp.first->val;
            dist[temp.first->right->val]='R';
            if(temp.first->right->val==destValue)
            break;
            qe.push({temp.first->right,temp.second+1});
            }
            if(parent[temp.first] && pt[parent[temp.first]->val]==1e9){
            pt[parent[temp.first]->val]=temp.first->val;
            dist[parent[temp.first]->val]='U';
            if(parent[temp.first]->val==destValue)
            break;
            qe.push({parent[temp.first],temp.second+1});
            }
            
        }
        string s="";
            int p=destValue;
            while(p!=pt[p])
            {
                s+=dist[p];
                p=pt[p];
            }
            reverse(s.begin(),s.end());
            return s;
        

    }
};