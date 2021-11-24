/* ABOUT C++
	-Object-Oriented and compiled language - supports the four primary features of OOP: encapsulation, polymorphism, abstraction, and inheritance.
	-Middle-level language: can do both programming low-level (drivers, kernels) and even higher-level applications (games, GUI, desktop apps etc.)
	-Machine Independent but Platform Dependent: A C++ executable is not platform-independent (compiled programs on Linux won’t run on Windows), however they are machine independent.
	-Pointer and direct Memory-Access: C++ provides pointer support which aids users to directly manipulate storage address.
	-Rich library support

	-Applications 
		Operating Systems & Systems Programming. e.g. Linux-based OS (Ubuntu etc.)
		Browsers (Chrome & Firefox)
		Graphics & Game engine
*/

/* Input/output stream, Types of variables,
	Dynamic memory allocation, Strings, References 
*/

#include <iostream>
#include <string>

using namespace std;

class Example {
    static int a; // static variable
    int b;        // instance variable
};
 
int main() {
	cout << "Size of char : " << sizeof(char) << " byte" << endl;
    cout << "Size of int : " << sizeof(int) << " bytes" << endl;

    int age;
    cout << "Enter your age:";
    cin >> age;
    cout << "Your age is: " << age << endl;

    /* TYPES OF VARIABLES
		Local Variables: A variable defined within a block or method
		Instance Variables: Instance variables are non-static variables and are declared in a class 
		Static Variables: Static variables are also known as Class variables. They are declared using the static keyword within a class
	*/

	/* Dynamic memory allocation- memory allocation manually by programmer
		Dynamically allocated memory is allocated on Heap and non-static and local variables get memory allocated on Stack
	*/
	int i;
	cout << "Enter array size: ";
    cin >> i;
	int *p = new int[i];
	cout << "Array: ";
	for (int k=0; k<i; k++) {
		cout << p[k] << " ";
	}
	cout << endl;

	/* STRING */
	string str;
	cout << "Enter string: ";
	getline (cin, str);
	cout << "The initial string is : " << str << endl;

	/* References - alternative name for an existing variable*/
	int x = 10;
  	// ref is a reference to x.
  	int &ref = x;
  	// Value of x is now changed to 20
  	ref = 20;
  	cout << "x = " << x << endl ;

	return 0;
}