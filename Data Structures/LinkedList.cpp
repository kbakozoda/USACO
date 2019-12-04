#include<bits/stdc++.h>
#include<iostream>

using namespace std;

// Singly-linked list
template<typename T>
struct ListNode {
    ListNode(const T &v) : value(v), next(nullptr) {}
    T value;
    ListNode *next;
};

void iterateVal(ListNode<int> * l) {
    while(l != nullptr) {
        cout << l->value << " ";
        l = l->next;
    }

    cout << endl;
}

void iterateAddr(ListNode<int> * l) {
    while(l != nullptr) {
        cout << l << " ";
        l = l->next;
    }

    cout << endl;
}

ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    ListNode<int> * resHead;
    ListNode<int> * resTail = new ListNode<int>(0);

    resHead = resTail;

    while ( !(l1 == nullptr && l2 == nullptr)) {
        if (l1 == nullptr) {
            resTail->next = l2;
            l2 = l2->next;
        } else if (l2 == nullptr) {
            resTail->next = l1;
            l1 = l1->next;
        } else {
            if (l1->value <= l2->value) {
                resTail->next = l1;
                l1 = l1->next;
            } else {
                resTail->next = l2;
                l2 = l2->next;
            }
        }
        resTail = resTail->next;
    }

    ListNode<int> * prev = resHead;
    resHead = resHead->next;

    delete prev;

    return resHead;
}

ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    ListNode<int>* tail = l;
    ListNode<int>* head = l;

    if (n == 0 || l == nullptr) {
        return l;
    }

    int elemCnt = 0;
    while (tail->next != nullptr) {
        elemCnt++;
        tail = tail->next;
    }
    elemCnt++;

    int replacedElems = 0;
    while (replacedElems < (elemCnt - n)) {
        tail->next = head;
        head = head->next;
        tail->next->next = nullptr;

        tail = tail->next;
        replacedElems++;
    }

    return head;
}

ListNode<int>* f(ListNode<int>* target, ListNode<int>* prev, int cnt, int groupSize) {
    if (cnt == groupSize - 1) {
        target->next = prev;
        return target;
    }
    ListNode<int>* last = f(target->next, target, cnt+1, groupSize);
    target->next = prev;

    return last;
}

ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if (l == nullptr) { return l; }
    ListNode<int>* ghead;
    ListNode<int>* gtail;
    int gcnt = 0;

    ghead = l;
    gtail = ghead;

    ListNode<int>* newStart;
    ListNode<int>* first = l;
    while (gtail != nullptr) {
        gcnt++;
        if (gcnt == k) {
            newStart = reverseNodesInKGroups(gtail->next, k);
            break;
        }

        gtail = gtail->next;
    }

    if (gcnt == k) {
        first = f(ghead, newStart, 0, k);
    } else {
        return l;
    }

    return first;
}

struct PaliRes {
    bool isPali;
    ListNode<int>* node;
    PaliRes(bool isPali, ListNode<int>* node): isPali(isPali), node(node)
    {}
};

PaliRes* palRec(ListNode<int>* l, int length) {
    if (length == 0) {
        PaliRes* res = new PaliRes(true, l);
        return res;
    } else if (length == 1) {
        PaliRes* res = new PaliRes(true, l->next);
        return res;
    } else {
        PaliRes* res = palRec(l->next, length-2);

        if (!res->isPali || res->node == nullptr) {
            return res;
        }

        if (l->value == res->node->value) {
            res->isPali = true;
            res->node = res->node->next;
            return res;
        } else {
            res->isPali = false;
            return res;
        }
    }
}

bool isListPalindrome(ListNode<int> * l) {
    int length = 0;
    ListNode<int>* slow = l;

    while (slow != nullptr) {
        length += 1;
        slow = slow->next;
    }
    PaliRes* res = palRec(l, length);
    return res->isPali;
}

int main() {
    ListNode<int>* l1 = new ListNode<int>(7);
    ListNode<int>* second = new ListNode<int>(9);
    ListNode<int>* third = new ListNode<int>(11);

    second->next = third;
    l1->next = second;
    third->next = new ListNode<int>(13);
    third->next->next = new ListNode<int>(15);

    ListNode<int>* l2 = new ListNode<int>(8);
    l2->next = new ListNode<int>(10);
    l2->next->next = new ListNode<int>(12);

    iterateVal(l1);
    iterateVal(l2);

    ListNode<int> * merged = mergeTwoLinkedLists(l1, l2);

    iterateVal(merged);

    ListNode<int>* l3 = new ListNode<int>(1);
    l3->next = new ListNode<int>(1);
    l3->next->next = new ListNode<int>(3);
    l3->next->next->next = new ListNode<int>(4);
    l3->next->next->next->next = new ListNode<int>(4);
    l3->next->next->next->next->next = new ListNode<int>(3);
    l3->next->next->next->next->next->next = new ListNode<int>(2);
    l3->next->next->next->next->next->next->next = new ListNode<int>(1);
    //l3->next->next->next->next->next->next->next->next = new ListNode<int>(1);

    //iterateVal(rearrangeLastN(l3, 4));
    //l3 = f(l3, l3->next->next->next->next, 0, 4);

    //l3 = reverseNodesInKGroups(l3, 1);
    iterateVal(l3);
    if (isListPalindrome(l3)) {
        cout << "list is a pali" << endl;
    } else {
        cout << "List is not a pali\n";
    }
    return 0;
}
