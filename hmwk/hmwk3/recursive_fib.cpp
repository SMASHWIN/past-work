#include <iostream>

using namespace std;

int fib(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return fib(n-1) + fib(n-2);
}

void fibHelper(int first, int second, int final){
	if (second == final){
		cout << endl;
		return;
	}
	int result = first + second;
	cout << result << " ";
	fibHelper(second, result, final);
}
void printFibNumbers(int N, int M){
	if (M < N) return;
	int initial = fib(N);
	if (M == N){
		cout << initial << " ";
		return;
	}
	int second = fib(N+1);
	int last = fib(M);
	cout << initial << " ";
	cout << second << " ";
	fibHelper(initial,second,last);
	return;
	
	
}

int main(){
	printFibNumbers(0,4);
	printFibNumbers(1,7);
	printFibNumbers(7,13);
	return 0;
}
