#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, vector<int>& nodes) {
    if (!root) return;
    inorderTraversal(root->left, nodes);
    nodes.push_back(root->val);
    inorderTraversal(root->right, nodes);
}

TreeNode* buildBalancedBST(vector<int>& nodes, int start, int end) {
    if (start > end) return nullptr;
    
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);
    
    return root;
}

TreeNode* balanceBST(TreeNode* root) {
    vector<int> nodes;
    inorderTraversal(root, nodes);
    return buildBalancedBST(nodes, 0, nodes.size() - 1);
}

void printInorder(TreeNode* node) {
    if (!node) return;
    printInorder(node->left);
    cout << node->val << " ";
    printInorder(node->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->left->left = new TreeNode(1);
    
    cout << "Original BST (inorder): ";
    printInorder(root);
    cout << endl;
    
    TreeNode* balanced = balanceBST(root);
    cout << "Balanced BST (inorder): ";
    printInorder(balanced);
    cout << endl;
    
    return 0;
}