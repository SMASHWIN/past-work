#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char c){
	if (c == '*' || c == '/') return 2;
	else if (c == '+' || c == '-') return 1;
	return 0;

}
void convertToPostfix(string* expression, int size){
	stack<char> Stack;
	string result;
	for(int i = 0; i < size; i++){
		char c = (*expression)[i];
		if (c == '(') Stack.push(c);
		else if (c == ')'){
			while (Stack.top()!= '(' && !Stack.empty()){
				char temp = Stack.top();
				Stack.pop();
				result += temp;
			}
			if(Stack.top() == '('){
				char temp = Stack.top();
				Stack.pop();
			}
		}	
		else if (c == '+' || c == '-' || c == '*' || c== '/'){
			while (!Stack.empty() && precedence(c) <= precedence(Stack.top())){
				char temp = Stack.top();
				Stack.pop();
				result += temp;
			}
			Stack.push(c);	
		}
		else result += c;
	}
	while(!Stack.empty()){
		char temp = Stack.top();
		Stack.pop();
		result += temp;
	}
	cout << result << endl;
}

/*Every operator and operand is pushed and popped onto the stack exactly once
except for the ')', so the Big-O is O(n) */


int main(){
	string exp = "(4 / (3 * 2) + 7)";
	convertToPostfix(&exp, exp.length());
	return 0;
}
