/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > output;
        if (root == NULL)
            return output;
        queue<TreeNode*> q;
        TreeNode* temp;
        int n = 0;
        q.push(root);
        while (!q.empty()) {
            n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++) {
                temp = q.front();
                q.pop();
                v.push_back(temp -> val);
                if (temp -> left != NULL) q.push(temp -> left);
                if (temp -> right != NULL) q.push(temp -> right);
            }
            if (!v.empty()) output.push_back(v);
        }
        return output;
    }
};