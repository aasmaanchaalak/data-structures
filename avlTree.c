#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
	int height;
};

int max(int a, int b)
{
	return (a > b)? a : b;
}

struct Node* newNode(int val)
{
	struct Node* node = (struct Node*)
						malloc(sizeof(struct Node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return(node);
}

struct Node *rightRotate(struct Node *y)
{
	struct Node *x = y->left;
	struct Node *T2 = x->right;

	x->right = y;
	y->left = T2;

	y->height = max(y->left->height, y->right->height) + 1;
	x->height = max(x->left->height, x->right->height) + 1;

	return x;
}

struct Node *leftRotate(struct Node *x)
{
	struct Node *y = x->right;
	struct Node *T2 = y->left;

	y->left = x;
	x->right = T2;

	x->height = max(x->left->height, x->right->height) + 1;
	y->height = max(y->left->height, y->right->height) + 1;

	return y;
}


struct Node* insert(struct Node* node, int val)
{
	if (node == NULL)
		return(newNode(val));

	if (val < node->val)
		node->left = insert(node->left, val);
	else if (val > node->val)
		node->right = insert(node->right, val);
	else
		return node;

	node->height = 1 + max(node->left->height, node->right->height);


	int balance = node->left->height - node->right->height;

	if (balance > 1 && val < node->left->val)
		return rightRotate(node);

	if (balance < -1 && val > node->right->val)
		return leftRotate(node);

	if (balance > 1 && val > node->left->val)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	if (balance < -1 && val < node->right->val)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	return node;
}

printTree(struct Node *root){
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main(){
    struct Node *root = NULL;

    int n,c;
    printf("Enter the size - ");
    scanf ("%d", &n);

    for (int i=0; i<n; i++){
        scanf("%d", &c);
        insert(root, c);
    }

    printf("The AVL tree is - ");
    printTree(root);

    return 0;
}