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

struct node* getTail(struct node *p) {
    struct node *curr = p;
    while (curr->next!=NULL){
        curr = curr->next;
    }
    return curr;
}

struct node* partition(struct node *head, struct node *tail) {
    struct node* curr = head->next;
    struct node* pivot = head;
    struct node* prev = head;

    while (curr != tail->next){
        if (pivot->val > curr->val){
            int t = prev->next->val;
            prev->next->val = curr->val;
            curr->val = t;
            prev=prev->next;
        }
        curr = curr->next;
    }
    int t = prev->val;
    prev->val = pivot->val;
    pivot->val = t;

    return prev;
}

void quickSort(struct node *head, struct node *tail){
    if (head == NULL || tail == NULL || head==tail){
        return;
    }
    struct node *pivot = partition(head, tail);
    quickSort(head, pivot);
    quickSort(pivot->next, tail);
}

void sortLinkedList(struct node *p){
    if (p->next == NULL){
        return;
    }
    struct node *tail = getTail(p);
    quickSort(p, tail);
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
    printf("Input:");
    printLinkedList(head);
    sortLinkedList(head);
    printf("Output:");
    printLinkedList(head);
}