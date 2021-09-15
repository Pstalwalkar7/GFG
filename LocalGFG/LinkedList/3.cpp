class Solution
{
    public:
    //Function to rotate a linked list.
    Node* rotate(Node* head, int k)
    {
        // Your code here
        Node* copy = head;
        while(head->next){
            head = head->next;
        }
        head->next = copy;
        
        head = copy;
        while(k){
            copy = head;
            head = head->next;
            k--;
        }
        
        copy->next = NULL;
        return head;
    }
};
    