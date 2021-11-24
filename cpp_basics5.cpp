/* 	Inheritence, Polymorphism 	
*/

#include <iostream>
#include <string>

using namespace std;
 

//---------------------------------------------------------------------

class Employee {	

};

class Engineer : public Employee {				// Sub class or derived class
    public:
      enum specialization {webDevt, dataScience, devOps};
};

class Manager : public Employee {				
    public:
      int nSubordinates;
};

//---------------------------------------------------------------------

class A {									// Inheritence - Public, Private and Protected
	public:
    	int x;
	protected:
	    int y;
	private:
	    int z;
};
 
class B : public A {
    // x is public
    // y is protected
    // z is not accessible from B
};
 
class C : protected A {
    // x is protected
    // y is protected
    // z is not accessible from C
};
 
class D : private A {    // 'private' is default for classes
    // x is private
    // y is private
    // z is not accessible from D
};

//---------------------------------------------------------------------

class E : public B, public C {				// multiple inheritence

};

//---------------------------------------------------------------------


class P {									// Diamond problem and virtual inheritence
	public:
    	int x;

    	void printhello() {
    		cout << "hello\n";
    	}
};
 
class Q : virtual public P {				
};
 
class R : virtual public P {
};

class S : public Q, public R {
};

//---------------------------------------------------------------------


class Complex {
	public:
		int real, img;

	public:
		Complex() {
			real = 0; img = 0;
		}
		Complex(int a, int b) {
			real = a;
			img = b;
		}
		int sum(int x, int y) {					// Compile time Polymorphism - function overloading
			return x+y;
		}
		int sum(int x, int y, int z) {
			return x+y+z;
		}

		Complex operator + (Complex c1) { 		// operator overloading by Operator functions
			Complex ret; 
			ret.real = c1.real + real;
			ret.img = c1.img + img;
			return ret;
		}
};

//---------------------------------------------------------------------

class Base {									// Run time polymorphism - virtual functions
	public:
	    void virtual print () { 
	    	cout<< "print base class" << endl; 
	    }
	   
	    void show () { 
	    	cout<< "show base class" << endl; 
	    }
};
   
class Derived: public Base {
	public:
	    void print () 				//print () is already virtual function in derived class, we could also declared
	    { 							//as virtual void print () explicitly
	    	cout<< "print derived class" <<endl; 
	    }
	   
	    void show () { 
	    	cout<< "show derived class" <<endl; 
	    }
};


int main() {
	/*INHERITENCE - capability of a class to derive properties and characteristics from another class
		|-Sub Class: The class that inherits properties from another class is called Sub class or Derived Class.
		|-Super Class:The class whose properties are inherited by sub class is called Base Class or Super class.
		|-Reusability: Inheritance supports the concept of “reusability”, 
		Benefits:
			-increases reusability, avoids duplication	
			-decreases chances of error

		Modes of Inheritance
			-Public mode: public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class.
			-Protected mode: both public member and protected members of the base class will become protected in derived class
			-Private mode: both public member and protected members of the base class will become Private in derived class. 
			-Private members in the base class cannot be directly accessed in the derived class, while protected members can be directly accessed.

		Types of Inheritence
			-Single inheritence
			-Multiple inheritence - class can inherit from more than one classes. 
			-Multilevel Inheritance: A derives B derives C

	*/
	S s1;
	s1.printhello();
	/* Diamond Problem and Virtual inheritence
		From above example we can see that “x” is inherited two times in S means an object of class “S” will contain two attributes of “x” (S::Q::x and S::R::x).
		This problem is also known as diamond problem. It is solved through virtual inheritence. When we use virtual inheritance, we are guaranteed to get only a single instance of the common base class. 
	*/

	/* POLYMORPHISM
		Types:
			1. Compile time Polymorphism - 
				-Function overloadingm - multiple functions with same name but different parameters 
				-Operator overloading
			2. Runtime Polymorphism - achieved by Function Overriding. Function overriding occurs when a derived class has a definition for one of the member functions of the base class. That base function is said to be overridden.
				It is achieved through virtual functions
	*/
	Complex m1;
	int sm1 = m1.sum(2,3);
	int sm2 = m1.sum(2,3,4);

	cout << "sm1 : " + to_string(sm1) + " sm2 : " + to_string(sm2) << endl;

	Complex m2 = Complex(3,4);
	Complex m3 = Complex(5,6);
	Complex m4;
	m4 = m2 + m3;

	cout << "m4 : " << m4.real << " " << m4.img << endl;

	Base *bptr;
    Derived d;
    bptr = &d;
       
    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print(); 
    // Non-virtual function, binded at compile time
    bptr->show(); 
	
	return 0;
}