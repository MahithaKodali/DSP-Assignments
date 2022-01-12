#include<stdio.h>
#include<stdlib.h>

void insert(int h[],int size)
{

 int key,index,i,hkey;
 printf("\nEnter a value to insert :\n");
 scanf("%d",&key);
 hkey=key%size;
 if(h[hkey]==NULL)
 {
 	h[hkey]=key;
 }
 else
 {
  for(i=0;i<size;i++)
  {
	index=(hkey+i*i)%size;
	if(h[index] ==NULL)
    {
    	h[index]=key;
        break;
    }
  }
  if(i==size)
	printf("\nElement cannot be inserted\n");
}
}

void search(int h[],int size)
{

 int key,index,i,hkey;
 printf("\nEnter search element\n");
 scanf("%d",&key);
 hkey=key%size;
 if(h[hkey]==key)
 {
 	printf("Value is at index %d",hkey);
 }
 else
 {
  for(i=0;i<size; i++)
  {
    index=(hkey+i*i)%size;
    if(h[index]==key)
    {
      printf("Value is at index %d",index);
      break;
    }
  }
  if(i ==size)
    printf("\n Value is not found\n");
 }
  
}

void delete(int h[],int size)
{

 int key,index,i,hkey;
 printf("\nEnter element to delete : \n");
 scanf("%d",&key);
 hkey=key%size;
 if(h[hkey]==key)
 {
 	h[hkey]=NULL;
 }
 else
 {
  for(i=0;i<size; i++)
  {
    index=(hkey+i*i)%size;
    if(h[index]==key)
    {
      h[index]=NULL;
      break;
    }
  }
 if(i ==size)
    printf("\n Value is not found\n");
}
}

void display(int h[],int size)
{
  int i,count=0;
  float lf;
  printf("\nElements in the hash table are \n");

  for(i=0;i<size; i++)
  {
  	printf("\nindex [%d] =  %d",i,h[i]);
  	if(h[i]!=NULL)
  		count++;
  }
  lf=(float)count/size;
  printf("\nLoad Factor = %f\n",lf);
}
main()
{
    int opt,i,size;
    printf("\nEnter size of table : ");
    scanf("%d",&size);
    int h[size];
    
    for(i=0;i<size;i++)//Initialise with NULL
    {
    	h[i]=NULL;
	}
	
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Load Factor\n5. Exit\n");
        printf("Enter your choice : \n");
        scanf("%d",&opt);
        if(opt==1)
        {
			insert(h,size);
        }
        else if(opt==2)
        {
        	delete(h,size);
		}
        else if(opt==3)
        {
            search(h,size);
        }
        else if(opt==4)
        {
            display(h,size);
        }
        else if(opt==5)
			exit(0);
    }
}
