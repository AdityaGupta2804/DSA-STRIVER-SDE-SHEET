#include <iostream>
#include <vector>
using namespace std;

// Definition for the Node with bottom pointer
struct Node {
    int data;
    Node *next;
    Node *bottom;

    Node(int x) : data(x), next(NULL), bottom(NULL) {}
};
/*Main code starts here */
class Solution {
public:
    Node* mergetwolist(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* res;
        if (l1->data < l2->data) {
            res = l1;
            res->bottom = mergetwolist(res->bottom, l2);
        } else {
            res = l2;
            res->bottom = mergetwolist(l1, res->bottom);
        }
        return res;
    }

    // Function to flatten the linked list
    Node* flatten(Node* root) {
        if (root == NULL) return root;
        Node* head2 = flatten(root->next);
        return mergetwolist(root, head2);
    }
};
/*Main code end  here */

// Utility function to create a bottom-linked list from a vector
Node* createBottomList(const vector<int>& vals) {
    Node* head = nullptr;
    Node* curr = nullptr;
    for (int val : vals) {
        if (!head) {
            head = new Node(val);
            curr = head;
        } else {
            curr->bottom = new Node(val);
            curr = curr->bottom;
        }
    }
    return head;
}

// Utility function to print the bottom-linked list
void printFlattenedList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

// Driver code
int main() {
    /*
    Linked list structure before flattening:
    5 -> 10 -> 19 -> 28
    |     |     |     |
    7     20    22    35
    |           |     |
    8           50    40
    |                 |
    30                45
    */

    Node* head = new Node(5);
    head->bottom = createBottomList({7, 8, 30});
    head->next = new Node(10);
    head->next->bottom = createBottomList({20});
    head->next->next = new Node(19);
    head->next->next->bottom = createBottomList({22, 50});
    head->next->next->next = new Node(28);
    head->next->next->next->bottom = createBottomList({35, 40, 45});

    Solution sol;
    Node* flatHead = sol.flatten(head);
    cout << "Flattened list: ";
    printFlattenedList(flatHead);

    return 0;
}
