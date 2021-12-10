#include "../node.cpp"

/*
    Algo: Take a dummy node and point to the smaller head.
    Take a single temp pointer for both the linked list.
    Take a node named current, which points to the current traversed node.
    Compare both the heads and point to the one which is smaller, move that head next and current to the head.
    Repeat the process till (both are NULL) or one of them is null.
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

Node *addSLL(Node *head1, Node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    Node *dummy = new Node(0);
    Node *current = dummy;
    int carry = 0;
    while (head1 != NULL || head2 != NULL || carry)
    {
        int sum = 0;
        if (head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if (head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        sum %= 10;
        Node *newNode = new Node(sum);
        current->next = newNode;
        current = current->next;
    }
    return dummy->next;
}

int main()
{
    Node *head1 = new Node(2);
    insertNode(&head1, 4);
    insertNode(&head1, 3);
    Node *head2 = new Node(5);
    insertNode(&head2, 6);
    insertNode(&head2, 7);
    insertNode(&head2, 9);
    Node *ans = addSLL(head1, head2);
    recursiveTraversal(ans);
    return 0;
}