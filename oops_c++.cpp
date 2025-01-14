#include<bits/stdc++.h>

using namespace std;
//Starting oops concepts from here
//this is the basic syntax to declare a class
class Teacher{
//We can make the salary as private and other as the public by using the private keyword 
private:
	double salary;//now the salary is private and other properties are public we can not access the salary outside the class
	//Basically this is data hiding

public: // This is the access modifiers in the oops and in c++ it is by default private we have to use public
	    //keyword to access the properties in the code or outside the class 
	//Properties
	string name;
	string department;
	string subject;
	double* cgpaPtr;

	Teacher(){ // This is basicallly a constructor of Teacher class and it is non-parameterised
		cout << "Hi, I am your constructor" << "\n";
		department = "Computer science";// By default it set the department value as computer science we dont need to set value again and again
	}

	Teacher(string name, string department, string subject, double salary, double cgpa){ //This is parameterised constructor
		// Property name = parameter name
		this->name = name;
		this->department = department;
		this->subject = subject;
		this->salary = salary;
		*cgpaPtr = new float;
		*cgpaPtr = cgpa;
	}

	//copy constructor
	Teacher(Teacher &obj){ // pass by refrence
		cout << "I am custom copy constructor";
		this->name = obj.name;
		this->department = obj.department;
		this->subject = obj.subject;
		this->salary = obj.salary;
		this.cgpaPtr = obj.cgpaPtr;//this is basically a shallow copy
		cgpaPtr = new double;
		*cgpaPtr = *obj.cgpaPtr;//above 2 lines make the deep copy of the constructor and make a copy of allocated memory

	}

	//Destructor
	~Teacher(){
		cout << "Hie, i am destructor";
		delete cgpaPtr;
	}


	//Methods => basically method is a function which is in the class not outside the class
	//Methods are also called the member function in c++
	//This function takes the parameter as new dept and set the old dept as new dept
	void change_dept(string newDept){
		department = newDept;
	}
	/*
	If we want to get the salary which is private we use setter and getter in the concept
	Basically we will derive 2 functions one is setSalary and other is get salary in the public

	*/
	void setSalary(double s){
		salary = s;
	}
	double getSalary(){
		return salary;
	}
	void getInfo(){
		cout << "Name" << name;
		cout << "Department" << department;
		cout << "CGPA" << *cgpaPtr;
	}

};


int main(){
	//To create an object in the make function firstly write the name of the class which is "Teacher" and then object name
	Teacher T1; //Constructor call
	//Here the t1 got the following properties as name, dept, subject and salary
	//to access the name of the object we use . operator like
	T1.name = "Girish";//This means we are accessing the name property of T1 object
	T1.department; 
	T1.setSalary(25000);
	T1.getSalary();
	//To access method we will simply do
	cout << T1.name << "\n";
	cout << T1.getSalary() << "\n";

	Teacher T2("Girish", "Computer science", "C++",  25909);
	T2.getInfo();

	Teacher T3(T2);//copy constructor copy the properties of T2 in T3;

	T3.getInfo();
	return 0;
}