/*
Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

      1) Insert
      2) Remove
      3) Replace

      input : str1 = "SATURDAY"
              str2 = "SUNDAY"

      output : 3

      reason : Remove A from str1 | STURDAY
               Remove T from str1 | SURDAY
               Replace R with N  | SUNDAY = str2
*/

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b, int c)
{
      return min(min(a,b),c);
}

int ED(string X , string Y , int m , int n)
{
      int i , j , ED[m+1][n+1];

      for(i = 0 ; i <= m ; i++)
      {
            for(j = 0 ; j <= n; j++)
            {
                  if(i == 0)
                        ED[i][j] = j;
                  else if(j == 0)
                        ED[i][j] = i;
                  else if(X[i-1] == Y[j-1])
                        ED[i][j] = ED[i-1][j-1];
                  else
                        ED[i][j] = 1 + min(ED[i-1][j-1] , ED[i-1][j] , ED[i][j-1]);
            }
      }
      return ED[m][n];
}

int main()
{
      string X = "SUNDAY";
      string Y = "SATURDAY";

      int m = X.length() ;
      int n = Y.length() ;

      cout << "The edit distance is: " << ED(X , Y , m , n);

      return 0;
}
