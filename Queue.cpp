#include <iostream>
using namespace std;

class Queue {
    public:
        void enqueue(int item);
        int dequeue();
    private:
        int size = 0;
        int *array;
};

void Queue::enqueue(int item) {
    int *temp = new int[++size];
    copy(array, array + this->size - 1, temp);
    temp[size - 1] = item;
    
    delete array;
    array = temp;
}

int Queue::dequeue() {
    int *temp = new int[--size];
    int result;

    copy(array + 1, array + this->size + 1, temp);
    result = array[0];

    delete array;
    array = temp;
    return result;
}

int main() {
    Queue *queue = new Queue();

    queue->enqueue(1);
    queue->enqueue(2);
    queue->enqueue(3);

    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;
    cout << queue->dequeue() << endl;

    return 0;
}