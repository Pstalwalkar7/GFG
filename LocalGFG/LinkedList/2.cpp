struct Node* reverseList(struct Node *head)
{
    struct Node* nxt = head->next;
    struct Node* prev = NULL;
    while(nxt){
        head->next = prev;
        prev = head;
        head = nxt;
        nxt = nxt->next;
    }
    head->next = prev;
    return head;
}