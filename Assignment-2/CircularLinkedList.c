#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    char data[50];  
    struct node *next;   
};  
struct node *head;  
void lastinsert ();   
void display(); 
int i; 
void main ()  
{ 
  for(i=0;i<5;i++) 
  {
  	lastinsert();
  } 
  display();
}  
void lastinsert()  
{  
    struct node *ptr,*temp;   
    char data[50];  
    ptr = (struct node *)malloc(sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\nOVERFLOW\n");  
    }  
    else  
    {  
        printf("\nEnter string :");  
        scanf("%s",data[50]);  
        if(head == NULL)  
        {  
            head = ptr;  
            ptr -> next = head;    
        }  
        else  
        {  
            temp = head;  
            while(temp -> next != head)  
            {  
                temp = temp -> next;  
            }  
            temp -> next = ptr;   
            ptr -> next = head;  
        } 
    }  
  
}  
void display()  
{  
    struct node *ptr;  
    ptr=head;  
    if(head == NULL)  
    {  
        printf("\nnothing to print");  
    }     
    else  
    {     
        while(ptr -> next != head)  
        {  
          
            printf("%s\n", ptr -> data);  
            ptr = ptr -> next;  
        }  
        printf("%s\n", ptr -> data);  
    }  
              
}  
