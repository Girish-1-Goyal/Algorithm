#include<bits/stdc++.h>

using namespace std;

/*
in inheritance firstly parent class constructor is called then  the child class constructor is called this is only
for if the constructor is non parameterised

and for parameterised constructor we use different method


*/

class Person{
public:
	string name;
	int age;
	Person(string name, int age){
		this->name = name;
		this->age = age;
	}

	Person(){
		cout << "hie i am constructor of parent class";
	}
};

class Student : public Person{ //this student class inherit all the properties from the person class publicly
public:
	int rollNo;

	Student(){
		cout << "hie i am the constructor of base class";//this is for if the constructor is non  parameterised
	}

	Student(string name, int age, int rollNo) : Person(name, age){
		cout << "this is the constructor for the parameterised class";//this is for if the constructor is parameterised
		this->rollNo = rollNo;
	}
	void getInfo(){
		cout << name;
		cout << age;
		cout << rollNo;
	}
};

int main(){
	Student s1("Girish", 24, 1001);
	s1.getInfo();
	return 0;
}

/*
if we want to do a multiple inheritance 

we have 2 parent class and a child class


This is the syntax of the class
class child_name : public ParentClass1, public ParentClass2{};




*/