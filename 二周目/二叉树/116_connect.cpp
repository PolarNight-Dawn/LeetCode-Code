#include <iostream>
#include <queue>

//
// Created by polarnight on 23-9-27, 下午8:25.
//

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *bfs(Node *root) {
        std::queue<Node *> que;

        que.push(root);
        while (!que.empty()) {
            Node *pre;
            int len = que.size();

            for (int i = 0; i < len; i++) {
                Node *node = que.front();
                que.pop();
                if (i != 0) pre->next = node;
                if (node && node->left) que.push(node->left);
                if (node && node->right) que.push(node->right);
                pre = node;
            }
        }

        return  root;
    }

    Node* connect(Node* root) {
        return bfs(root);
    }
};

int main116() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    Node *res = sol.connect(root);

    return 0;
}