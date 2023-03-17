#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
    int is_threaded;
};

struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->is_threaded = 0;
    return newNode;
}

void insert(struct TreeNode** root, int value) {
    struct TreeNode* newNode = createNode(value);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    struct TreeNode* curr = *root;
    struct TreeNode* parent = NULL;
    while (curr != NULL) {
        parent = curr;
        if (value < curr->value) {
            if (!curr->is_threaded) {
                curr = curr->left;
            } else {
                break;
            }
        } else {
            if (!curr->is_threaded) {
                curr = curr->right;
            } else {
                break;
            }
        }
    }
    if (value < parent->value) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->left = newNode;
        parent->is_threaded = 1; // set is_threaded flag to 1
        if (newNode->left == NULL) { // set is_threaded flag of newNode
            newNode->is_threaded = 1;
        } else {
            newNode->is_threaded = 0;
        }
    } else {
        newNode->left = parent;
        newNode->right = parent->right;
        parent->right = newNode;
        parent->is_threaded = 1; // set is_threaded flag to 1
        newNode->is_threaded = 1; // set is_threaded flag of newNode
    }
}



struct TreeNode* leftMost(struct TreeNode* node) {
    if (node == NULL) {
        return NULL;
    }
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void traverse(struct TreeNode* root) {
    struct TreeNode* curr = leftMost(root);
    while (curr != NULL) {
        printf("%d ", curr->value);
        if (curr->is_threaded) {
            curr = curr->right;
        } else {
            curr = leftMost(curr->right);
        }
    }
}

int main() {
    struct TreeNode* root = NULL;
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 15);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 12);
    insert(&root, 17);
    traverse(root); // output: 3 5 7 10 12 15 17
    return 0;
}
