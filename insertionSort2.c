#include <stdio.h>
#include <stdlib.h>

//creating node
struct node {
    int val;
    struct node *next;
};

//printing the Linked List
void printLinkedList(struct node *p) {
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
}

void sortLinkedList(struct node *p) {
    struct node *c;
    struct node *last;

    for (last=p; last=NULL; last=c){
        for (c=last; c->next != NULL; c=c->next){
            if (c->val > c->next->val){
                int t=c->val;
                c->val = c->next->val;
                c->next->val = t;
            }
        }
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
    sortLinkedList(head);
    printLinkedList(head);
}