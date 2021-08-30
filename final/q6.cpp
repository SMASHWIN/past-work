#include <iostream>
#include <math.h>
using namespace std;


bool checkEqualHelper(int a[], int b[], int size, int idx_a, int idx_b, int min, int max){
	int i = idx_a;
	int j = idx_b;
	while(i < size){
		if (a[i] > min && a[i] < max) break;
		i++;
	}
	while(j < size){
		if (b[j] > min && b[j] < max) break;
		j++;
	}
	if (i == size && j == size) return true;
	if (a[i] != b[j]) return false;
	if (((i == size) && (j != size)) || ((i != size) && (j == size))) return false;
	return checkEqualHelper(a,b,size, i+1, j+1, a[i], max) && checkEqaulHelper(a,b,size, i+1, j+1, min, a[j]);
}

bool checkEqual(int a[], int b[]){
	int a_size = sizeof(a)/sizeof(a[0]);
	int b_size = sizeof(b)/sizeof(b[0]);
	if (a_size != b_size) return false;
	if (a[0] != b[0]){
		return false;
	}
	if (a_size == 1) return true;
	return checkEqualHelper(a,b, a_size, 1,1, -2147483647, a[0]) && checkEqualHelper(a,b, a_size, 1,1, a[0], 21474836487);
}

