#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int flag=0;
int depth=0;
int wordcheck=0;
int frequency=1;

struct node {
char data[100];
struct node* left;
struct node* right;
}*root=NULL;


int cDegree(struct node* temp){
	int x=0;
	while(temp!=NULL){
		x+=1;
		temp=temp->right;
	}
	return x;
}

int cDepth(struct node* root){
	int count=0,x=0;
	while(root!=NULL){
	struct node* temp=root;
	x=0;
	while(temp!=NULL){
		x+=1;
		temp=temp->left;
	}
	if(x>count)
	count=x;
	root=root->right;
	}
	return count;
}


void cFrequency(struct node* root,int count){
	while(root!=NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node*));
		temp=root->left;
		while(temp!=NULL){
			if(temp->left!=NULL){
				char ch=temp->left->data[0];
				int value=ch-'0';
				if(value==count){
					printf("%s - %d\n",temp->data,count);
					wordcheck=1;
				}
			}
			else if(temp->left==NULL && count==1){
				printf("%s\n",temp->data);
				wordcheck=1;
		}
		temp=temp->right;
	}
	root=root->right;
}
}


void category(struct node* root,char* ch,int x){
	if(x==0){
	if(root->left == NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->left=NULL;
		temp->right=NULL;
		root->left=temp;
		printf("\n Category Added into tree\n\n");
	}
	else{
		root=root->left;
		while(root->right != NULL){
		if(strcmp(root->data,ch) == 0)
		{
			printf("\nCategory already present in tree\n\n");
			return;
		}
		root=root->right;
		}
		if(strcmp(root->data,ch) == 0)
		{
			printf("\nCategory already present in tree\n\n");
			return;
		}
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->left=NULL;
		temp->right=NULL;
		root->right=temp;
		printf("\n Category Added into tree\n\n");
	}
	}
	else{
	if(root->left == NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->left=NULL;
		temp->right=NULL;
		root->left=temp;
		printf("\n Word Added into tree\n\n");
	}
	else{
		root=root->left;
		while(root->right != NULL){
		if(strcmp(root->data,ch) == 0){
			if(root->left == NULL){
				struct node* freq=(struct node*)malloc(sizeof(struct node));
				strcpy(freq->data,"2");
				flag=1;
				if(2 > frequency){
					frequency=2;
				}
				freq->left=NULL;
				freq->right=NULL;
				root->left=freq;
				printf("\nWord already present in tree .Frequency is updated\n\n");
				return;
			}
			else{
				char c1=root->left->data[0];
				int x=c1-'0';
				x=x+1;
				if(x > frequency){
					frequency=x;
				}
				c1=x+'0';
				root->left->data[0]=c1;
				printf("\nWord already present in tree .Frequency is updated\n\n");
				return;
			}
		}
		root=root->right;
		}
		if(strcmp(root->data,ch) == 0){
			if(root->left == NULL){
				struct node* freq=(struct node*)malloc(sizeof(struct node));
				strcpy(freq->data,"2");
				flag=1;
				if(2 > frequency){
					frequency=2;
				}
				freq->left=NULL;
				freq->right=NULL;
				root->left=freq;
				printf("\nWord already present in tree .Frequency is updated\n\n");
				return;
			}
			else{
				char c1=root->left->data[0];
				int x=c1-'0';
				x=x+1;
				if(x > frequency){
					frequency=x;
				}
				c1=x+'0';
				root->left->data[0]=c1;
				printf("\nWord already present in tree .Frequency is updated\n\n");
				return;
			}
		}
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->left=NULL;
		temp->right=NULL;
		root->right=temp;
		printf("\n Word Added to desired category\n\n");
	}
}
}



int degree=0;
void Degree(struct node* root, char* ch){
	if(root==NULL)
	return;
	if(strcmp(root->data,ch)==0){
		printf("\nDegree is %d\n\n",cDegree(root->left));
		degree=1;
	return ;
	}
	else{
		Degree(root->left,ch);
		Degree(root->right,ch);
	}
}


