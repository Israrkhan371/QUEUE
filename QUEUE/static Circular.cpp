#include <iostream>
using namespace std;

class Circ {
private:
    int front, rear, count, size;
    int* array;

public:
    Circ(int s) {
        size = s;
        array = new int[s];
        front = rear = count = 0;
    }

    ~Circ() {
        delete[] array;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == size;
    }

    void enqueue(int val) {
        if (!isFull()) {
            array[rear] = val;
            rear = (rear + 1) % size;
            count++;
        } else {
            cout << "Overflow\n";
        }
    }

    int dequeue() {
        if (!isEmpty()) {
            int val = array[front];
            front = (front + 1) % size;
            count--;
            return val;
        } else {
            cout << "Underflow\n";
            return -1;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return array[front];
        }
    }

    void display() {
        if (!isEmpty()) {
            int f = front;
            cout << "Queue elements: ";
            for (int i = 0; i < count; i++) {
                cout << array[f] << " ";
                f = (f + 1) % size;
            }
            cout << endl;
        } else {
            cout << "Queue is empty\n";
        }
    }
};

int main() {
    Circ q(4);

    // q.enqueue(12);
    // q.enqueue(13);
    // q.enqueue(14);
    // q.display();

    // cout << q.dequeue() << "dequed " << endl;
    // q.display();

    // cout << "Front element: " << q.getFront() << endl;
q.getFront();
    return 0;
}
