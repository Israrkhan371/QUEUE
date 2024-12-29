#include <iostream>
using namespace std;

class AscendingPriorityQueue {
private:
    int* myArray; // Array to store queue elements
    int rear;     // Points to the next position for insertion
    int size;     // Maximum capacity of the queue

public:
    AscendingPriorityQueue(int s) {
        size = s;
        myArray = new int[s];
        rear = 0; // No elements initially
    }

    ~AscendingPriorityQueue() {
        delete[] myArray;
    }

    bool isEmpty() {
        return rear == 0;
    }

    bool isFull() {
        return rear == size;
    }

    void enqueue(int value) {
        if (!isFull()) {
            myArray[rear] = value;
            rear++;
            cout << "Enqueued: " << value << endl;
        } else {
            cout << "Queue Overflow" << endl;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int minIndex = 0;

        for(int i= 1; i < rear; i++){
            if(myArray[i] < myArray[minIndex]){
                minIndex = i;
            }
        }
        int minVal = myArray[minIndex];

        for (int i = minIndex; i < rear - 1; i++){
            myArray[i] = myArray[i+1];
        }

        rear--;

        return minVal;


        // Find the minimum element in the queue
        // int minIndex = 0;
        // for (int i = 1; i < rear; i++) {
        //     if (myArray[i] < myArray[minIndex]) {
        //         minIndex = i;
        //     }
        // }

        // // Save the minimum value to return
        // int minValue = myArray[minIndex];

        // // Shift elements to the left to fill the gap
        // for (int i = minIndex; i < rear - 1; i++) {
        //     myArray[i] = myArray[i + 1];
        // }

        // // Decrement the rear to reflect the removal
        // rear--;

    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i < rear; i++) {
            cout << myArray[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    AscendingPriorityQueue pq(5);

    pq.enqueue(10);
    pq.enqueue(20);
    pq.enqueue(5);
    pq.enqueue(15);

    pq.display();

    cout << "Dequeued (minimum): " << pq.dequeue() << endl;
    pq.display();

    pq.enqueue(2);
    pq.display();

    cout << "Dequeued (minimum): " << pq.dequeue() << endl;
    pq.display();

    return 0;
}
