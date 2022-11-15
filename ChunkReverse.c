#include <stdio.h>
#include <stdlib.h>

//creating node
struct node {
    int val;
    struct node *next;
};

//reverse structure
struct node *chunkReverse(struct node *head, int k)
{
    if (!head)
        return NULL;
   
    struct node* curr = head;
    struct node* next = NULL;
    struct node* prev = NULL;
    int count = 0;
     
    /*reversing first k nodes of the linked list */
    while (curr != NULL && count < k)
    {
        next  = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
     
    /* next is now a pointer to (k+1)th node
       Recursively call for the list starting from current.*/
    if (next !=  NULL)
       head->next = chunkReverse(next, k);
    
    /* prev is new head */
    return prev;
}

//printing the Linked List
void printLinkedList(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
}

int main(){

    //intialize nodes
    struct node *prev, *head, *p;
    head = NULL;

    //taking number of elements in array
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++){

        //allocating memory
        p = malloc(sizeof(struct node));

        //taking each element in array
        scanf("%d", &p->val);

        //allotting address to the next pointer
        p->next = NULL;
        if(head==NULL){
            head = p;
        } else {
            prev->next = p;
        }
        prev = p;
    }
    printLinkedList(head);
    
    int k;
    printf("Enter chunk size from 1 to n: ");
    scanf("%d", &k);
    head = chunkReverse(head, k);
    printLinkedList(head);
    return 0;
}