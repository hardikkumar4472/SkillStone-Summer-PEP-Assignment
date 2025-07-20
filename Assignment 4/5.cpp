#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct BSTInfo {
    bool isBST;
    int size;
    int min;
    int max;
    BSTInfo(bool b, int s, int mn, int mx) : isBST(b), size(s), min(mn), max(mx) {}
};

BSTInfo largestBSTHelper(TreeNode* root, int& maxSize) {
    if (!root) {
        return BSTInfo(true, 0, INT_MAX, INT_MIN);
    }
    
    BSTInfo left = largestBSTHelper(root->left, maxSize);
    BSTInfo right = largestBSTHelper(root->right, maxSize);
    
    if (left.isBST && right.isBST && root->val > left.max && root->val < right.min) {
        int size = left.size + right.size + 1;
        maxSize = max(maxSize, size);
        return BSTInfo(true, size, min(root->val, left.min), max(root->val, right.max));
    }
    
    return BSTInfo(false, 0, 0, 0);
}

int largestBSTSubtree(TreeNode* root) {
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;
}

int main() {
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(60);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(20);
    root->right->left = new TreeNode(45);
    root->right->right = new TreeNode(70);
    root->right->right->left = new TreeNode(65);
    root->right->right->right = new TreeNode(80);
    
    cout << "Size of largest BST subtree: " << largestBSTSubtree(root) << endl;
    return 0;
}