/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasparent;
        int n = descriptions.size();
        for (int i = 0; i < n; i++) {
            int parentval = descriptions[i][0], childval = descriptions[i][1],
                isleft = descriptions[i][2];
            TreeNode *parentnode = nullptr, *childnode = nullptr;

            if (mp.find(parentval) == mp.end())
                parentnode = new TreeNode(parentval);
            else
                parentnode = mp[parentval];

            if (mp.find(childval) == mp.end())
                childnode = new TreeNode(childval);
            else
                childnode = mp[childval];

            if (isleft)
                parentnode->left = childnode;
            else
                parentnode->right = childnode;

            hasparent[childval] = true;
            mp[childval] = childnode;
            mp[parentval] = parentnode;
        }
        TreeNode* rootnode = nullptr;
        for (auto p : mp) {
            int nodeval = p.first;
            TreeNode* node = p.second;
            if (!hasparent[nodeval])
                rootnode = node;
        }
        return rootnode;
    }
};
