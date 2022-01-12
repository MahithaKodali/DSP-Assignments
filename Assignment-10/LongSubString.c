#include <stdio.h>
#include <string.h>
void printSubStr(char* str, int low, int high)
{
    int i;
	for (i = low; i <= high; ++i)
        printf("%c", str[i]);
}

int longestPalSubstr(char* str)
{
    int maxLength = 1;
	int start = 0;
    int len = strlen(str);
	int low, high,i;
    for (i = 1; i < len; ++i)
	{
        low = i - 1;
        high = i;
        while (low >= 0 && high < len && str[low] == str[high]) 
		{
            --low;
            ++high;
        }
        ++low; 
		--high;
        if (str[low] == str[high] && high - low + 1 > maxLength) 
		{
            start = low;
            maxLength = high - low + 1;
        }
        low = i - 1;
        high = i + 1;
        while (low >= 0 && high < len && str[low] == str[high])
		{
            --low;
            ++high;
        }
        ++low;
		--high;
        if (str[low] == str[high] && high - low + 1 > maxLength) 
		{
            start = low;
            maxLength = high - low + 1;
        }
    }
    printSubStr(str, start, start + maxLength - 1);
}

int main()
{
    char str[50];
    printf("\nEnter string : ");
    scanf("%s",&str);
    longestPalSubstr(str);
    return 0;
}
