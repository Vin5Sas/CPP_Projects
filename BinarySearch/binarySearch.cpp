/*BINARY SEARCH PROGRAM
Recursive Function Approach
Time Complexity: O(log n)
*/
using namespace std;
#include<iostream>
#include<math.h>

int binarySearch(int arr[], int start, int end, int target)
{
    int mid = floor((start+end)/2);                             //calculate mid index value of the incoming array

    if(start>end)                                               //base condition check, if start index is greater than the end index of the array, it means that the target value was not found in the array
        return -1;
    if(arr[mid]==target)                                        //if the value at index 'mid' of the array equals the target value searched for, return the 'mid' index            
        return mid;
    if(arr[mid]>target)                                         //if the value at index 'mid' of the array is greater than the target, then we halve the array with 'mid-1' as the end index of array in the new recursive call 
        return binarySearch(arr,start,mid-1,target);
    else
        return binarySearch(arr,mid+1,end,target);              //else then we consider the right half of the array for further search and pass 'm+1' as start index of the array for the next recursive call
    //return 0;
}

void main()
{
    cout<<"Let's do some Binary Search!\n";

    int target;
    int start = 0;
    int arr[100];
    //int arr[] = {1,2,3,4,5,6,7,8,9};
    int result = 0;
    int arraySize = sizeof(arr) / sizeof(int);                  //size of int is '4' bytes, so an array of 100 elements would occupy 400 bytes, thus 400/4 = 100, which will be the size of the array / count of elements in the array
    int end = arraySize;
    
    cout<<"Size of array  = "<<arraySize<<"\nSize of one element is "<<sizeof(int)<<endl; 

    for(int i=1; i<=100; i++)
    {
    arr[i-1] = i;
    cout<<arr[i-1]<<" ";
    }

    cout<<"\nEnter a target number to find: \n";
    cin>>target;
    result = binarySearch(arr, start, end, target);

    if(result>=0)
        cout<<"The target "<<target<<" was found in the array at index number "<<result;
    else
        cout<<"The given target value was not found"; 
}