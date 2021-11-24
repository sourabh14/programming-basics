/* Classes and Objects - C++ 11  */

#include <iostream>
#include <string>

using namespace std;
 
class Employee {
    public:							// Access specifier: can be public, private or protected
    	string name;				// Data members
    	int id;

	public:				
    	void getdetails() {			// Member functions
    		cout << name + " " + to_string(id) << endl;
    	}							
    	void getid();
};

// Member functions can be defined outside the class, using scope resolution operator ::
void Employee::getid() {						
	cout << "Id is: " << id << endl;			
}

int main() {
	Employee e1; 
	/* When a class is defined, no memory is allocated but when it is instantiated (i.e. an object is created) memory is allocated. */

	e1.name = "empl1";
	e1.id = 1001;

	e1.getdetails();
	e1.getid();		// member functions defined inside the class definition are by default inline
					// Inline functions are copied everywhere during compilation, like pre-processor // macro, so the overhead of function calling is reduced.

	/* Note: In C++ the only difference between a class and a struct is that members and base classes are private by default in classes, whereas they are public by default in structs.
	So structs can have constructors, and the syntax is the same as for classes.*/
	
	return 0;
}