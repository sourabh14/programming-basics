/* 	Constructors, Destructors, Access Modifiers
*/

#include <iostream>
#include <string>

using namespace std;
 
class Employee {										// Parent class or Base class
    public:							
    	string name;
    	int id;

	public:				
		Employee() {									// Default Constructor
			name = "default_name";
			id = 1000;
			cout << "Default Constructor called" << endl;
		}

		Employee(string s, int i) {						// Parameterized Constructor
			name = s;
			id = i;
			cout << "Parameterized Constructor called" << endl;
		}

		~Employee() {									// Destructor - no argument, no return type
			cout << "Destructor called for " << id << endl;
		}

    	void getdetails() {			
    		cout << name + " " + to_string(id) << endl;
    	}							
};

class Test {
	public:
		string name;
	private:
		int id;

	public:
	void setid(int i) {
		id = i;
	}
	void disp() {
		cout << "Name: " << name << endl;
		cout << "Id: " << id << endl;
	}
};


//---------------------------------------------------------------------


int main() {
	Employee e1, e2("random", 1999), e3; 
	e3 = Employee(e2);
	/* CONSTRUCTORS - called by the compiler every time an object of that class is instantiated. 
		-Constructors have the same name as the class and may be defined inside or outside the class.
		-There are 3 types of constructors:
			1. Default constructors
			2. Parameterized constructors
			3. Copy constructors- Copy Constructor creates a new object, which is exact copy of the existing object. The compiler provides a default Copy Constructor to all the classes
	*/
	e1.getdetails();
	e2.getdetails();
	e3.getdetails();

	/* DESTRUCTORS- called by the compiler when the scope of the object ends.*/

	/* ACCESS MODIFIERS - used to assign the accessibility to the class members
		Encapsulation can be implemented using Class and access modifiers.
    	By default the access modifier for the members will be Private.
    	Three types: 
    		-Public - available to everyone, can be accessed by other classes and functions too
			
			-Private - class members declared as private can be accessed only by the member functions inside the class. They are not allowed to be accessed directly by any object or function outside the class. Only the member functions or the friend functions are allowed to access the private data members of a class. 
			
			-Protected - similar to private access modifier in the sense that it can’t be accessed outside of it’s class unless with the help of friend class, the difference is that the class members declared as Protected can be accessed by any subclass(derived class) of that class as well. 
	*/
	Test t1;
	t1.name = "hello";
	t1.setid(1000);
	t1.disp();

	return 0;
} 
// Scope for e1,e2,e3 ends here