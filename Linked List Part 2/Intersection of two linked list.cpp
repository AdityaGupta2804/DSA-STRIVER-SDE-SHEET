/* 
    author: Aditya Gupta 
    created: 05.04.2025 17:07:58
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
    /*Only for this code  of intesection of two linked list */
    void createLinkedList(int n, vector<int>& vals) {
        head = nullptr;
        ListNode* tail = nullptr;
        for (int i = 0; i < n; i++) {
            ListNode* node = new ListNode(vals[i]);
            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }
        }
    }
};
class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            ListNode* temp1 = headA;
            ListNode* temp2 = headB;
    
            while (temp1 != temp2) {
                temp1 = temp1 == nullptr ? headB : temp1->next;
                temp2 = temp2 == nullptr ? headA : temp2->next;
            }
    
            return temp1;
        }
};
    
void solve() {
    // Inputs: n1 = first list length, n2 = second list length, skipA = where A connects to intersection, skipB = where B connects
    int n1, n2, common;
    cin >> n1 >> n2 >> common;

    vector<int> A(n1), B(n2), C(common);
    for (int i = 0; i < n1; i++) cin >> A[i];
    for (int i = 0; i < n2; i++) cin >> B[i];
    for (int i = 0; i < common; i++) cin >> C[i];

    // Build List A
    LinkedList listA;
    listA.createLinkedList(n1, A);
    ListNode* headA = listA.getHead();

    // Build List B
    LinkedList listB;
    listB.createLinkedList(n2, B);
    ListNode* headB = listB.getHead();

    // Build common list
    LinkedList commonList;
    commonList.createLinkedList(common, C);
    ListNode* commonHead = commonList.getHead();

    // Attach common list
    ListNode* temp = headA;
    while (temp && temp->next) temp = temp->next;
    if (temp) temp->next = commonHead;

    temp = headB;
    while (temp && temp->next) temp = temp->next;
    if (temp) temp->next = commonHead;

    cout << "List A: ";
    listA.display();
    cout << "List B: ";
    listB.display();
    cout << "Common: ";
    commonList.display();

    Solution sol;
    ListNode* intersection = sol.getIntersectionNode(headA, headB);
    if (intersection)
        cout << "Intersection at node with value: " << intersection->val << "\n";
    else
        cout << "No intersection\n";
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