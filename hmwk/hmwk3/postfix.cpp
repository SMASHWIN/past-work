#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

double operation(double first, double second, string op){
	if (op.compare("+") == 0) return first + second;
	if (op.compare("-") == 0) return first - second;
	if (op.compare("*") == 0) return first*second;
	if (op.compare("/") == 0) return first/second;
	return -1;
}
double evaluate(string expr){
	stack<string> Stack;
	string curr = "";
	for (int i = 0; i < expr.length(); i++){
		string c;	
		if (i == expr.length() - 1){
			curr += expr[i];
			c = curr;
		}	
		else if (expr[i] != ' '){
			curr += expr[i];
			continue;
		}
		else{
			c = curr;
			curr = "";
		}
		
		if ((c.compare("+") == 0) || (c.compare("-") == 0) || (c.compare("*") == 0) || (c.compare("/") == 0)){
			double a = stod(Stack.top());
			Stack.pop();
			double b = stod(Stack.top());
			Stack.pop();
			double result = operation(b, a, c);
			Stack.push(to_string(result));
		}
		else{
			Stack.push(c);
		}
	}
	double result = stod(Stack.top());
	return result;
}

int main(){
	string expression;
	while (true){
		cout << "Enter an expression (or type 'end' to exit)" << endl;
		getline(cin, expression);
		if (expression.compare("end") == 0) break;
		double result = evaluate(expression);
		cout << "The result is: " << result << endl;	
	}
	return 0;
}
