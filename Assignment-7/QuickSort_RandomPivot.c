#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=(low-1),j;
	for(j=low;j<=high-1;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

int partition_random(int arr[],int low,int high)
{
	srand(time(NULL));
	int random=low+rand()%(high-low);
	swap(&arr[random],&arr[high]);
	return partition(arr,low,high);
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition_random(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}

void display(int arr[])
{
	int i,n;
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int main()
{
	int n,i,l=0;
	clock_t start,end;
	double run;
	printf("Enter size of array : ");
	scanf("%d",&n);
	int arr[n];
	srand(time(0));
	for(i=0;i<n;i++)
	{
		arr[i]=(rand()%(n-l+1))+l;
	}
	printf("\nRandom array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	start=clock();
	quickSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	display(arr);
	printf("Total run time = %lf\n",run);
	
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	start=clock();
	quickSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	display(arr);
	printf("Total run time = %lf\n",run);
	
    printf("\nAlmost sorted array : ");	
	swap(&arr[0],&arr[1]);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);	
	}
	start=clock();
	quickSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	display(arr);
	printf("Total run time = %lf\n",run);
	return 0;
}
