#define pp pair<int,int>
#define depth first
#define parent second

pp info[102];

class Solution {
public:
    
    void dfs(TreeNode* node, int cur_depth, int cur_parent){
        if(node == NULL) return;
        
        info[node->val] = {cur_depth, cur_parent};
        dfs(node->left, cur_depth + 1, node->val);
        dfs(node->right, cur_depth + 1, node->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, -1);
        if(info[x].depth != info[y].depth) return false;
        if(info[x].parent == info[y].parent) return false;
        return true;
    }
};