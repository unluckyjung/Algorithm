# 104. Maximum Depth of Binary Tree


## Cpp

```cpp
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
    int answer = 0;
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        dfs(root, 1);
        return answer;
    }
    
    void dfs(TreeNode* node, int curDepth){
        if(node->left == NULL && node->right == NULL) {
            answer = max(answer, curDepth);
            return;
        }
        
        if(node->left != NULL){
            dfs(node->left, curDepth + 1);
        }
        
        if(node->right != NULL){
            dfs(node->right, curDepth + 1);
        }
    }
};
```