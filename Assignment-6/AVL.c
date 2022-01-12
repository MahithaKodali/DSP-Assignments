#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	int height;
};
void currentLevel(struct Node *root, int level);
int max(int a,int b);
int height(struct Node *N)
{
	if(N==NULL)
		return 0;
	return N->height;
}
int max(int a,int b)
{
	return (a>b)?a:b;
}
struct Node* newNode(int key)
{
	struct Node* node=(struct Node*)malloc(sizeof(struct Node));
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return (node);
}
struct Node *rightRotate(struct Node *y)
{
	struct Node *x=y->left;
	struct Node *T2=x->right;
	x->right=y;
	y->left=T2;
	y->height=max(height(y->left),height(y->right))+1;
	x->height=max(height(x->left),height(x->right))+1;
	return x;
}
struct Node *leftRotate(struct Node *x)
{
	struct Node *y=x->right;
	struct Node *T2=y->left;
	y->left=x;
	x->right=T2;
	x->height=max(height(x->left),height(x->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
int getBalance(struct Node *N)
{
	if(N==NULL)
		return 0;
	return height(N->left)-height(N->right);
}
struct Node* insert(struct Node* node,int key)
{
	if(node==NULL)
		return (newNode(key));
	if(key<node->key)
		node->left=insert(node->left,key);
	else if(key>node->key)
		node->right=insert(node->right,key);
	else
		return node;
	node->height=1+max(height(node->left),height(node->right));
	int balance=getBalance(node);
	if(balance>1 && key<node->left->key)
		return rightRotate(node);
	if(balance<-1 && key>node->right->key)
		return leftRotate(node);
	if(balance>1 && key>node->left->key)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(balance<-1 && key<node->right->key)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
struct Node* minValueNode(struct Node* node)
{
	struct Node* current=node;
	while(current->left != NULL)
		current=current->left;
	return current;
}
struct Node* delete(struct Node* root,int key)
{
	if(root==NULL)
		return root;
	if(key<root->key)
		root->left=delete(root->left,key);
	else if(key>root->key)
		root->right=delete(root->right,key);
	else
	{
		if((root->left==NULL)||(root->right==NULL))
		{
			struct Node *temp=root->left ? root->left :root->right;
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
			else
				*root=*temp;
			free(temp);
		}
		else
		{
			struct Node* temp=minValueNode(root->right);
			root->key=temp->key;
			root->right=delete(root->right,temp->key);
		}
	}
	if(root==NULL)
		return root;
	root->height=1+max(height(root->left),height(root->right));
	int balance=getBalance(root);
	if(balance>1 && getBalance(root->left)>=0)
		return rightRotate(root);
	if(balance>1 && getBalance(root->left)<0)
	{
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	if(balance<-1 && getBalance(root->right)<=0)
		return leftRotate(root);
	if(balance<-1 && getBalance(root->right)>0)
	{
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
void preOrder(struct Node *root)
{
	if(root!=NULL)
	{
		printf("%d  ",root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d  ", root->key);
}
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    printf("%d  ", root->key);
    inOrder(root->right);
}
void levelOrder(struct Node *root)
{
    int h = Height(root);
    int i;
    for (i = 1; i <= h; i++)
        currentLevel(root, i);
}
 
void currentLevel(struct Node *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d  ", root->key);
    else if (level > 1) {
        currentLevel(root->left, level - 1);
        currentLevel(root->right, level - 1);
    }
}
 
int Height(struct Node *N)
{
    if (N == NULL)
        return 0;
    else {
        int lheight = Height(N->left);
        int rheight = Height(N->right);
 
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}
int sumLeft(struct Node *root)
{
   if(root == NULL)
     return 0;
   return sumLeft(root->left) + root->key + sumLeft(root->right);
}

int main()
{
	struct Node *root=NULL;
	int sum,ch,n;
	while(1)
	{
	printf("\n1. INSERT\n2. DELETE\n3. DISPLAY\n4. SUM OF LEFT SUB-TREE NODES\n5.EXIT\n");
	printf("Enter choice : ");
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter node value : ");
		scanf("%d",&n);
		root=insert(root,n);
	}
	else if(ch==2)
	{
		printf("Enter node value : ");
		scanf("%d",&n);
		root=delete(root,n);
	}
	else if(ch==3)
	{
		printf("\nPRE ORDER : ");
		preOrder(root);
		printf("\n");
		printf("IN ORDER : ");
		inOrder(root);
		printf("\n");
		printf("POST ORDER : ");
		postOrder(root);
		printf("\n");
		printf("LEVEL ORDER : ");
		levelOrder(root);
		printf("\n\n");
	}
	else if(ch==4)
	{
		sum=sumLeft(root->left);
		printf("Left sub-tree sum = %d\n",sum);
	}
	else if(ch==5)
		break;
	else
		printf("Invalid choice");
   }
	return 0;
}
