/* 	Exception handling	
*/

#include <iostream>
#include <string>

using namespace std;
 
// This function signature is fine by the compiler, but not recommended.
// Ideally, the function should specify all uncaught exceptions and function
// signature should be- "void fun(int *ptr, int x) throw (int *, int)"
void fun(int *ptr, int x) {
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}

void fun2(int *ptr, int x) throw (int *, int) { 	// this is better
    if (ptr == NULL)
        throw ptr;
    if (x == 0)
        throw x;
    /* Some functionality */
}

class Base {};

class Derived: public Base {};


class Test {
	public:
  		Test() { cout << "Constructing an object of Test " << endl; }
  		~Test() { cout << "Destructing an object of Test "  << endl; }
};

int main() {
	/* EXCEPTIONS - run-time anomalies. When an error occurs, C++ will normally stop and generate an error message. The technical term for this is: C++ will throw an exception (throw an error).
		-Two types of exceptions: a)Synchronous, b)Asynchronous (Ex:which are beyond the program’s control, Disc failure etc). 

	EXCEPTION HANDLING - C++ provides following specialized keywords for this purpose.
		-try: represents a block of code that can throw an exception. It allows you to define a block of code to be tested for errors while it is being executed.
		-catch: represents a block of code that is executed when a particular exception is thrown.
			There is a special catch block called ‘catch all’ catch(…) that can be used to catch all types of exceptions.
			If an exception is thrown and not caught anywhere, the program terminates abnormally.
		-throw: Used to throw an exception. It throws an exception when a problem is detected, which lets us create a custom error. Also used to list the exceptions that a function throws, but doesn’t handle itself.

	Why Exception Handling? 
		- Separation of Error Handling code from Normal Code
		- Functions/Methods can handle any exceptions they choose: A function can throw many exceptions, but may choose to handle some of them. The other exceptions which are thrown, but not caught can be handled by caller If the caller chooses not to catch them, then the exceptions are handled by caller of the caller. 

		In C++, a function can specify the exceptions that it throws using the throw keyword. The caller of this function must handle the exception in some way (either by specifying it again or catching it)
		
		- Grouping of Error Types: In C++, both basic types and objects can be thrown as exception. We can create a hierarchy of exception objects, group exceptions in namespaces or classes, categorize them according to types

	*/

	int x = -1;
 
	cout << "Before try \n";
	try {
		cout << "Inside try \n";
		if (x < 0) {
			throw x;
	 		cout << "After throw (Never executed) \n";
		}
	}
	catch (int x) {
		cout << "Exception Caught \n";
	}

	cout << "After catch (Will be executed) \n\n";

	// Catch all block
	try  {
       throw 10;
    }
    catch (char *excp)  {
        cout << "Caught " << excp;
    }
    catch (...)  {
        cout << "Default Exception\n";
    }

    /* Checked vs Unchecked exceptions
    	- Unlike Java, in C++, all exceptions are unchecked. Compiler doesn’t check whether an exception is caught or not. For example, in C++, it is not necessary to specify all uncaught exceptions in a function declaration. Although it’s a recommended practice to do so.

	*/
    try {
       fun(NULL, 0);
    }
    catch(...) {
        cout << "Caught exception from fun()\n\n";
    }

    /* Stack unwinding - if exception is not handled in same function (where it is thrown)
    	The process of removing function entries from function call stack at run time is called Stack Unwinding. Stack Unwinding is generally related to Exception Handling. In C++, when an exception occurs, the function call stack is linearly searched for the exception handler, and all the entries before the function with exception handler are removed from the function call stack. So exception handling involves Stack Unwinding if exception is not handled in same function (where it is thrown).

    	For more details: https://www.geeksforgeeks.org/stack-unwinding-in-c/
	*/

    /* Catching base and derived classes as exceptions
  		-If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class. If we put base class first then the derived class catch block will never be reached. 
	*/

  	try {
  		Base b;
  		Derived d;
  		throw d;
  	}
  	catch (Base bb) {					// compiler gives warning but not an error
  		cout << "Caught base\n";		
  	}
  	catch (Derived dd) {				// this catch is not reachable. It should be placed before
  		cout << "Caught derived\n";
  	}

  	/* Exception handling and object destruction
  		- When an exception is thrown, destructors of the objects (whose scope ends with the try block) is automatically called before the catch block gets exectuted.
	*/
  	
  	try {
  		Test t;
  		throw 10;
  	} 
  	catch (int i) {
  		cout << "Caught " << i << endl;
  	}

  	/* Destructors are only called for the completely constructed objects. When constructor of an object throws an exception, destructor for that object is not called. */


	return 0;
}