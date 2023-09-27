#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    string result {};
    string tree2str(TreeNode* t) {
        if (t == nullptr) return string {};
        result = std::to_string(t->val)
                + "("+tree2str(t->left)
                + tree2str(t->right)+")";
        return result;
    }
};

int main()
{
    Solution s;
    TreeNode t {5};
    auto answer = s.tree2str( &t);
    cout << "Hello World!" << endl;
    return 0;
}
