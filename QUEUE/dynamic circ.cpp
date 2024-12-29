#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class DynamicCircularQueue {
private:
    Node* front;
    Node* rear;

public:
    DynamicCircularQueue() : front(nullptr), rear(nullptr) {}

    ~DynamicCircularQueue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front; // Point rear to front to complete the circle
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front; // Maintain circular linkage
        }
        cout << "Enqueued: " << value << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int value = front->data;

        if (front == rear) {
            // Single element in the queue
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            front = front->next;
            rear->next = front; // Maintain circular linkage
            delete temp;
        }
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        Node* temp = front;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    DynamicCircularQueue dq;

    dq.enqueue(10);
    dq.enqueue(20);
    dq.enqueue(30);
    dq.display();

    cout << "Dequeued: " << dq.dequeue() << endl;
    dq.display();

    cout << "Front element: " << dq.getFront() << endl;

    dq.enqueue(40);
    dq.enqueue(50);
    dq.display();

    return 0;
}
