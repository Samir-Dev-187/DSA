#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache
{
    public:
        class Node
        {
            public:
                int key, val;
                Node* prev;
                Node* next;

                Node(int k, int v)
                {
                    key = k;
                    val = v;
                    prev = next = NULL;
                }
        };

        Node* head = new Node(-1, -1);
        Node* tail = new Node(-1, -1);

        unordered_map<int, Node*> m;
        int limit;

        void addNode(Node* newNode)
        {
            Node* oldNext = head->next;

            head->next = newNode;
            oldNext->prev = head;

            newNode->next = oldNext;
            newNode->prev = head;
        }

        void delNode(Node* oldNode)
        {
            Node* oldPrev = oldPrev->prev;
            Node* oldNext = oldNode->next;

            oldPrev->next = oldNext;
            oldNext->prev = oldPrev;
        }

        LRUCache(int capacity)
        {
            limit = capacity;
            head->next = tail;
            tail->prev = head;
        }

        int get(int key)
        {
            if(m.find(key) == m.end())
            {
                return -1;
            }

            Node* ansNode = m[key];
            int ans = ansNode->val;

            m.erase(key);
            delNode(ansNode);

            addNode(ansNode);
            m[key] = ansNode;

            return ans;
        }

        void put(int key, int val)
        {
            if(m.find(key) != m.end())
            {
                Node* oldNode = m[key];
                delNode(oldNode);
                m.erase(key);
            }

            if(m.size() == limit)
            {
                m.erase(tail->prev->key);
                delNode(tail->prev);
            }

            Node* newNode = new Node(key, val);
            addNode(newNode);
            m[key] = newNode;
        }
};

int main()
{
    LRUCache cache(2); // Capacity 2

    cache.put(1, 10); // Cache = {1=10}
    cache.put(2, 20); // Cache = {2=20, 1=10}

    cout << "Get 1: " << cache.get(1) << endl; // returns 10, Cache = {1=10, 2=20}

    cache.put(3, 30); // Removes key 2, Cache = {3=30, 1=10}

    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)

    cache.put(4, 40); // Removes key 1, Cache = {4=40, 3=30}

    cout << "Get 1: " << cache.get(1) << endl; // returns -1
    cout << "Get 3: " << cache.get(3) << endl; // returns 30
    cout << "Get 4: " << cache.get(4) << endl; // returns 40
    
    return 0;
}