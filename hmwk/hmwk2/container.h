#ifndef CONTAINER_H
#define CONTAINER_H
using namespace std;
class container
{
	public:
	// CONSTRUCTOR
	container();
	~container();
	container(const container& c);
	container& operator=(const container& c);
	// MEMBER FUNCTIONS
	bool lookup(const int& target);
	void remove(const int& target);
	void add(const int& target);
	private:
	struct node{
		int key;
		node *next;
	};
	node* head;
	node* tail;
};
#endif
