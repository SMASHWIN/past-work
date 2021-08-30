#include <iostream>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

Queue<ValueType> iterative_reverse(Queue<ValueType> q){
	stack<ValueType> Stack;

	while (!q.isEmpty()){
		Stack.push(q.peek());
		q.dequeue();
	}
	while (!Stack.isEmpty()){
		q.enqueue(Stack.peek());
		Stack.pop();
	}
	return q;
}


Queue<ValueType> recursive_reverse(Queue<ValueType> q){
	if (q.isEmpty()){
		return q;
	}
	ValueType first = q.peek();
	q.dequeue();
	q = recursive_reverse(q);
	q.enqueue(first);
	return q;
}
/*
Only used for testing (using built in queue)
int main(){
	queue<int> Queue;
	Queue.push(10); 
   	Queue.push(20); 
    	Queue.push(30); 
    	Queue.push(40); 
    	Queue.push(50); 
    	Queue.push(60); 
    	Queue.push(70); 
    	Queue.push(80); 
    	Queue.push(90); 
    	Queue.push(100);
	queue<int> reverse = recursive_reverse(Queue); 
	while (!reverse.empty()){
		cout << reverse.front() << " ";
		reverse.pop();
	}
	return 0;
  
}
*/
