#include <iostream>
#include <stack>
using namespace std;

int findCelebrity(int n){
	stack<int>Stack;
	int a;
	int b;
	if (n == 1) return n;
	for (int i = 1; i <= n; i++){
		Stack.push(i);
	}
	while(Stack.size() > 2){
		a = Stack.top();
		Stack.pop();
		b = Stack.top();
		if (knows(a,b)){
			continue;
		}
		else{
			Stack.pop();
			Stack.push(a);
		}
	}
	a = Stack.pop();
	b = Stack.pop();
	if (knows(a,b) && !knows(b,a)) return b;
	else if (knows(b,a) && !knows(a,b)) return a;
	else return -1;	
}
