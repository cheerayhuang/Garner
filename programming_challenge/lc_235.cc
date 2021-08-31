#include <iostream>

using namespace std;


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = nullptr, left_res = nullptr, right_res = nullptr;

        if (root == p || root == q) {
            res = root;
        }

        if (root->left) {
            left_res = lowestCommonAncestor(root->left, p, q);
        }

        if (root->right) {
            right_res = lowestCommonAncestor(root->right, p, q);
        }

        if (left_res != nullptr && right_res != nullptr) {
            res = root;
        }

        if (res == nullptr) {
            res = left_res ? left_res : right_res;

        }

        return res;
    }
};

int main() {


    return 0;
}
