#include <stdio.h>
#include <stdlib.h>

struct binaryTree{
    int val;
    struct binaryTree* left;
    struct binaryTree* right;
};

typedef struct binaryTree * NodeAddress;

NodeAddress createNode(int i){
    NodeAddress new = malloc(sizeof(struct binaryTree));
    new->val = i;
    new->right = NULL;
    new->left = NULL;
    return new;
}

NodeAddress search(NodeAddress root, int i){
    if (root){
        if ( i > root->val ){
            search(root->right, i);
        } else if ( i < root->val ){
            search(root->left, i);
        } else {
            return root;
        }
    } else {
        return NULL;
    }
}

NodeAddress insert(NodeAddress root, int i){
    if (root==NULL){
        return createNode(i);
    }
    
    if (root){
        if ( i < root->val ){
            if (root->left){
                return insert(root->left, i);
            } else {
                root->left = createNode(i);
            }
            return root->left;
        } else if ( i < root->val ){
            if (root->right){
                return insert(root->right, i);
            } else {
                root->right = createNode(i);
            }
            return root->right;
        }
    }
    return root;
}

void printBinaryTree(NodeAddress tree)
{
    if (tree == NULL) // If the tree points to nothing, just return
    {
        return;
    }
    else // Else, print the smaller elements first, then print the node's value, then print the bigger elements
    {
        printBinaryTree(tree->left);
        printf("%d ", tree->val);
        printBinaryTree(tree->right);
    }
}

int main(){

    NodeAddress tree = malloc(sizeof(struct binaryTree));

    //taking number of elements in array
    int n,i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (i=0; i<n; i++){
        int d;
        //taking each element in array
        scanf("%d", &d);
        insert(tree, i);
    }

    printBinaryTree(tree);
}
