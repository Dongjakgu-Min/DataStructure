#include <iostream>

using namespace std;

struct Node {
    Node* front;
    Node* back;
    int data;
};

class DoubleLinkedList {
    public:
        void push(int data);
        void pop(int index);
    private:
        Node* head;
        int length = 0;
}; 

void DoubleLinkedList::push(int data) {
    if (head == NULL) {
        this->head = new Node;
        head->data = data;
    } else {
        Node *newNode = new Node;
        Node *temp = head;

        while (temp->back != NULL) {
            temp = temp->back;
        }

        newNode->front = temp;
        newNode->data = data;

        temp->back = newNode;
    }

    this->length++;
}

void DoubleLinkedList::pop(int index) {
    if (this->length < index) {
        cout << "길이 초과" << endl;
        return;
    }

    Node *temp = head;
    Node *target;

    for (int i = 0; i < index - 2; i++) {
        temp = temp->back;
    }

    target = temp->back;

    if (temp->back->back != NULL) {
        cout << temp->back->back->data << endl;
        temp->back = temp->back->back;
        temp->back->front = temp;
    } else {
        temp->back = NULL; 
    }

    delete target;
    this->length--;
}

int main() {
    DoubleLinkedList *list = new DoubleLinkedList();

    list->push(1);
    list->push(2);
    list->push(3);
    list->push(4);

    list->pop(3);

    delete list;
}