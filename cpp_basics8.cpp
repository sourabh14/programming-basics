/* Template Classes, Standard Template Library (STL)
	Vector, List, Set, Map
*/

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

template <typename T> 
T myMax(T x, T y) {			// Function template - takes arguments of type T and returns T
   return (x > y)? x: y;
}

template <class T>
class NumChar {
	public:
		T key;

		NumChar(T k) {
			key = k;
		}
		
		void display() {
			cout << "key: " << key << endl;
		}
};

void printVector(vector<int> v) {
	printf("vector: ");
	for (int i=0; i<v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void printList(list <int> l) {
	printf("list: ");
	for(auto it= l.begin(); it!= l.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main() {
	/* Template - Generic class/ function. It enables to create a single function or single class to work with different data types using templates.
		-pass data type as a parameter so that we don’t need to write the same code for different data types. 
		-Templates are expanded at compiler time. This is like macros. The difference is, the compiler does type checking before template expansion. 
	*/

	cout << myMax(3, 7) << endl;  			// call myMax for int
  	cout << myMax(3.0, 7.12) << endl; 		// call myMax for double
  	cout << myMax('g', 'e') << endl;   		// call myMax for char
 
 	NumChar<int> nc1(5);
	nc1.display();

	NumChar<char> nc2('c');
	nc2.display();

	/* STL provide common programming data structures and functions such as lists, stacks, arrays, etc. 

		Component: Algorithms, Containers, Functions, Iterators
	*/	

	/* CONTAINERS:
		vector - Dynamic array with ability to resize itself automatically when an element is inserted or deleted
		list - Doubly-linked list
		stack - Adapts a container to provide stack
		queue - Adapts a container to provide queue

		priority_queue - Adapts a container to provide priority queue
		set - Collection of unique keys, sorted by keys
		multiset - Collection of keys, sorted by keys
		map - Collection of key-value pairs, sorted by keys, keys are unique
	*/

	// VECTOR
	vector<int> v1;
	int i;

	for (i=0; i<5; i++) {
		v1.push_back(i+1);
	}
	printVector(v1);

	printf("pop v1\n");
	v1.pop_back();
	printf("pop v1\n");
	v1.pop_back();
	printVector(v1);

	printf("pop v1 from front\n");
	assert(!v1.empty());
    v1.erase(v1.begin());
    printVector(v1);

    v1.clear();
	printVector(v1);


	// LIST - doubly linked list
	list<int> l1;
	for (int i=0; i<10; i++) {
		l1.push_back(i);
	}
	printf("\nList Implementation");
	printList(l1);

	printf("pop from back\n");
	l1.pop_back();
	printList(l1);

	printf("pop from front\n");
	l1.pop_front();
	printList(l1);

	// SET - each element has to be unique
	set<int> s1;

	printf("Insert 40\n"); s1.insert(40);
	printf("Insert 30\n"); s1.insert(30);
    printf("Insert 60\n"); s1.insert(60);
    printf("Insert 20\n"); s1.insert(20);
  	printf("Insert 50\n"); s1.insert(50);
  	printf("Insert 40\n"); s1.insert(40); // wont be inserted
	printf("Insert 90\n"); s1.insert(90);
	printf("Insert 20\n"); s1.insert(20); // wont be inserted
	printf("Insert 30\n"); s1.insert(30); // wont be inserted

	cout << "Set: ";
	for (auto itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;


    // MAP - Each element has a key value and a mapped value. No two mapped values can have same key values.
    //	Faster access of data: Fast access of values of elements through the key.
	//	No duplication of data: Every key is unique in the map so that duplication of data doesn’t exist.

    map<string, string> m;
    m.insert(pair<string, string>("Roses", "Red"));
    m.insert(pair<string, string>("Leaves", "Green"));
    m.insert(pair<string, string>("Sky", "Blue"));

    cout << "Roses are " << m["Roses"] << endl;
    cout << "Sky is " << m["Sky"] << endl;

	return 0;
}
