#include <bits/stdc++.h>
using namespace std;

int maximumPathSum(int *ar1,int *ar2,int m,int n)
{
    int i = 0,j = 0;
    int sum1 = 0;
    int sum2 = 0;
    int ret = 0;

    while(i < m && j < n){
        if(ar1[i]<ar2[j]) sum1+=ar1[i++];
        else if(ar1[i]>ar2[j]) sum2+=ar2[j++];
        else{
            ret += max(sum1,sum2);
            sum1 = sum2 = 0;
            while(i<m && j<m &&ar1[i]==ar2[j]){
                ret+= ar1[i++];
                j++;
            }
        }
    }
    while(i<m) sum1+=ar1[i++];
    while(j<n) sum2+=ar2[j++];
    ret+=max(sum1,sum2);
    return ret;
}

int main()
{
      int ar1[]  = {2, 3, 7, 10, 12, 15, 30, 34};
    int ar2[] =  {1, 5, 7, 8, 10, 15, 16, 19};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    cout << "Maximum sum path is "
         << maximumPathSum(ar1, ar2, m, n);
    return 0;


}
