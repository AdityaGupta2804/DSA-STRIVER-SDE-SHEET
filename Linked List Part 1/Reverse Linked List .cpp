#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    
    ListNode(int data) {
        val = data;
        next = nullptr;
    }

    int getValue() {
        return val;
    }

    void setValue(int newVal) {
        val = newVal;
    }
};

class LinkedList {
private: 
    ListNode* head;
public:
    LinkedList() { head = nullptr; }

    ListNode* getHead() {
        return head;
    }

    void setHead(ListNode* newHead) {
        head = newHead;
    }

    void createLinkedList(int n) {
        this->head = nullptr;
        ListNode *tail = nullptr;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ListNode* val = new ListNode(x);

            if (!head) {
                head = val;
                tail = val;
            } else {
                tail->next = val;
                tail = val;
            }
        }
    }

    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            return;
        }
        ListNode* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    void deleteNode(int key) {
        if (!head) return;

        if (head->val == key) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* temp = head;
        while (temp->next && temp->next->val != key)
            temp = temp->next;

        if (!temp->next) return;

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    void deleteAtBegin() {
        if (!head) return;
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        ListNode* temp = head;
        while (temp->next->next)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    void reverse() {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    bool search(int key) {
        ListNode* temp = head;
        while (temp) {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        ListNode* temp = head;  
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// LeetCode-style solution class
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

void solve() {
    LinkedList list;
    int n;
    cin >> n;
    list.createLinkedList(n);

    cout << "Original List: ";
    list.display();

    Solution sol;
    ListNode* reversedHead = sol.reverseList(list.getHead());

    list.setHead(reversedHead);
    cout << "Reversed List: ";
    list.display();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    auto start = chrono::high_resolution_clock::now();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cerr << "Execution Time: " << duration.count() << " ms" << std::endl;

    return 0;
}
