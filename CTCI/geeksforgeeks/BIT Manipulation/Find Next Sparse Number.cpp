#include <bits/stdc++.h>
using namespace std;

int find_next_sparse_number(int number){
    vector<int> bits;
    while(number>0){
        bits.push_back(number&1);
        number>>=1;
    }

    bits.push_back(0);
    int n = bits.size();
    int last_pos = 0;
    for(int i = 1;i<n-1;i++){
        if(bits[i-1]==1 && bits[i]==1 && bits[i+1]==0){
            bits[i+1] = 1;
            for(int j = i;j>=last_pos;j--) bits[j]=0;
            last_pos = i+1;
        }
    }
    int ans = 0;
    for(int i= 0;i<n;i++) {
        ans |= (bits[i]<<i);
    }
    return ans;
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        printf("Next Sparse Number: %d\n",find_next_sparse_number(n));

    }
}
