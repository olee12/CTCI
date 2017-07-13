/*
 * BitRotation.cpp
 *
 *  Created on: May 2, 2017
 *      Author: Tahmidolee
 */

#include <bits/stdc++.h>
using namespace std;
const int INT_BIT = 32;

int leftRotate(int n,int m)
{
   // printf("%d %d\n",(n << m) , (n>>(INT_BIT - m )));
	return (n << m) | (n>>(INT_BIT - m ));
}

int rightRotate(int n,int m){

	return (n >> m) | (n << (INT_BIT-m));

}


int main(int argc, char **argv) {

	int n,m;
	while(scanf("%d %d",&n,&m)==2){
		printf("Left Rotate : %d\nRight Rotate %d\n",leftRotate(n,m),rightRotate(n,m));

	}
}




