#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

unordered_map<string, int> counts;
vector<TreeNode*> result;

string serialize(TreeNode* node) {
    if (!node) return "#";
    string key = to_string(node->val) + "," + serialize(node->left) + "," + serialize(node->right);
    counts[key]++;
    if (counts[key] == 2) {
        result.push_back(node);
    }
    return key;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    counts.clear();
    result.clear();
    serialize(root);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);
    
    vector<TreeNode*> duplicates = findDuplicateSubtrees(root);
    cout << "Duplicate subtrees roots: ";
    for (TreeNode* node : duplicates) {
        cout << node->val << " ";
    }
    cout << endl;
    
    return 0;
}