class Bag{
private:
 	int** container;
 	int size;
public:
 	Bag(int* nums, int size){
 		this->size = size;
 		container = new int*[size];
 		for(int i = 0; i < size; i++){
 			container[i] = new int(nums[i]);
 		}
 	}
	Bag& operator=(Bag& b){
		for (int i = 0; i < size; i++){
			delete container[i];
		}
		delete container;
		size = b.size;
		container = new int*[size];
 		for(int i = 0; i < size; i++){
			container[i] = new int(*(b.container[i]));
 		}
 		return *this;
 	}
	~Bag(){
		for (int i = 0; i < size; i++){
			delete container[i];
		}
		delete container;
	}
	
};

Q1:
There will be a memory leak. Before deleting container, you have to delete all the individual pointers created in the container
array. Only then can you delete container.
Additionally, this->container[i] points to the same place as b.container[i], so if b.container[i] is later modified, that would also change the container
Q2: (Implemented above)

Q3: (Implemented above)
