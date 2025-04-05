/* 
    author: Aditya Gupta 
    created: 05.04.2025 16:42:08
*/

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
// Template to debug 1 variable
template<typename T>
void debug1(const char* varName, T varValue) {
    cout << varName << " = " << varValue << endl;
}
// Template to debug 2 variables
template<typename T1, typename T2>
void debug2(const char* varName1, T1 varValue1, const char* varName2, T2 varValue2) {
    cout << varName1 << " = " << varValue1 << " " << varName2 << " = " << varValue2 << endl;
}
// Template to print a vector
template<typename T>
void debug_vector(const char* varName, const vector<T>& vec) {
    cout << varName << " = [";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

#define debug1(var) debug1(#var, var)
#define debug2(var1, var2) debug2(#var1, var1, #var2, var2)
#define debug_vector(vec) debug_vector(#vec, vec)

#else
#define debug1(var)
#define debug2(var1, var2)
#define debug_vector(vec)
#endif

#define int long long
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

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode* dummy = new ListNode(0);
            ListNode* cur = dummy;
    
            while (list1 && list2) {
                if (list1->val > list2->val) {
                    cur->next = list2;
                    list2 = list2->next;
                } else {
                    cur->next = list1;
                    list1 = list1->next;
                }
                cur = cur->next;
            }
    
            cur->next = list1 ? list1 : list2;
    
            ListNode* head = dummy->next;
            delete dummy;
            return head;
        }
    };
    
void solve() {
    int n1, n2;
    cin >> n1;
    LinkedList list1;
    list1.createLinkedList(n1);
    cout << "List 1: ";
    list1.display();

    cin >> n2;
    LinkedList list2;
    list2.createLinkedList(n2);
    cout << "List 2: ";
    list2.display();

    Solution sol;
    ListNode* mergedHead = sol.mergeTwoLists(list1.getHead(), list2.getHead());

    cout << "Merged List: ";
    while (mergedHead) {
        cout << mergedHead->val << " -> ";
        mergedHead = mergedHead->next;
    }
    cout << "NULL\n";
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