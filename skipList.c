#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
 
int max_level = 2;
 
typedef struct node {
    int key;
    int value;
    struct node **forward;
} node;
 
typedef struct skiplist {
    int level;
    int size;
    struct node *header;
} skiplist;
 
skiplist *createSkiplist(skiplist *list) {
    int i;
    node *header = (node *) malloc(sizeof(struct node));
    list->header = header;
    header->key = INT_MAX;
    header->forward = (node **) malloc(
            sizeof(node*) * (max_level + 1));
    for (i = 0; i <= max_level; i++) {
        header->forward[i] = list->header;
    }
 
    list->level = 1;
    list->size = 0;
 
    return list;
}
 
int skiplist_insert(skiplist *list, int key, int value) {
    node *update[max_level + 1];
    node *x = list->header;
    int i, level;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
        update[i] = x;
    }
    x = x->forward[1];
 
    if (key == x->key) {
        x->value = value;
        return 0;
    } else {
        int level = 1;
        while (rand() < RAND_MAX / 2 && level < max_level) {
            level++;
        }

        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->header;
            }
            list->level = level;
        }
 
        x = (node *) malloc(sizeof(node));
        x->key = key;
        x->value = value;
        x->forward = (node **) malloc(sizeof(node*) * (level + 1));
        for (i = 1; i <= level; i++) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
    return 0;
}
 
node *skiplist_search(skiplist *list, int key) {
    node *x = list->header;
    int i;
    for (i = list->level; i >= 1; i--) {
        while (x->forward[i]->key < key)
            x = x->forward[i];
    }
    if (x->forward[1]->key == key) {
        return x->forward[1];
    } else {
        return NULL;
    }
    return NULL;
}
 
void skiplist_print(skiplist *list) {
    node *x = list->header;
    while (x && x->forward[1] != list->header) {
        printf("%d[%d]->", x->forward[1]->key, x->forward[1]->value);
        x = x->forward[1];
    }
    printf("NIL\n");
}
 
int main() {
    int arr[] = { 3, 6, 9, 2, 11, 1, 4 }, i;
    skiplist list;
    createSkiplist(&list);
 
    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        skiplist_insert(&list, arr[i], arr[i]);
    }
    skiplist_print(&list);
 
    printf("Search:--------------------\n");
    int keys[] = { 3, 4, 7, 10, 111 };
 
    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        node *x = skiplist_search(&list, keys[i]);
        if (x) {
            printf("key = %d, value = %d\n", keys[i], x->value);
        } else {
            printf("key = %d, not fuound\n", keys[i]);
        }
    }
 
    return 0;
}