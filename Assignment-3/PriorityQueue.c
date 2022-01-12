#include<stdio.h>
#define N 20
int Pr[N];
char Q[N];
int r = -1,f = -1;
void enqueue(char data,int p);
void display();
int dequeue();
void enqueue(char data,int p)
{
	int i;
	if((f==0)&&(r==N-1)) 
		printf("Queue is full");
	else
	{
		if(f==-1)
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == N-1)
		{
			for(i=f;i<=r;i++) { 
			Q[i-f] = Q[i]; Pr[i-f] = Pr[i]; 
			r = r-f; f = 0;
			for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void display() 
{
    int i;
	for(i=f;i<=r;i++)
	{
		printf("\nName = %s\tGATE score = %d",Q[i],Pr[i]);
	}
}
int dequeue() 
{
	if(f == -1)
	{
		printf("Queue is Empty");
	}	
	else
	{
		printf("deleted name = %s\t GATE score = %d",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
int main()
{
	int opt,n,i,p;
	char data;
	while(1)
	{
		printf("\n\n1  Insert the data in Queue\n2 Display the data in Queue \n3  Delete the data from the Queue\n4 Exit\n");
		printf("\nEnter your choice :" );
		scanf("%d",&opt);
		if(opt==1)
		{
			printf("\nEnter student name: ");
			scanf("%s",&data);
			printf("\nEnter GATE score : ");
			scanf("%d",&p);
			enqueue(data,p);
			i++;
		}
		else if(opt==2)
		{
		 	display();
		}
		else if(opt==3)
		{
			dequeue();
		}
		else if(opt==4)
		{
			break;
		}
	}
        return 0;
}
