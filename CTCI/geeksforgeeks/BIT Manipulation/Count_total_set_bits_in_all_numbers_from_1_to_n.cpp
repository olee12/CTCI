/*
 * Count_total_set_bits_in_all_numbers_from_1_to_n.cpp
 *
 *  Created on: May 2, 2017
 *      Author: Tahmidolee
 */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pli;
const int maxn = 35;
pli dp[maxn];
int num[maxn];

pli rec(int pos, int flag) {
	if (pos == 0)
		return make_pair(0ll, 1);

	pli &ret = dp[pos];
	if (flag && ret.first != -1)
		return ret;

	int start = 0;
	int end = flag ? 1 : num[pos];

	pli now;
	now.first = now.second = 0;
	for (int i = start; i <= end; i++) {
		pli tmp = rec(pos - 1, flag || i<end);
		now.first+= tmp.second*i + tmp.first;
		now.second+= tmp.second;
	}
	if(flag) ret = now;
	return now;
}

long long solve(int n) {
	int len = 0;
	while (n > 0) {
		num[++len] = n & 1;
		n >>= 1;
	}
	return rec(len,0).first;
}


int leftMostBits(int n){
	if(n==0) return 0;
	int m = 0;
	while(n>0){
		n>>=1;
		m++;
	}
	return m-1;
}

long long count_set_bit(int n){
	if(n==0) return 0;
	int m = leftMostBits(n);

	if(n == (1<<(m+1)) - 1)
		return ((long long)(m+1) * (1<<(m)));

	n = n - (1<<(m));

	return (n+1)  + ((long long)(m) * (1<<(m-1))) + count_set_bit(n);

}


int main(int argc, char **argv) {
	//freopen("C:\\Users\\Tahmidolee\\workspace\\MyCodes\\Debug\\inp.txt","r",stdin);
	int n;
	memset(dp,-1,sizeof(dp));
	while (scanf("%d", &n) == 1) {
		printf("Number of set bit : %lld %lld\n",solve(n),count_set_bit(n));
	}
	return 0;
}

