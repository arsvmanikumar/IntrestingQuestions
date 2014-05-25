// Merge Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<malloc.h>


void merge(int arr[],int left_first,int right_first,int right_end)
{
	int left_end=right_first-1;
	int iterator=0;
	int *mem=(int *)malloc(sizeof(int)*((right_end-left_first)+1));
	while(left_first<=left_end && right_first<=right_end)
	{
		if(arr[left_first]<arr[right_first])
		{
			*(mem+iterator)=arr[left_first];
			left_first++;
		}
		else
		{
			*(mem+iterator)=arr[right_first];
			right_first++;
		}
		iterator++;
	}
	while(left_first<=left_end)
	{
			*(mem+iterator)=arr[left_first];
			left_first++;
			iterator++;
	}

	while(right_first<=right_end)
	{		*(mem+iterator)=arr[right_first];
			right_first++;
			iterator++;
	}
	while(iterator>0)
	{
		arr[right_end--]=*(mem+--iterator);

	}
	free(mem);
}

void mergeSort(int arr[],int left,int right)
{
	if(right-left <= 0)
		return ;
	int mid=(left+right)/2;
	mergeSort(arr,left,mid);
	mergeSort(arr,mid+1,right);
	merge(arr,left,mid+1,right);
}

void  printArray(int arr[],int size)
{
	int iterator=0;
	while(iterator<size)
	{
		printf("%d ",arr[iterator++]);
	}
	printf("\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	int inputs[]={25,369,9699,155,1554,69,789,2,1,-259,-4,4125,58,-789,-8955};

	printArray(inputs,sizeof(inputs)/sizeof(int)-1);
	mergeSort(inputs,0,sizeof(inputs)/sizeof(int)-1);
	printArray(inputs,sizeof(inputs)/sizeof(int)-1);
	return 0;
}

