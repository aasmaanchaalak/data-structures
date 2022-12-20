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

int replace(NodeAddress root, const i){
        if (i=="right"){
            root = root->right;
            while (root->left){
                root = root->left;
            }
        } else {
            root = root->left;
            while (root->right){
                root=root->right;
            }
        }
        return root->val;
}

NodeAddress deleteNode(NodeAddress root, int i){
    root = search(root, i);

    if (root){
        if ( i > root->val ){
            deleteNode(root->right, i);
        } else if ( i < root->val ){
            deleteNode(root->left, i);
        } else {
            if (root->left == NULL && root->right){
                root = NULL;
            } else if (root ->right){
                root -> val = replace(root, "right");
                root -> right = deleteNode(root->right, root->val);
            } else {
                root -> val = replace(root, "left");
                root -> left = deleteNode(root->left, root->val);
            }
        }
    } else {
        return NULL;
    }
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

    printf("Which number do you want to delete - ");
    scanf("%d", &i);
    deleteNode(tree, i);
}
