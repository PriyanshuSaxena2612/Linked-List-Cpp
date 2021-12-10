#include "../node.cpp"

int countNodes(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }
    return 1 + countNodes(head->next);
}

Node *nthNodeFromEnd(Node *head, int n)
{
    int count = countNodes(head);
    int front = count - n;
    count = 0;
    Node *temp = head;
    while (count < front)
    {
        temp = temp->next;
        count++;
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
    cout << "\n"
         << countNodes(head) << "\n";
    Node *ans = nthNodeFromEnd(head, 6);
    cout << ans->data << "\n";
    return 0;
}