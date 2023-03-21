#include <new>
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};


class Queue {
private:
    Node *front;
    Node *rear;
    int count;
public:

    Queue() {
        front = NULL;
        rear = NULL;
        count = 0;
    }


    void enqueue(int data) {
        Node *temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if (front == NULL) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        count++;
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        front = front->next;
        delete temp;
        count--;
    }


    int top() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }


    bool isEmpty() {
        return (front == NULL);
    }


    int size() {
        return count;
    }
};


int main() {
    Queue q;
    q.enqueue(15);
    q.enqueue(25);
    q.enqueue(35);
    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;
    q.dequeue();
    cout << "Top element: " << q.top() << endl;
    cout << "Size: " << q.size() << endl;
    q.dequeue();
    q.dequeue();
    cout << "Is Queue empty? 1 means yes,0 means no : " << q.isEmpty() << endl;
    cout << "Size: " << q.size() << endl;
    return 0;
}
