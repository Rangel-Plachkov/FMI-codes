// /https://intranet.fmi.uni-sofia.bg/index.php/s/o1mQN0S3lmXkfEJ
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Node {
    char text;
    Node* left;
    Node* right;
    
    Node() : text(0), left(nullptr), right(nullptr) {}
    Node(char newText) : text(newText), left(nullptr), right(nullptr) {}
};

size_t getTreeLevel(const Node* treePtr) {
    if (treePtr == nullptr) {
        return 0;
    }
    size_t leftHeight = getTreeLevel(treePtr->left);
    size_t rightHeight = getTreeLevel(treePtr->right);
    return 1 + std::max(leftHeight, rightHeight);
}

void treeRec(const Node* treePtr, size_t level, std::vector<std::string>& resultTable, size_t maxDepth) {
    if (level >= maxDepth) return;

    if (treePtr == nullptr) {
        resultTable[level] += '.';
        treeRec(nullptr, level + 1, resultTable, maxDepth);
        treeRec(nullptr, level + 1, resultTable, maxDepth);
    } else {
        resultTable[level] += treePtr->text;
        treeRec(treePtr->left, level + 1, resultTable, maxDepth);
        treeRec(treePtr->right, level + 1, resultTable, maxDepth);
    }
}

std::vector<std::string> getText(const Node* treePtr) {
    size_t maxDepth = getTreeLevel(treePtr);
    std::vector<std::string> result(maxDepth);
    treeRec(treePtr, 0, result, maxDepth);
    return result;
}

int main() {    
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('F');
    root->left->right->left = new Node('G');
    root->left->right->right = new Node('H');
    root->left->right->right->right = new Node('I');

    size_t height = getTreeLevel(root);
    std::cout << "Tree height: " << height << std::endl;

    std::vector<std::string> levels = getText(root);
    std::cout << "Tree nodes by level (using '.' for empty):" << std::endl;
    for (size_t i = 0; i < levels.size(); ++i) {
        std::cout << "Level " << i << ": " << levels[i] << std::endl;
    }

    delete root->left->right->right->right;  // I
    delete root->left->right->left;           // G
    delete root->left->right->right;          // H
    delete root->left->right;                  // E
    delete root->left->left;                   // D
    delete root->right->right;                 // F
    delete root->left;                         // B
    delete root->right;                        // C
    delete root;                              // A

    return 0;
}
