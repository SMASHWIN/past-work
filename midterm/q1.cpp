Do we need to implement the copy constructor or does the default suffice?

A: The default does NOT suffice. Each Roster instance contains two pointers as its private variables. The default copy constructor will shallow copy those pointers, making the pointers of both instances (the initial and the copy) point to the same thing when they should point to the same value, not the same address.

Copy constructor:

Roster::Roster(const Roster& r){
	Node* temp = r.head;
	head = new Node(r.head->employee);
	tail = head;
	while (temp != r.tail){
		temp = temp->next;
		this->insert(temp->employee);
	}
}

bool Roster::operator==(const Roster& r){
	Node* temp = this->head;
	Node* temp2 = r.head;
	while (temp != NULL && temp2 != NULL){
		if (!(temp->employee == temp2->employee)){
			return false;
		}
		temp = temp->next;
		temp2 = temp2->next;
	}
	if (temp == NULL && temp2 == NULL) return true;
	return false;
}