void Depth(struct node* root, char* ch){
	if(root==NULL)
	return ;
	if(strcmp(root->data,ch)==0){
		printf("\nDepth is %d\n\n",cDepth(root->left));
		depth=1;
	return ;
	}
	else{
		Depth(root->right,ch);
		Depth(root->left,ch);
	}
}

void display(struct node* root){
	printf("\n%s\n",root->data);
	root=root->left;
	while(root!=NULL){
		printf("\nCategory:\n");
		printf("%s\n",root->data);
		struct node* temp=root;
		temp=temp->left;
		printf("words:\n");
		if(temp==NULL)
		printf("empty\n");
		else{
		while(temp!=NULL){
			printf("%s",temp->data);
			if(temp->left != NULL){
				printf(" %s\n",temp->left->data);
			}
			else{
				printf("\n");
			}
			temp=temp->right;
		}
	}
		root=root->right;
	}
	printf("\n");
}
void LeafNodes(struct node* root){
	while(root!=NULL){
	struct node* temp=root->left;
	if(temp==NULL){
		printf("%s\n",root->data);
	}
	else{
	while(temp!=NULL){
		printf("%s\n",temp->data);
		temp=temp->right;
	}
	}
	root=root->right;
}
printf("\n");
}
void Addwords(struct node* root,char* ch,char* cat){
	if(root->left == NULL){
		printf("\n\nNo Categories present\n\n");
		return;
	}
	else{
		root=root->left;
		while(root!= NULL){
		if(strcmp(root->data,cat) == 0){
			break;
		}
		root=root->right;
		}
		if(root==NULL){
			printf("\nNo such category present in tree\n\n");
			return;
		}
		else{
		category(root,ch,1);
	}
}
}
int main(){
char ch[]="words";
struct node* head=(struct node*)malloc(sizeof(struct node));
strcpy(head->data,ch);
head->left=NULL;
head->right=NULL;
root=head;
int choice;
while (1)
    {
printf("1.Add Category\n2.Add word\n3.Display\n4.Display Leaf nodes excluding Level 4\n5.Depth of any Node\n6.Degree of any Node\n7.Display the Words in Frequency Descending order\n8.Exit\nEnter Your choice : \n");
        if(scanf("%d", &choice)==1){
        if(choice==1){
        	fflush(stdin);
        	char ch[20];
        	printf("Enter the Category : ");
        	gets(ch);
        	category(root,ch,0);
			}
		else if(choice==2){
			if(root->left == NULL)
			printf("\nNo Categories Present\n\n");
			else{
			fflush(stdin);
        	char ch[20];
        	printf("Enter the word : ");
        	gets(ch);
        	fflush(stdin);
        	char cat[20];
        	printf("Enter the Category into which You want to Add: ");
        	gets(cat);
        	Addwords(root,ch,cat);
		}
	}
		else if(choice==3){
			display(root);
		}
		else if(choice==4){
			printf("\nLeaf nodes excluding Level 4 :\n");
			if(root->left==NULL)
			printf("%s\n\n",root->data);
			else
			LeafNodes(root->left);
		}
		else if(choice==5){
            printf("Enter the category or word : ");
			fflush(stdin);
        	char x[20];
        	gets(x);
        	if(strcmp(x,"words")==0 && flag==1){
        		printf("\nDepth is 3\n");
			}
			else{
        	Depth(root,x);
        	if(depth==0)
        	printf("\nNo such word present in tree\n\n");
        	depth=0;
		   }
		}
		else if(choice==6){
			printf("Enter the category or Word : ");
			fflush(stdin);
        	char w[20];
        	gets(w);
        	Degree(root,w);
        	if(degree==0)
        	printf("\nNo such word present in tree\n");
        	degree=0;
        }

		else if(choice==7){
			if(root->left == NULL){
				printf("\nWords not Present\n\n");
			}
			else{
			printf("\n");
			int p=frequency;
			while(p>0){
			cFrequency(root->left,p);
			p--;
			}
			if(wordcheck==0)
			printf("Words not Present\n");
			printf("\n");
		}
		}
		else if(choice==8)
		break;
		else
			printf("\nEnter valid choice\n\n");
    }
    }
}
