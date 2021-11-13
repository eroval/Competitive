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
    void currentSum(TreeNode* root, int targetSum, int& finalSteps, bool used){
        if(root!=nullptr){
            if(targetSum-root->val==0){
                ++finalSteps;
            }
            currentSum(root->left, targetSum-root->val, finalSteps, true);
            currentSum(root->right, targetSum-root->val, finalSteps, true);

            if(!used){
                currentSum(root->left, targetSum, finalSteps, false);
                currentSum(root->right,targetSum, finalSteps,  false);
            }
        }
    }
        
    int pathSum(TreeNode* root, int targetSum) {
        int finalSteps=0;
        currentSum(root,targetSum, finalSteps, false);
        return finalSteps;
    } 
};