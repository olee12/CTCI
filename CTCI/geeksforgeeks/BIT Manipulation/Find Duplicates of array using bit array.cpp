#include <bits/stdc++.h>
using namespace std;
const int maxn = 32000+5;

int flag[maxn];

void set_bit(int pos)
{
    int indx = pos / 32;
    int bit = pos % 32;

    flag[indx] |= (1<<bit);

}

bool get_bit(int pos){
    int indx = pos>>5;
    int bit = pos & 31;
   // printf(" [%d %d %d] ",pos,indx,bit);
    return (flag[indx] & (1<<bit))!=0;

}



int main(){
    int ara[] = {10,1,2,52,4,1,35,2,621,2,621,525,121,32,32,11,991,971,100,92,100,10};
    int n = sizeof(ara)/sizeof(int);
   // printf("%d\n",n);
    for(int i = 0;i<n;i++){
        if(get_bit(ara[i])){
            printf("%d ",ara[i]);
        }else set_bit(ara[i]);
    }
    return 0;
}
