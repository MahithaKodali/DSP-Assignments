#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void display();
void traverse();
void insertAtFront();
void insertAtEnd();
struct node {
	int info;
	struct node* link;
};
struct node* start = NULL,*c,*p,*r;
void main()
{
 int choice;
	while (1) 
	{
    	printf("\n\n***INSERTION***\n");
		printf("1 At beginning\n");
		printf("2 At ending\n");
		printf("3 Display\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);
		if (choice==1)
		{
			insertAtFront();
		}
		else if(choice==2)
		{
			insertAtEnd();
		}
		else if(choice==3)
		{
			traverse();
			display();
			break;
		}
		else
			printf("Incorrect Choice\n");
	}
}
void display()
{
 int dec=0;
 if(start == NULL)
  printf("list is empty");
 else
  {
   for(c=start;c!=NULL;c=c->link)
   {
    dec=dec*2+c->info;
   }
   printf("Decimal value = %d",dec);
  }
}
void traverse()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		printf("Linked List is : \n");
		while (temp != NULL) {
			printf("%d -> ",temp->info);
			temp = temp->link;
		}
		printf("\n\n");
	}
}
void insertAtFront()
{
	int data;
	struct node* temp;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->info = data;
	temp->link = start;
	start = temp;
}
void insertAtEnd()
{
	int data;
	struct node *temp, *head;
	temp = malloc(sizeof(struct node));
	printf("\nEnter number to"
		" be inserted : ");
	scanf("%d", &data);
	temp->link = 0;
	temp->info = data;
	head = start;
	while (head->link != NULL) {
		head = head->link;
	}
	head->link = temp;
}
