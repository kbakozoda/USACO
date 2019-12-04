#include<bits/stdc++.h>
#include<iostream>

using namespace std;

template<typename T>
struct QueueNode {
    QueueNode(const T &v): data(v), next(nullptr) {}
    QueueNode(const T &v, QueueNode* next): data(v), next(next) {}
    T data;
    QueueNode* next;
};

template<typename T>
class Queue {
    public:
        Queue(): first(nullptr), last(nullptr) {}
        bool isEmpty() {
            return last == nullptr;
        }

        void push(const T &val) {
            QueueNode<T>* newNode = new QueueNode<T>(val);
            if (last != nullptr) {
                last->next = newNode;
            }

            last = newNode;

            if (first == nullptr) {
                first = last;
            }
        }

        T next() const {
            if (first == nullptr) return NULL; // or throw any exception

            return first->data;
        }

        void pop() {
            if (first == nullptr) return;
            QueueNode<T>* prevFirst = first;
            first = first->next;
            if (first == nullptr) last = nullptr;
            delete prevFirst;
        }

    QueueNode<T>* first;
    QueueNode<T>* last;
};

int main() {
    Queue<int>* myQueue = new Queue<int>();
    myQueue->push(1);
    myQueue->push(2);
    cout << "Next elem is: " << myQueue->next() << endl;
    myQueue->pop();
    cout << "Next elem is: " << myQueue->next() << endl;
    myQueue->isEmpty() ? cout << "Q is empty\n" : cout << "Q still has items\n";
    myQueue->pop();
    myQueue->isEmpty() ? cout << "Q is empty\n" : cout << "Q still has items\n";
    return 0;
}
