#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *parent;
    Node *left;
    Node *right;
};

class Tree {
   public:
    Tree(int data);
    void push(int data);
    void pop(int data);

   private:
    Node *head;
};

Tree::Tree(int data) {
    this->head = new Node;
    this->head->data = data;
}

void Tree::push(int data) {
    Node *current = this->head;
    Node *newNode = new Node;
    newNode->data = data;

    while (true) {
        if (current->left == NULL && current->data > data) {
            newNode->parent = current;
            current->left = newNode;
            break;
        }

        if (current->right == NULL && current->data < data) {
            newNode->parent = current;
            current->right = newNode;
            break;
        }

        if (current->left == NULL && current->right == NULL) {
            newNode->parent = current;
            if (current->data < data) current->right = newNode;
            if (current->data > data) current->left = newNode;
            break;
        }

        if (current->data > data) {
            current = current->left;
        } else if (current->data < data) {
            current = current->right;
        }
    }
}

void Tree::pop(int data) {
    Node *current = this->head;
    Node *pointer;

    // 맨 오른쪽에 있는 Node를 가져오기 위함.
    while (data != current->data) {
        if ((current->left == NULL && current->data > data) ||
            (current->right == NULL && current->data < data) ||
            (current->right == NULL && current->left == NULL &&
             current->data != data)) {
            current = NULL;
            break;
        }

        if (current->data > data)
            current = current->left;
        else
            current = current->right;
    }

    if (current == NULL) return;
    pointer = current;

    // 만약 맨 마지막에 있는 Node가 왼쪽 Node를 가지고 있다면 끌어올려 줘야 하므로 pointer 변수 생성.
    while (pointer->right == NULL && pointer->left == NULL) {
        if (pointer->right != NULL) {
            pointer = pointer->right;
        } else {
            pointer = pointer->left;
        }
    }

    while (current == pointer) {
        if (current->right != NULL) {
            current->data = current->right->data;
            current = current->right;
        } else if (current->left != NULL) {
            current->data = current->left->data;
            current = current->left;
        }
    }

    delete pointer;
}

int main() {
    Tree *tree = new Tree(5);
    tree->push(2);
    tree->push(3);
    tree->push(4);

    tree->pop(3);

    delete tree;
}