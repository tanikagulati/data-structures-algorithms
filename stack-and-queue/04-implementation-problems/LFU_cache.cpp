#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lfu-cache/description/

class Node
{
public:
    int key;
    int val;
    int cnt = 1;
    Node *prev;
    Node *next;

    Node(int key, int val)
    {
        this->key = key;
        this->val = val;
        prev = next = NULL;
    }
};

class List
{
public:
    Node *dHead = new Node(-1, -1);
    Node *dTail = new Node(-1, -1);
    int size = 0;

    List()
    {
        dHead->next = dTail;
        dTail->prev = dHead;
    }

    void deleteNode(Node *temp)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        size--;
        // TC: O(1)
    }

    void insertAtFront(Node *temp)
    {
        temp->next = dHead->next;
        dHead->next = temp;
        temp->next->prev = temp;
        temp->prev = dHead;
        size++;
        // TC: O(1)
    }
};

class LFUCache
{
    int capacity;
    unordered_map<int, Node *> keyNodeMap;
    unordered_map<int, List *> freqListMap;
    int minFreq;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    void updateFreqListMap(Node *node)
    {
        freqListMap[node->cnt]->deleteNode(node);

        if (node->cnt == minFreq && freqListMap[minFreq]->size == 0)
            minFreq++;

        node->cnt++;
        if (freqListMap.find(node->cnt) == freqListMap.end())
            freqListMap[node->cnt] = new List();
        freqListMap[node->cnt]->insertAtFront(node);
    }

    int get(int key)
    {
        auto it = keyNodeMap.find(key);
        if (it == keyNodeMap.end())
            return -1;
        else
            updateFreqListMap(it->second);
        return it->second->val;
        // TC: O(1)
    }

    void put(int key, int val)
    {
        auto it = keyNodeMap.find(key);
        if (it != keyNodeMap.end())
        {
            it->second->val = val;
            updateFreqListMap(it->second);
        }
        else
        {
            if (keyNodeMap.size() == capacity)
            {
                Node *toBeDeleted = freqListMap[minFreq]->dTail->prev;
                keyNodeMap.erase(toBeDeleted->key);
                freqListMap[minFreq]->deleteNode(toBeDeleted);
                delete toBeDeleted;
                if (freqListMap[minFreq]->size == 0)
                    minFreq++;
            }
            Node *newNode = new Node(key, val);
            keyNodeMap.insert({key, newNode});
            if (freqListMap.find(1) == freqListMap.end())
                freqListMap[1] = new List();
            freqListMap[1]->insertAtFront(newNode);
            minFreq = 1;
        }
        // TC: O(1)
    }
};

int main()
{
    LFUCache *cache = new LFUCache(2);
    cache->put(1, 10);
    cache->put(2, 20);
    cout << cache->get(1) << endl;
    cache->put(3, 30);
    cout << cache->get(2) << endl;
}