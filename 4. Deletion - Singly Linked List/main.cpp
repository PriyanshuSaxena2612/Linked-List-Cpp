#include "../node.cpp"

void deleteNode(Node *head, int pos)
{
    if (head == NULL)
    {
        return;
    }
    // deleting the head
    if (pos == 1)
    {
        Node *temp = head;
        head = temp->next;
        delete (temp);
        return;
    }
    Node *temp = head;
    int count = 0;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;
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
    // deleteNode(head, 5);
    recursiveTraversal(head);
    return 0;
}