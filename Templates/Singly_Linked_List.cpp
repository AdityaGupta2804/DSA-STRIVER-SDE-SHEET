/* 
    author: Aditya Gupta 
    created: 25.03.2025 22:27:04
*/

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

    // Getter for node value
    int getValue() {
        return val;
    }

    // Setter for node value
    void setValue(int newVal) {
        val = newVal;
    }
};

class LinkedList {
private: 
    ListNode* head;
public:
    LinkedList() { head = nullptr; }

    // Getter for head
    ListNode* getHead() {
        return head;
    }

    // Setter for head
    void setHead(ListNode* newHead) {
        head = newHead;
    }

    // Create a Linked List
    void createLinkedList(int n) {
        this->head = nullptr;  // Ensure head is reset
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

    // Insert at Head
    void insertAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at Tail
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

    // Delete Node by Value
    void deleteNode(int key) {
        if (!head) return;

        // If head holds the key
        if (head->val == key) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        ListNode* temp = head;
        while (temp->next && temp->next->val != key)
            temp = temp->next;

        if (!temp->next) return; // Key not found

        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete from Beginning
    void deleteAtBegin() {
        if (!head) return;
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from End
    void deleteAtEnd() {
        if (!head) return;

        if (!head->next) {  // If only one node
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

    // Reverse the Linked List
    void reverse() {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse link
            prev = curr;        // Move prev ahead
            curr = next;        // Move curr ahead
        }
        head = prev; // New head is the last node
    }

    // Search for a value
    bool search(int key) {
        ListNode* temp = head;
        while (temp) {
            if (temp->val == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Display the linked list
    void display() {
        ListNode* temp = head;  
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

void solve() {
    // Test cases for linked list operations
    LinkedList list;
    list.createLinkedList(5);
    list.display();
    
    cout << "Head Value: " << list.getHead()->getValue() << endl;
    list.insertAtHead(100);
    cout << "After inserting 100 at head: ";
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
