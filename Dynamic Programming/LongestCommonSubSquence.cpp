//Program on c++ to print the longest common sub sequence | DP
/*
  problem:
    input : " A G G T A B "
            " G X T X Y A B"
    output: 4 (G T A B)

    Reason: G T A B are the longest sub sequence which are apperaing in
            same relative order.
*/
#include<bits/stdc++.h>
using namespace std;

int max(int a , int b)
{
      return (a > b)?a:b;
}
int lcs(char arr[] , char arr1[] , int m , int n)
{
      int i, j;

      //creating an array with one size greater then original one
      int L[m+1][n+1];

      //loop to check condition
      for(i = 0; i <= m; i++)
      {
            for(j = 0; j <= n; j++)
            {     //filling the 0th index with zeros
                  if(i == 0 || j == 0)
                        L[i][j] = 0;
                  else if(arr[i - 1] == arr1[j - 1])
                        L[i][j] = 1+L[i-1][j-1]; //adding 1 to the diagonal index of current index value
                  else
                        L[i][j] = max(L[i][j-1], L[i-1][j]); //finding max between [i][j-1] and [i-1][j]
            }
      }
      return L[m][n];
}



int main()
{
      char arr[] = "AGGTAB";
      char arr1[] = "GXTXAYB";

      int m = strlen(arr);
      int n = strlen(arr1);

      cout << "Length of lcs is: " << lcs( arr, arr1, m, n);

      return 0;
}
