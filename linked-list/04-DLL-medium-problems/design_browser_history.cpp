#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string url;
    Node *next;
    Node *prev;

    Node(string url1)
    {
        url = url1;
        next = NULL;
        prev = NULL;
    }
};

class Browser
{
public:
    Node *current;
    Browser(string homepage)
    {
        current = new Node(homepage);
        // TC: O(1)
    }

    string visit(string url)
    {
        Node *newTab = new Node(url);
        current->next = newTab;
        newTab->prev = current;
        current = newTab;
        return current->url;
        // TC: O(1)
    }

    string back(int steps)
    {
        while (steps && current->prev)
        {
            current = current->prev;
            steps--;
        }
        return current->url;
        // TC: O(steps)
    }

    string forward(int steps)
    {
        while (steps && current->next)
        {
            current = current->next;
            steps--;
        }
        return current->url;
        // TC: O(steps)
    }
};

int main()
{
    Browser *obj = new Browser("google.com");
    cout << obj->current->url << endl;

    obj->visit("leetcode.com");
    cout << obj->current->url << endl;

    obj->visit("gfg.org");
    cout << obj->current->url << endl;

    obj->back(2);
    cout << obj->current->url << endl;

    obj->forward(3);
    cout << obj->current->url << endl;
}