/* 
    author: Aditya Gupta 
    created: 21.06.2025 00:54:44
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
class LRUCache {
public:
    class ListNode {
    public:
        int key, value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, ListNode*> mp;
    ListNode* head;
    ListNode* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new ListNode(0, 0); // dummy head
        tail = new ListNode(0, 0); // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void addToFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            ListNode* node = mp[key];
            removeNode(node);
            addToFront(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            ListNode* existingNode = mp[key];
            existingNode->value = value;
            removeNode(existingNode);
            addToFront(existingNode);
        } else {
            if (mp.size() == capacity) {
                ListNode* lru = tail->prev;
                mp.erase(lru->key);
                removeNode(lru);
                delete lru;
            }
            ListNode* newNode = new ListNode(key, value);
            addToFront(newNode);
            mp[key] = newNode;
        }
    }

    ~LRUCache() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
void solve(){
   
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