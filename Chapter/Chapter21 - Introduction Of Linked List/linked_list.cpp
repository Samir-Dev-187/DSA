#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(int val)
        {
            data = val;
            next = NULL;
        }
};

class List
{
    Node* head;
    Node* tail;

    public:
        List()
        {
            head = tail = NULL;
        }

        void push_front(int val) //add node in front
        {
            Node* newNode = new Node(val);
            if(head == NULL)
            {
                head = tail = newNode;
                return;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
        }

        void push_back(int val) //add node in back
        {
            Node* newNode = new Node(val);

            if(head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        }

        void pop_front() //delete front node
        {
            if(head == NULL)
            {
                cout << "Linked List Is Empty...";
                return;
            }
            Node* temp = head;
            head = head->next;
            temp->next = NULL;
            delete temp;
        }

        void pop_back() //delete back node
        {
            if(head == NULL)
            {
                cout << "Linked List Is Empty..";
                return;
            }
            Node* temp = head;
            while(temp->next != tail)
            {
                temp = temp->next;
            }
            temp->next = NULL;
            delete tail;
            tail = temp;
        }

        void insert(int val, int pos) // insert in middle of a linked list
        {
            if(pos<0)
            {
                cout << "Invalid Position..";
                return;
            }
            if(pos==0)
            {
                push_front(val);
                return;
            }
            Node* temp = head;
            for(int i=0; i<pos-1; i++)
            {
                if(temp == NULL)
                {
                    cout << "Invalid Position..";
                }
                temp = temp->next;
            }
            Node* newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }

        void printLL() //print node
        {
            Node* temp = head;
            while(temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp ->next;
            }
            cout << "NULL" << endl;
        }

        int search(int key)
        {
            Node* temp = head;
            int idx = 0;

            while(temp != NULL)
            {
                if(temp->data == key)
                {
                    return idx;
                }
                temp = temp->next;
                idx++;
            }
            return -1;
        }
};

int main()
{
    List l1;
    // l1.push_front(1);
    // l1.push_front(2);
    // l1.push_front(3);
    // l1.push_back(4);

    // // l1.pop_front();
    // l1.pop_back();
    
    l1.push_front(3);
    l1.push_front(2);
    l1.push_front(1);

    l1.insert(4,1);

    l1.printLL();
    cout << endl;

    cout << l1.search(4) << endl;

    return 0;
}