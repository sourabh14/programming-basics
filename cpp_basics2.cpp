/* Object Oriented Programming (OOP)
	-programming paradigm built on the concept of objects, that contain both data and code to modify the data. 
	-Object-oriented programming mimics a lot of the real-world attributes of objects. 
	-organizes software design around data, or objects, rather than functions and logic.

Structure of OOP
	-Classes: are user-defined data types that act as the blueprint for individual objects, attributes and methods.
	-Objects: are instances of a class 
	-Methods: are functions that are defined inside a class that describe the behaviors of an object. 
	-Attributes: are defined in the class template and represent the state of an object.

Principles of OOP
	-Encapsulation: binding together the data and the functions that manipulate them. 
		|-Objects comprise data that define its state and methods that define its behavior. 
		|-Each object encapsulates these two entities. A class is an example of encapsulation. Eg: car encapsulates mechanism for filling fuel tank, starting the car, moving steering wheel.
		|-Data hiding: It's also a mechanism of restricting the direct access to some components of an object, such that users cannot access state values for all of the variables of a particular object. Eg: users cannot view internal working of an engine 

	-Abstraction: means displaying only essential information and hiding the details. 
		|-The internal implementation of object methods is invisible to the user. 
		Eg: internal working of engine of car is not known. 
	
	-Inheritence:  The capability of a class to derive properties and characteristics from another class 


	-Polymorphism: means having many forms. 
		Eg: man at the same time is a father, a husband, an employee
		|-An operation may exhibit different behaviours in different instances. The behaviour depends upon the types of data used in the operation.
		|-C++ supports operator overloading and function overloading.
			Operator Overloading: The process of making an operator to exhibit different behaviours in different instances is known as operator overloading.
			Function Overloading: Function overloading is using a single function name to perform different types of tasks.
		|-Polymorphism is extensively used in implementing inheritance.
		|-Eg: Suppose we have to write a function to add some integers, some times there are 2 integers, some times there are 3 integers. We can write the Addition Method with the same name having different parameters, the concerned method will be called according to parameters. 
			int sum(int a, int b) and int sum(int a, int b, int c)

	-Message Passing: Objects communicate with one another by sending and receiving messages. A message for an object is a request for execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results.
		Eg: We cannot directly start engine. We must do it through keys, i.e. through proper channel.
		|- A message for an object is a request for execution of a procedure and therefore will invoke a function in the receiving object that generates the desired results

	-Dynamic Binding: In dynamic binding, the code to be executed in response to function call is decided at runtime. 		|-C++ has virtual functions to support this.

Benefits of OOP
	-Modularity - Encapsulation enables objects to be self-contained,
	-Reusability - Code can be reused through inheritance,
	-Easily upgradable and scalable. Programmers can implement system functionalities independently.
	-Flexibility. Polymorphism enables a single function to adapt to the class it is placed in. Different objects can also pass through the same interface.
	-Security. Using encapsulation and abstraction, complex code is hidden, software maintenance is easier 
*/

