#include <iostream>
using namespace std;

class Stack {
    public:
        void push(int item);
        int pop();
    private:
        void extend() {
            int *temp = new int[++this->length];
            copy(array, array + this->length - 1, temp);
            delete array;
 
            array = temp;
        }
        int shrink() {
            int *temp = new int[--this->length];
            copy(array, array + this->length, temp);

            int value = array[this->length];
            delete array;
            array = temp;
            
            return value;
        }
        int *array;
        int length = 0;
};

void Stack::push(int item) {
    this->extend();
    this->array[this->length - 1] = item;
}

int Stack::pop() {
    return this->shrink();
}

int main() {
    Stack *stack = new Stack();

    stack->push(1);
    stack->push(2);
    stack->push(3);

    cout << stack->pop() << endl;
    cout << stack->pop() << endl;
    cout << stack->pop() << endl;

    return 0;
}
