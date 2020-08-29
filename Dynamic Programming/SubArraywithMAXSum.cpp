#include<bits/stdc++.h>
using namespace std;

int mini(int a , int b)
{
    return (a > b)? b : a;
}
int resultSub(vector<int> &A)
{
    int n = A.size();
    int result = 0, min ;
    int ans = 0;
    for(int i = 0; i < n - 1; i++)
    {
        if(A[i] > A[i - 1])
        {
            if((A[i]*A[i]) > ans)
            {
                min = A[i];
                result = A[i];
                ans = A[i] * A[i];
            }
            else
            {
                if(ans < (result + A[i])*mini( min , A[i]))
                {
                    min = mini( min , A[i]);
                    result += A[i];
                    ans = result * min;
                }
            }
        }
        else
        {
            if(ans < (result + A[i])*mini(min,A[i]))
            {
                min = mini(min,A[i]);
                result += A[i];
                ans = result * min;
            }
            else
            {
                min = 0;
                result = 0;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    vector<int> A;
    cout << "Enter how many values you need to push \n";
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        A.push_back(num);
    }
    cout << "Ans is: "<<resultSub(A);
    return 0;
}
