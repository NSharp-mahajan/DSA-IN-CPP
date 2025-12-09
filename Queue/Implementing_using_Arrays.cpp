#include<iostream>
#define MAX 10
#include<queue>
using namespace std;

class LinearQueue{
    int front, rear, size;
    int* arr;
public:
    LinearQueue(){
        arr = new int[MAX];
        front = 0;
        rear = -1;
        size = 0;
    }
    bool isEmpty(){
        return size == 0;
    }
    bool isFull(){
        return size == MAX;
    }

    void enqueue(int item){
        if(isFull()){
            cout << "Queue is Full!" << item << endl;
            return;
        }
        rear++;
        arr[rear] = item;
        size++;
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return -1;
        }
        int removed = arr[front];
        cout << "Removed: " << removed << endl;
        front++;
        size--;
        return removed;
    }

    int peekFront(){
        if(isEmpty())return -1;
        return arr[front];
    }
    int peekRear(){
        if(isEmpty()) return -1;
        return arr[rear];
    }
    int getSize(){
        return size;
    }

    void display(){
        if(isEmpty()){
            cout << "Queue is empty: " << endl;
            return;
        }
        cout << "Queue: ";
        for(int i = front; i <= rear; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    LinearQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "size: " << q.getSize() << endl;
    cout << "Front: " << q.peekFront() << endl;
    cout << "rear: " << q.peekRear() << endl;

    q.dequeue();
    q.dequeue();

    cout << "size: " << q.getSize() << endl;
    cout << "Front: " << q.peekFront() << endl;
    cout << "rear: " << q.peekRear() << endl;

    q.display();

    return 0;
}