/* 
	Old keypad in a foreign land - Hacker Earth

*/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


void SelectionSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]<a[j])
            {
                swap(&a[i],&a[j]);
            }
        }
    }
}


int main()
{
    int n;
    scanf("%d",&n);
    int freArr[100];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&freArr[i]);
    }
    
    int k,sum=0;
    
    int keySize[100];
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&keySize[i]);
        sum+=keySize[i];
    }

    if(sum<n)
    {
        printf("-1");
        return 0;
    }
    SelectionSort(freArr,n);
    SelectionSort(keySize,k);
    int min=0,j=1,l=0;
    
    for(int i=0;i<n;i++)
    {
        while(keySize[l]==0) l++;
        if(l>=k) 
        {
            l=0;
            j++;
        }
        min+=freArr[i]*j;
        keySize[l]--;
        l++;
       
        
    }
    printf("%d",min);
	return 0;
}