#include <iostream>
using namespace std;

template <class T>
class dnode{
public:
	T data_field;
	dnode<T>* next;
	dnode<T>* prev;

	dnode(T &data, dnode* n = NULL, dnode*p = NULL): data_field(data), next(n), prev(p){};
	~dnode() {if (next != NULL) next = nullptr; if(prev != NULL) prev = nullptr;}; 
	T& getData() {return data_field;};
	dnode<T>* getNext() { return next;};
	dnode<T>* getPrev() {return prev;};	
	void setPrev(dnode<T>* p){prev = p;};
	void setNext(dnode<T>* d){next = d;};
	void insertNode(dnode<T>* before, dnode<T>* after){
		next = after;
		prev = before;
	};
};
