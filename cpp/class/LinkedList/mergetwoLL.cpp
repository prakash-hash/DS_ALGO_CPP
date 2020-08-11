#include <iostream>

Node* mergeTwoLLs(Node *head1, Node *head2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    Node *fhead = NULL;
    Node *ftail = head1;
    if(head1 -> next == NULL)
    {
        head1 -> next =  head2;
        return head1;
    }
    else if(head2 -> next == NULL)
    {
        head2 -> next = head1;
        return head2;
    }
    while(ftail -> next != NULL)
    {
        if(head1 -> data < head2 -> data)
        {

            if(fhead == NULL)
            {
                fhead = head1;
                ftail = head1;
                head1 = head1 -> next;
            }
            else
            {

                ftail -> next = head1;
                ftail = ftail -> next;
                head1 = head1 -> next;
            }
        }
        else
        {
            if(fhead == NULL)
            {
                fhead = head2;
                ftail = head2;
                head2 = head2 -> next;
            }
            else
            {
                ftail -> next = head2;
                ftail = ftail -> next;
                head2 = head2 -> next;
            }
        }
    }
    if(head1 == NULL)
        ftail -> next = head2;
    else if(head2 == NULL)
        ftail -> next = head1;
    
    return fhead;
}

