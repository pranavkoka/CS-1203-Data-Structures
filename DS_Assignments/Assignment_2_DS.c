#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int key;
	struct node *left, *right;
} NODE;

NODE * createNode(int k)
{
	NODE *temp;
	temp = (NODE *) malloc(sizeof(NODE));
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

NODE * insert(NODE * anode, int k)
{
	NODE *temp, *parent;
	int direction;
	if (anode == NULL)
	{
		anode = createNode(k);
		return anode;
	}
	temp = anode;
	while (temp != NULL)
	{
		if (temp->key == k)
		{
			printf("node with value %d exists\n", k);
			return temp;
		}
		if (k < temp->key)
		{
			parent = temp;
			temp = temp->left;
			direction = 0;
		}
		else
		{
			parent = temp;
			temp = temp->right;
			direction = 1;
		}
	}
	temp = createNode(k);
	if (direction==0) parent->left = temp;
	else parent->right = temp;
	return temp;
}

void inorder_rec(NODE *anode)
{
	if (anode != NULL) 
	{
		inorder_rec(anode->left);
		printf("%d ", anode->key);
		inorder_rec(anode->right);
	}
}

typedef struct sNode
{
	NODE* t;
	struct sNode* next;
}STACKNODE;

void push(STACKNODE** stack_top, NODE* node)
{
	STACKNODE* new_node = (STACKNODE*)malloc(sizeof(STACKNODE));
	if (new_node == NULL)
	{
		printf("Stack Overflow\n");
		getchar();
		exit(0);
	}
	new_node->t = node;
	new_node->next = (*stack_top);
	(*stack_top) = new_node;
}

NODE* pop(STACKNODE** stack_top)
{
	NODE* result;
	STACKNODE* top;
	if (*stack_top == NULL)
	{
		printf("Stack Underflow \n");
        getchar();
        exit(0);
	}
	else
	{
		top = *stack_top;
		result = top->t;
		*stack_top = top->next;
		free(top);
		return result;
	}
}

void inorder_stack(NODE* root)
{
	NODE* current = root;
	STACKNODE* s = NULL;
	int done = 0;
	while(done == 0)
	{
		if (current != NULL)
		{
			push(&s, current);
			current = current->left;
		}
		else
		{
			if(s != NULL)
			{
				current = pop(&s);
				printf("%d ", current->key);
				current = current->right;
			}
			else done = 1;
		}
	}
}

int main()
{
	NODE *root1 = NULL;
	root1 = insert(root1, 50);
    insert(root1, 30);
    insert(root1, 20);
    insert(root1, 40);
    insert(root1, 70);
    insert(root1, 60);
    insert(root1, 80);

    NODE *root2 = NULL;
	root2 = insert(root2, 4);
    insert(root2, 7);
    insert(root2, 9);
    insert(root2, 6);
    insert(root2, 13);
    insert(root2, 21);
    insert(root2, 17);

    // Displaying the elements in the tree using recursive inorder traversal
    printf("Inorder recursive Traversal 1: ");
    inorder_rec(root1);
    printf("\n");

    // Displaying the elements in the tree using stack inorder traversal
    printf("Inorder stack Traversal 1    : ");
    inorder_stack(root1);
    printf("\n\n");

    printf("Inorder recursive Traversal 2: ");
    inorder_rec(root2);
    printf("\n");

    printf("Inorder stack Traversal 2    : ");
    inorder_stack(root2);
    printf("\n");

    return 0;
}

//took help from geekforgeeks and class notes