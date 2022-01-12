#include <stdio.h>
#include <limits.h>
int min(int x, int y) {
    return (x < y) ? x : y;
}
int findSmallestSubarrayLen(int arr[], int n, int k)
{
    int windowSum = 0;
    int len = INT_MAX;
    int left = 0,right=0;
    for (right;right < n; right++)
    {
        windowSum += arr[right];
        while (windowSum > k && left <= right)
        {
            len = min(len, right - left + 1);
            windowSum -= arr[left];
            left++;
        }
    }
    if (len == INT_MAX) {
        return 0;
    }
    return len;
}
 
int main()
{
    int i,size;
	printf("Enter array length : \n");
    scanf("%d",&size);
    
    int arr[size];
    printf("Enter array elements:\n");
    for(i = 0; i < size;  i++){
    	scanf("%d", &arr[i]);
     }
    int k;
 
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Enter a value :\n");
    scanf("%d",&k);
    int len = findSmallestSubarrayLen(arr, n, k);
 
    if (len != INT_MAX) {
        printf("The smallest subarray length is %d", len);
    }
    else {
        printf("No subarray exists");
    }
 
    return 0;
}



