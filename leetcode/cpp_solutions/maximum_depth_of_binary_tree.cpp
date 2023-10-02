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
    int maxDepth(TreeNode* root) {
        TreeNode* temp = root;
        if (temp == nullptr) return 0;
        else{
            int lDepth = maxDepth(temp->left);
            int rDepth = maxDepth(temp->right);

            if (lDepth > rDepth) return (lDepth + 1);
            else return (rDepth + 1);
        }
        
    }
};
