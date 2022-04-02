#include <iostream>
using namespace std;

class Heap {
   public:
    ~Heap();
    virtual void add(int item) = 0;
    virtual int remove() = 0;

   protected:
    int *array;
    int length = 0;
    void extend() {
        int *temp = new int[++this->length];
        copy(array, array + length - 1, temp);
        delete array;
        array = temp;
    };
    void shrink() {
        int *temp = new int[--this->length];
        copy(array, array + this->length, temp);
        delete array;
        array = temp;
    }
    void swap(int i, int j) {
        int temp;
        temp = this->array[i];
        this->array[i] = this->array[j];
        this->array[j] = temp;
    }
};

Heap::~Heap() { delete array; }

class MaxHeap : Heap {
   public:
    virtual void add(int item) override;
    virtual int remove() override;
};

void MaxHeap::add(int item) {
    this->extend();
    this->array[this->length - 1] = item;
    for (int i = this->length; i > 1; i /= 2) {
        if (this->array[i / 2 - 1] < this->array[i - 1]) {
            this->swap(i / 2 - 1, i - 1);
        }
    }
}

int MaxHeap::remove() {
    int result = this->array[0];
    this->array[0] = this->array[this->length - 1];
    this->shrink();

    for (int i = 1; i < (this->length + 1) / 2;) {
        if (this->array[i - 1] > this->array[i * 2 - 1] && this->array[i - 1] > this->array[i * 2])
            break;
        else if (this->array[i - 1] < this->array[i * 2 - 1]) {
            this->swap(i - 1, i * 2 - 1);
            i *= 2;
        }
        else if (this->array[i - 1] < this->array[i * 2]) {
            this->swap(i - 1, i * 2);
            i = i * 2 + 1;
        }
    }

    return result;
}

int main() {
    MaxHeap *heap = new MaxHeap();

    heap->add(1);
    heap->add(2);
    heap->add(3);
    heap->add(4);
    heap->add(5);

    cout << heap->remove() << endl;
    cout << heap->remove() << endl;
    cout << heap->remove() << endl;
    cout << heap->remove() << endl;
    cout << heap->remove() << endl;

    return 0;
}