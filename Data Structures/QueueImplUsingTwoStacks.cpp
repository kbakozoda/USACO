#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// implementing a queue using two stacks, STL stacks used here
template<typename T>
class SpecialQueue {
    public:

        void push(vector<T> items) {
            for (T& item: items) {
                push(item);
            }
        }

        void push(T item) {
            newer.push(item);
        }

        void pop() {
            if (older.empty()) {
                transferItemsFromNewerToOlder();
            }

            if (older.empty()) {
                return;
            }

            older.pop();
        }

        T peek() {
            if (older.empty()) {
                transferItemsFromNewerToOlder();
            }

            if (older.empty()) {
                return NULL;
            }

            return older.top();
        }

        bool isEmpty() {
            return newer.empty() && older.empty();
        }

        int size() {
            return newer.size() + older.size();
        }
    private:
        stack<T> newer;
        stack<T> older;

        void transferItemsFromNewerToOlder() {
            if (newer.empty())
                return;

            while(!newer.empty()) {
                older.push(newer.top());
                newer.pop();
            }
        }
};

int main() {
    SpecialQueue<int>* myQ = new SpecialQueue<int>();

    myQ->push({1,2,3,4,5});
    cout << "inserted 5 elems, current size: " << myQ->size() << " next is: " << myQ->peek() << endl;
    myQ->pop();
    cout << "popped 1 and now next in queue is:" << myQ->peek() << endl;
    cout << "insert 6,7" << endl;
    myQ->push({6,7});
    cout << "next is: " << myQ->peek() << endl;
    cout << "pop 4 elements" << endl;

    for (int i=1; i<=4; i++)
        myQ->pop();

    cout <<"next is: " << myQ->peek() << endl;
    cout <<"insert 8,9 and then pop once" << endl;
    myQ->push({8,9});
    myQ->pop();
    cout << "next in queue is: " << myQ->peek() << endl << "now pop 3 times"<< endl;
    for (int i=1; i<=3; i++)
        myQ->pop();

    if (myQ->isEmpty())
        cout << "queue is empty" << endl;

    else
        cout << "Queue is not empty yet, next is:" << myQ->peek() << endl;

    cout << "push 1,2 into queue" << endl;
    myQ->push({1,2});

    cout << "next is: " << myQ->peek() << endl;
    cout <<"push 3" << endl;
    myQ->push(3);
    cout << "size of queue now is :" << myQ->size() << endl << "next in queue is" << myQ->peek() << endl;

    return 0;
}
