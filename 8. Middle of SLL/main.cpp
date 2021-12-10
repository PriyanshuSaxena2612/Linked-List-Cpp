#include "../node.cpp"

/*
    Algo: Take two pointers slow and fast, move 
    slow by one step and fast by two steps
    when fast->next = NULL or fast = NULL
    slow would be pointing to the middle of the SLL.
*/

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

void middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << slow->data;
}

int main()
{
    Node *head = new Node(1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);
    insertNode(&head, 6);
    // insertNode(&head, 6);
    recursiveTraversal(head);
    cout << "\n";
    middleNode(head);
    return 0;
}