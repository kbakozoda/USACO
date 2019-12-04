#include<bits/stdc++.h>
#include<iostream>

using namespace std;

template<typename T>
struct StackNode {
    StackNode(const T &v): data(v), next(nullptr) {}
    StackNode(const T &v, StackNode* next): data(v), next(next) {}
    T data;
    StackNode* next;
};

template<typename T>
class Stack {
    public:
        int _size;
        Stack(): top(nullptr), _size(0) {}
        bool isEmpty() {
            return top == nullptr;
        }

        void add(const T &val) {
            StackNode<T>* newNode = new StackNode<T>(val, top);
            top = newNode;
            _size++;
        }

        T peek() const {
            if (top == nullptr) return NULL;
            return top->data;
        }

        void pop() {
            if (top == nullptr) return;
            StackNode<T>* prevTop = top;
            top = top->next;
            _size--;
            delete prevTop;
        }

        int size() {
            return _size;
        }

    StackNode<T>* top;
};

int main() {
    Stack<int>* myStack = new Stack<int>();
    myStack->isEmpty() ? cout << "Empty\n" : cout << "Has items\n";
    myStack->add(1);
    myStack->add(2);
    cout << myStack->peek() << endl;
    myStack->pop();
    cout <<"after pop: " << myStack->peek() << endl;
    myStack->add(2);
    myStack->add(3);
    cout << "size:" << myStack->size() << endl;
    return 0;
}
