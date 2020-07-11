/*
  This is one of the famouse algorithm of DP
  in this there will be given array with values and thier weight.
  we have to calulate the max value sum we can put in a bag with
  given weight W

  eg: input: valuep[] = { 60, 100, 120}
             weight[] = { 10, 20, 30}
             W = 50 // max weight hold by a bag

      output: 220

      reason: 30 + 20 <= 50 and thier respective value is 100 + 120 = 220.
*/

#include<bits/stdc++.h>
using namespace std;

int max(int a , int b)
{
      return (a > b)? a : b;
}

int knapsack(int w, int val[] , int wt[], int n)
{
      int temp[n+1][w+1];
      int i , j;

      for(i = 0 ; i <= n; i++)
      {
            for(j = 0; j <= w; j++)
            {
                  if(i == 0 || j == 0)
                         temp[i][j] = 0;
                  else if(j >= wt[i - 1])
                        temp[i][j] = max(temp[i - 1][j], val[i - 1] + temp[i - 1][j - wt[i - 1]]);
                  else
                        temp[i][j] = temp[i - 1][j];
            }
      }
      return temp[n][w];
}

int main()
{
      int val[] = { 60, 100, 120 };
      int wt[] = { 10, 20, 30};

      int w = 50;
      int n = sizeof(val)/sizeof(val[0]);

      cout << knapsack(w, val, wt, n);

      return 0;
}
