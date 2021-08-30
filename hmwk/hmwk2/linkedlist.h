class DoubleLinkedList
{
	public:
	//Implement ALL following methods.
	//Constructor.
	DoubleLinkedList();
	//Copy constructor.
	DoubleLinkedList(const DoubleLinkedList & rhs);
	//Destructor. Clear all nodes.
	~DoubleLinkedList();
	// Insert function. Returns true if item is inserted,
	// false if the item it a duplicate value
	bool insert(int x);
	// Removes the first occurrence of x from the list,
	// If x is not found, the list remains unchanged.
	void remove(int x);
	//Assignment operator.
	const DoubleLinkedList& operator=(const DoubleLinkedList & rhs);
	private:
	struct node{
		int data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
};
