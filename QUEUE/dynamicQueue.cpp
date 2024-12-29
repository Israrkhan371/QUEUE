#include <iostream>
using namespace std;

class Node {
    
        

    public:
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = NULL;
        }
};

class Queue{
    Node* front;
    Node* rear;

    public:
        Queue(){
            front = NULL;
            rear = NULL;
        };

        bool isEmpty(){
            return front == NULL;
        }

        void enqueue(int val){
            Node* newNode = new Node(val);

            if(isEmpty()){
                front = rear = newNode;
            }else{
                rear->next = newNode;
                rear = newNode;
            }
            cout << "Enqueued " << val << endl;
        }

        void deque(){
            Node* temp = front;
            int value = temp->data;
            if(front == rear){
                front = rear = NULL;
            }else{
                front = front->next;
            }
            cout << "Dequeued " << value << endl;
            delete temp;
        }

        int getFront(){
            return front->data;
        }

        void display(){
            if(isEmpty()){
                cout <<"Queue is empty" << endl;
            }else{
                Node* temp = front;
                while(temp != NULL){
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            cout << endl;
            }
        }

};

int main(){
    
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(100);
    q.display();
    q.deque();
    q.display();
    cout << "Front value = " << q.getFront();
    q.deque();
    q.display();

    q.deque();
    q.display();
    q.enqueue(45);
    q.enqueue(78);
    q.display();
    q.getFront();
    
    return 0;
}