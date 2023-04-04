#include <iostream>
using namespace std;

#define SIZE 5 // maximum size of the circular queue

class CircularQueue {
private:
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }


    void insert(int element) {
        if ((front == 0 && rear == SIZE - 1) || front == rear + 1 ) {
            cout << "Circular Queue is full\n";
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear = (rear + 1) % SIZE;
            items[rear] = element;
        }
    }

    void remove() {
        if (front == -1) {
            cout << "Circular Queue is empty\n";
        }
        else {
            cout << "Deleted " << items[front] << endl;
            if (front == rear) {
                front = -1;
                rear = -1;
            }
            else {
                front = (front + 1) % SIZE;
            }
        }
    }

    void display() {
        if (front == -1) {
            cout << "Circular Queue is empty\n";
        }
        else {
            cout << "Circular Queue elements are: ";
            int i;
            for (i = front; i != rear; i = (i + 1) % SIZE) {
                cout << items[i] << " ";
            }
            cout << items[i] << endl;
        }
    }
};

int main() {
    CircularQueue cq;

    cq.insert(1);
    cq.insert(2);
    cq.insert(3);
    cq.insert(4);
    cq.insert(5);

    cq.display();

    cq.remove();
    cq.remove();

    cq.display();

    cq.insert(6);
    cq.insert(7);

    cq.display();

    return 0;
}
