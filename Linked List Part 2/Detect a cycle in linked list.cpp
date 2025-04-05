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
        ListNode* tail = nullptr;

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
        int count = 0;  // Limit to avoid infinite loop if cycle exists
        while (temp && count < 100) {
            cout << temp->val << " -> ";
            temp = temp->next;
            count++;
        }
        if (count == 100) cout << "CYCLE DETECTED (LIMIT REACHED)";
        else cout << "NULL\n";
    }
};

// === LeetCode logic integrated ===
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

// === Driver code ===
void solve() {
    LinkedList list;
    int n;
    cin >> n;

    list.createLinkedList(n);

    // Creating a cycle for testing purpose
    // Connect last node to node at pos (0-indexed), -1 means no cycle
    int pos;
    cin >> pos;

    if (pos != -1) {
        ListNode* tail = list.getHead();
        ListNode* cycleEntry = nullptr;
        int index = 0;
        while (tail->next) {
            if (index == pos) cycleEntry = tail;
            tail = tail->next;
            index++;
        }
        tail->next = cycleEntry;
    }

    Solution sol;
    bool hasCycle = sol.hasCycle(list.getHead());

    if (hasCycle)
        cout << "Cycle detected in linked list.\n";
    else {
        cout << "No cycle in linked list.\n";
        list.display();
    }
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
    cerr << "Execution Time: " << duration.count() << " ms" << endl;

    return 0;
}
