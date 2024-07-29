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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        maxDepth(root,ans);
        return ans;

    }
    private:
    int maxDepth (TreeNode * root , int&ans)
    {
    if(root == nullptr)
       return 0;
    const int L = maxDepth(root->left,ans);
    const int R = maxDepth(root->right,ans);
    
    ans=max(ans,L+R);
    return 1 + max(L,R);
    }
};