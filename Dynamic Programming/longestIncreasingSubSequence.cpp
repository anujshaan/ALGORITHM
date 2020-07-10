/*
This is second problem from TOP 20 Dynamic Programming list.
Problem is to find the length of the longest sub sequence of
the given sequence.

    input: {3 , 10 , 2 , 1 , 20}
    output: 3

    reason: 3 ,10 ,20 is the only possible sub sequence or subset of array in
          increasing order.
*/
#include<bits/stdc++.h>
using namespace std;

int lis(int arr[], int n)
{
      int i,j;

      //creating array of size n
      int lis[n];
      lis[0] = 1;

      //loop to starting from 1 because we have to compare ith index with previous one i.e jth
      //also in i loop we are giving every index value as 1 because in start every
      //sequence is atleast 1 long
      for(i = 1; i < n; i++)
      {
            lis[i] = 1;
            for(j = 0; j < i; j++)
            {
                  //here we are comparing two index value
                  if(arr[i] > arr[j] && lis[i] < lis[j]+1)
                  {
                        //here we are adding jth value with 1 in ith index
                        lis[i] = lis[j] + 1;
                  }
            }
      }
      return *max_element(lis , lis + n);
}

int main()
{
      int arr[] = {10,22,9,33,21,50,41,60};
      int n = sizeof(arr) / sizeof(arr[0]);

      cout << "longest list in order are : " << lis(arr,n);

      return 0;
}
