#include <iostream>
using namespace std;

class Queue {
    private:
        int size, rear, front;
        int* aarray;

    public:
        // Constructor
        Queue(int s) {
            size = s;
            rear = -1;
            front = -1;
            aarray = new int[s];
        }

        // Destructor to free memory
        ~Queue() {
            delete[] aarray;
        }

        // Check if the queue is full
        bool isFull() {
            return rear == size - 1;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return front == rear;
        }

        // Enqueue an element
        void enqueue(int val) {
            if (isFull()) {
                cout << "Queue Overflow" << endl;
            } else {
                aarray[++rear] = val;
                cout << val << " enqueued" << endl;
            }
        }

        // Dequeue an element
        void dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow" << endl;
            } else {
                front++;
                cout << aarray[front] << " dequeued" << endl;
            }
        }

        // Get the front element
        int getFront() {
            if (isEmpty()) {
                cout << "Queue is Empty" << endl;
                return -1;
            } else {
                return aarray[front + 1];
            }
        }

        // Display the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is Empty" << endl;
            } else {
                cout << "Queue elements: ";
                for (int i = front + 1; i <= rear; i++) {
                    cout << aarray[i] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Queue q(4);

    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(8); // Queue becomes full
    q.enqueue(9); // Should trigger "Queue Overflow"

    q.display();

    q.dequeue();
    q.display();

    cout << "Front element: " << q.getFront() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue(); // Queue becomes empty
    q.dequeue(); // Should trigger "Queue Underflow"

    return 0;
}
