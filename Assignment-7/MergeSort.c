#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
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
	mergeSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	printArray(arr,n);
	printf("Total run time = %lf\n",run);
	
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	start=clock();
	mergeSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	printArray(arr,n);
	printf("Total run time = %lf\n",run);
	
    printf("\nAlmost sorted array : ");	
	swap(&arr[0],&arr[n-1]);
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);	
	}
	start=clock();
	mergeSort(arr, 0, n-1);
	end=clock();
	run=((double)(end-start))/CLOCKS_PER_SEC;
	printf("\nResultant Sorted array is : ");
	printArray(arr,n);
	printf("Total run time = %lf\n",run);
	return 0;
}

