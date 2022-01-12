#include <stdio.h>
#include<stdlib.h>
#define arr_size 50
#define no_of_q 4
#define q_size (arr_size/no_of_q)
int multiarr[arr_size]={0};
int rear[no_of_q]={5,3,2,6};
void creat();
void display_all();
void display2();
void initialize();
void insert();
void delet();
void main(){
	int choice,i,j,k;
	k=0;
	while(1){
		printf("\n 1. Initialize multi level queues with given default sizes");
		printf("\n 2. Insertion in queue with minimum nuber of elements");
		printf("\n 3. Deletion from queue with maximum number of elements");
		printf("\n 4. Display all queues");
		printf("\n 0. Exit");
		printf("\n\n Enter your choice: ");
		if(scanf("%d",&choice)==1){
			if(choice == 1){
				if(k==1){
					printf("\nMulti level Queue already initialized\n");
				}
				else if(k==0){
					initialize();
					k=1;
					printf("\n");
				}
				else{ }	
			}
			else if (choice == 2){
				if(k==0){
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					insert();
				}
			}
			else if (choice == 3){
				if(k==0){
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					delet();
				}
			}
			else if (choice == 4){
				if(k==0){
					display_all();
					printf("\n Multi level queue has not been initialized\n\n");
				}
				else{
					display2();
				}
			}
			else if (choice ==0){
				break;
			}
			else{
				printf("\n Invalid choice. Enter a valid choice\n");
			}
		}
		else{
			printf("\n Invalid choice\n\n");
			exit(0);
		}
	}	
}
void initialize(){
	int i,j,temp,k;
	for(j=0;j<no_of_q;j++){
		i=q_size*j;
		for(k=0;k<rear[j];k++,i++){
			multiarr[i]=(i+1);			
		}
	}
	display2();
}

void insert(){
	int val,front,j,k,temp,min,index;
	min=rear[0];
	index=0;
	for(front=0;front<no_of_q;front++){
		if(rear[front]<min){
			min=rear[front];
			index=front;
		}
	}
	front=q_size*index;
	printf("\n Enter value to be inserted into queue %d:  ",index+1);
	scanf("%d",&multiarr[front+min]);
	printf("\n Inserted value is %d\n\n",multiarr[front+min]);
	rear[index]=rear[index]+1;
	
}


void delet(){
	int val,front,j,k,temp,max,index;
	max=rear[0];
	index=0;
	for(front=0;front<no_of_q;front++){
		if(rear[front]>max){
			max=rear[front];
			index=front;
		}
	}
	
	front=q_size*index;
	printf("\ndeleted value is %d\n",index+1,multiarr[front+max-1]);
	multiarr[front+max-1]=0;
	rear[index]=rear[index]-1;	
	
}
void display_all(){
	int front,j,temp;
	printf("\n Multi level queue: ");
	for(j=0;j<no_of_q;j++){
		printf("\n Queue no - %d\n",j+1);
		front=q_size*j;
		temp=q_size;
		while(temp--){
			printf("%d ",multiarr[front++]);
		}
		printf("\n");
	}
}
void display2(){
	int j,k,front;
	printf("\n Multi level queue: \n");
	for(j=0;j<no_of_q;j++){
		printf("\n Queue no - %d\n",j+1);
		front=q_size*j;
		for(k=0;k<rear[j];k++,front++){
			printf("%d ",multiarr[front]);			
		}
		printf("\n");
	}
}

