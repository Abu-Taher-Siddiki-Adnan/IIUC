#include<bits/stdc++.h>
using namespace std;
class Stack
{
    struct Node
    {
        int data;
        Node* next;
    };
    Node* head;
    void addFirst(int item)
    {
        Node* nn = new Node;
        nn->data = item;
        nn->next = head;
        head = nn;
    }
    bool deleteFirst()
    {
        if(head == 0) return false;
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }
public:
    Stack()
    {
        head = 0;
    }
    void push(int item)
    {
        addFirst(item);
    }
    void pop()
    {
        if(!deleteFirst())
        {
            cout << "Stack Underflow" << endl;
            return;
        }
    }
    int top()
    {
        /// Check if the LL is empty
        return head->data;
    }
    bool empty()
    {
        return head == 0;
    }
};
int main()
{
    Stack s, t;
    s.push(5);
    s.push(15);
    s.push(25);

    t.push(10);
    t.push(100);
    t.push(1000);

    while(!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    while(!t.empty())
    {
        cout << t.top() << " ";
        t.pop();
    }
    cout << endl;
    return 0;
}
