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

int partition_median(int arr[],int low,int high)
{
	int pivot;
	int mid=(low+high)/2;
	if(arr[mid]<arr[low])
	{
		swap(&arr[mid],&arr[low]);
	}
	if(arr[high]<arr[low])
	{
		swap(&arr[high],&arr[low]);
	}
	if(arr[high]<arr[mid])
	{
		swap(&arr[high],&arr[mid]);
	}
	swap(&arr[mid],&arr[high-1]);
	pivot=arr[high-1];
	return partition(arr,low,high);
}

void quickSort(int arr[],int low,int high)
{
	if(low<high)
	{
		int pi=partition_median(arr,low,high);
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
	quickSort(arr, n/4,(3*n)/4);
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
	quickSort(arr, n/4,(3*n)/4);
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
	quickSort(arr,n/4,(3*n)/4);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	display(arr);
	printf("Total run time = %lf\n",run);
	return 0;
}
