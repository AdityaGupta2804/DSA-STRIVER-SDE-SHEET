/* 
    author: Aditya Gupta 
    created: 21.06.2025 00:55:10
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
class LFUCache {
public:
    class ListNode {
public:
    int key, value, useCounter;
    ListNode* prev;
    ListNode* next;
    ListNode(int k, int v, int uC) : key(k), value(v), useCounter(uC), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    ListNode* head;
    ListNode* tail;

    DoublyLinkedList() {
        head = new ListNode(0, 0, 0);  // dummy head
        tail = new ListNode(0, 0, 0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    void addFront(ListNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    bool empty() {
        return head->next == tail;
    }

    ListNode* removeLast() {
        if (empty()) return nullptr;
        ListNode* last = tail->prev;
        removeNode(last);
        return last;
    }

    ~DoublyLinkedList() {
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

    int capacity, minFreq;
    unordered_map<int, ListNode*> mp; // key -> node
    unordered_map<int, DoublyLinkedList*> freqMap; // freq -> DLL

    LFUCache(int capacity) {
        this->capacity = capacity;
        this->minFreq = 0;
    }

    void updateFreq(ListNode* node) {
        int oldFreq = node->useCounter;
        freqMap[oldFreq]->removeNode(node);

        if (freqMap[oldFreq]->empty()) {
            delete freqMap[oldFreq];
            freqMap.erase(oldFreq);
            if (minFreq == oldFreq) minFreq++;
        }

        node->useCounter++;
        int newFreq = node->useCounter;

        if (!freqMap.count(newFreq))
            freqMap[newFreq] = new DoublyLinkedList();

        freqMap[newFreq]->addFront(node);
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        ListNode* node = mp[key];
        updateFreq(node);
        return node->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (mp.count(key)) {
            ListNode* node = mp[key];
            node->value = value;
            updateFreq(node);
            return;
        }

        if (mp.size() >= capacity) {
            ListNode* nodeToRemove = freqMap[minFreq]->removeLast();
            mp.erase(nodeToRemove->key);
            delete nodeToRemove;
        }

        ListNode* newNode = new ListNode(key, value, 1);
        if (!freqMap.count(1))
            freqMap[1] = new DoublyLinkedList();
        freqMap[1]->addFront(newNode);
        mp[key] = newNode;
        minFreq = 1;
    }

    ~LFUCache() {
        for (auto& p : freqMap) {
            delete p.second;
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