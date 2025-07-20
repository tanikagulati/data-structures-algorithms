#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lru-cache/description/

class Node
{
public:
    int key;
    int val;
    Node *prev;
    Node *next;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
};

void deleteNode(Node *temp)
{
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    // TC: O(1)
}

void insertAtFront(Node *dummyHead, Node *temp)
{
    temp->next = dummyHead->next;
    dummyHead->next = temp;
    temp->next->prev = temp;
    temp->prev = dummyHead;
    // TC: O(1)
}

class LRUCache
{
    unordered_map<int, Node *> mp;
    Node *dummyHead = new Node(-1, -1);
    Node *dummyTail = new Node(-1, -1);
    int capacity;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        dummyHead->next = dummyTail;
        dummyTail->prev = dummyHead;
    }

    int get(int key)
    {
        auto it = mp.find(key);
        if (it == mp.end())
            return -1;
        deleteNode(it->second);
        insertAtFront(dummyHead, it->second);
        return it->second->val;
        // TC: O(1)
    }

    void put(int key, int val)
    {
        Node *temp;
        if (mp.find(key) != mp.end())
        {
            temp = mp[key];
            temp->val = val;
            deleteNode(temp);
            insertAtFront(dummyHead, temp);
        }
        else
        {
            if (mp.size() == capacity)
            {
                // delete LRU
                mp.erase(mp.find(dummyTail->prev->key));
                Node *toBeDeleted = dummyTail->prev;
                deleteNode(toBeDeleted);
                delete toBeDeleted;
            }
            temp = new Node(key, val);
            insertAtFront(dummyHead, temp);
            mp[key] = temp;
        }
        // TC: O(1)
    }
};

int main()
{
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 10);
    cache->put(2, 20);
    cout << cache->get(1) << endl;
    cache->put(3, 30);
    cout << cache->get(2) << endl;
    cache->put(4, 40);
    cout << cache->get(1) << endl;
    cout << cache->get(3) << endl;
    cout << cache->get(4) << endl;
}