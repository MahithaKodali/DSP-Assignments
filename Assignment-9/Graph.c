#include<stdio.h>

int q[20],top=-1,front=-1,rear=-1,a[20][20],vis[20],stack[20];

void add(int item)
{
	if(rear==19)
		printf("Queue is full");
	else
	{
		if(rear==-1)
		{
			q[++rear]=item;
			front++;
		}
		else
			q[++rear]=item;
	}
}

int delete()
{
	int k;
	if((front>rear)||(front==-1))
		return(0);
	else
	{
		k=q[front++];
		return(k);
	}
}

void bfs(int s,int n)
{
	int p,i;
	add(s);
	vis[s]=1;
	p=delete();
	if(p!=0)
		printf(" %d",p);
	while(p!=0)
	{	
		for(i=1;i<=n;i++)
			if((a[p][i]!=0)&&(vis[i]==0))
			{
				add(i);
				vis[i]=1;
			}
		p=delete();
		if(p!=0)
			printf(" %d ",p);
	}
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			bfs(i,n);
}

void push(int item)
{
	if(top==19)
		printf("Stack overflow ");
	else
		stack[++top]=item;
}

int pop()
{
	int k;
	if(top==-1)
		return(0);
	else
	{
		k=stack[top--];
		return(k);
	}
}

void dfs(int s2,int n)
{
	int i,k;
	push(s2);
	vis[s2]=1;
	k=pop();
	if(k!=0)
		printf(" %d ",k);
	while(k!=0)
	{
		for(i=1;i<=n;i++)
			if((a[k][i]!=0)&&(vis[i]==0))
			{
				push(i);
				vis[i]=1;
			}
			k=pop();
			if(k!=0)
			printf(" %d ",k);
	}
	for(i=1;i<=n;i++)
	if(vis[i]==0)
	dfs(i,n);
}

void main()
{
	int n,i,s,ch,j,s2;
	while(1)
	{
		for(i=1;i<=n;i++)
			vis[i]=0;
		printf("\n1. Create a graph");
		printf("\n2. BFS");
		printf("\n3. DFS");
		printf("\n4. Exit");
		printf("\nEnter choice : ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter no.of vertices : ");
			scanf("%d",&n);
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					printf("Enter 1 if %d---%d else 0 : ",i,j);
					scanf("%d",&a[i][j]);
				}
			}
			printf("THE ADJACENCY MATRIX IS\n");
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
					printf(" %d",a[i][j]);
				}
				printf("\n");
			}
	    }
	    else if(ch==2)
	    {
	    	printf("Enter source vertex :");
			scanf("%d",&s);
			bfs(s,n);
		}
		else if(ch==3)
		{
			printf("Enter source vertex :");
			scanf("%d",&s2);
			dfs(s2,n);
		}
		else if(ch==4)
		{
			exit(0);
		}
	}
}
