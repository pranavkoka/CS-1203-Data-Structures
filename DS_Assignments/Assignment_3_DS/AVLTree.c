#include <stdio.h>  
#include <stdlib.h>  
   
struct Node  
{  
    int key;  
    struct Node *left;  
    struct Node *right;  
    int height;  
};  
   
int getHeight(struct Node *n){  
    if(n==NULL)  
        return 0;  
    return n->height;  
}  
   
struct Node *createNode(int key){  
    struct Node* node = (struct Node *) malloc(sizeof(struct Node));  
    node->key = key;  
    node->left = NULL;  
    node->right = NULL;  
    node->height = 1;  
    return node;  
}  

void displayTree(struct Node* root, int space)
{
    int i;

    if (root == NULL) return;

    space += 10;

    // Process right child first
    displayTree(root->right, space);

    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    displayTree(root->left, space);
}
   
int max (int a, int b){  
    return (a>b)?a:b;  
}  
   
int getBalanceFactor(struct Node * n){  
    if(n==NULL){  
        return 0;  
    }  
    return getHeight(n->left) - getHeight(n->right);  
}  
   
struct Node* rightRotate(struct Node* y){  
    struct Node* x = y->left;  
    struct Node* T2 = x->right;  
   
    x->right = y;  
    y->left = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return x;  
}  
   
struct Node* leftRotate(struct Node* x){  
    struct Node* y = x->right;  
    struct Node* T2 = y->left;  
   
    y->left = x;  
    x->right = T2;  
   
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;  
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;  
   
    return y;  
}  
   
struct Node *insert(struct Node* node, int key){  
    if (node == NULL)  
        return  createNode(key);  
   
    if (key < node->key)  
        node->left  = insert(node->left, key);  
    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));  
    int bf = getBalanceFactor(node);  
   
    // Left Left Case  
    if(bf>1 && key < node->left->key){  
        return rightRotate(node);  
    }  
    // Right Right Case  
    if(bf<-1 && key > node->right->key){  
        return leftRotate(node);  
    }  
    // Left Right Case  
    if(bf>1 && key > node->left->key){  
            node->left = leftRotate(node->left);  
            return rightRotate(node);  
        }  
    // Right Left Case  
    if(bf<-1 && key < node->right->key){  
            node->right = rightRotate(node->right);  
            return leftRotate(node);  
        }  
    return node;  
}  

struct Node* minNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

struct Node *delete(struct Node* root, int key)
{
    if (root == NULL) return root;
    if (key<root->key) root->left = delete(root->left, key);
    else if (key>root->key) root->right = delete(root->right, key);
    else
    {
        if (root->left == NULL || root->right == NULL)
        {
            struct Node* temp;
            if (root->left != NULL) temp = root->left;
            else temp = root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else *root = *temp;
            free(temp);
        }
        else 
        {
            struct Node* temp = minNode(root->right);
            root->key = temp->key;
            root->right = delete(root->right, temp->key);
        }

    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (bf > 1 && getBalanceFactor(root->left) < 0) 
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (bf < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (bf < -1 && getBalanceFactor(root->right) > 0) 
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
   
void preOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        printf("%d ", root->key);  
        preOrder(root->left);  
        preOrder(root->right);  
    }  
}  

void inOrder(struct Node *root)  
{  
    if(root != NULL)  
    {  
        preOrder(root->left);  
        printf("%d ", root->key);  
        preOrder(root->right);  
    }  
}  
   
int main(){  
    struct Node * root = NULL;  
   
   
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 60);  
    root = insert(root, 30);  
    root = insert(root, 70);  
    root = insert(root, 80);  
    root = insert(root, 90);  
    preOrder(root);  
    printf("\n");

    inOrder(root);  
    printf("\n");

    displayTree(root, 10);

    root = delete(root, 60);

    preOrder(root);  
    printf("\n");

    inOrder(root);  
    printf("\n");

    displayTree(root, 10);

    root = delete(root, 40);

    preOrder(root);  
    printf("\n");

    inOrder(root);  
    printf("\n");

    displayTree(root, 5);


    return 0;  
} 