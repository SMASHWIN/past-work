#include <iostream>
#include <stack>
#include <string>
#include <cstring>
using namespace std;

bool check_parentheses_balance(string expr){
	Stack<char> a;
	Stack<char> b;
	Stack<char> c;
	for (int i = 0; i < expr.length(); i++){
		if (expr[i] == '('){
			a.push('(');
		}
		else if (expr[i] == '{'){
			b.push('{');
		}
		else if (expr[i] == '['){
			c.push('[');
		}
		else if (expr[i] == ')'){
			if (a.isEmpty()) return false;
			a.pop();
		}
		else if (expr[i]  == '}'){
			if (b.isEmpty()) return false;
			b.pop();
		}
		else if (expr[i] == ']'){
			if (c.isEmpty()) return false;
			c.pop();
		}

	}
	return true;
}

int main(){
	cout << check_parentheses_balance("(th(e{s)[e(are(bal]an)c)e}d)") << endl;
	cout << check_parentheses_balance("(the{s[e( are (Ba l]an)c)e}d 1@2#)") << endl;
	cout << check_parentheses_balance("th(es)e a[r]e n{o(t} ba)lan]ced") << endl;
	return 0;

}
