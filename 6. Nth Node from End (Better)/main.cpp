#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

/*
    Algo -> take two pointers at head, named temp and movingPointer
    move the movingPointer n times (nth node from end)
    now move both temp and movingPointer till the movingPointer gets to the null node
    now the temp node will be pointing to the nth node from the end
*/

Node *nthNodeFromEnd(Node *head, int n)
{
    Node *temp = head;
    Node *movingPointer = head;
    while (n--)
    {
        movingPointer = movingPointer->next;
    }
    while (movingPointer != NULL)
    {
        movingPointer = movingPointer->next;
        temp = temp->next;
    }
    return temp;
}

void insertNode(Node **head, int data)
{
    Node *newNode = new Node(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void recursiveTraversal(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    cout << temp->data << "->";
    recursiveTraversal(temp->next);
}

int main()
{
    Node *head = new Node(1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    recursiveTraversal(head);
    Node *ans = nthNodeFromEnd(head, 6);
    cout << "\n"
         << ans->data << endl;
    return 0;
}