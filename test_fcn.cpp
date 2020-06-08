//#include "stdafx.h"
#include <iostream> 
#include <string>
#include <cstring>
using namespace std;

class animal //base class
{
public:
	char* getname(); 	    //getter functions
	int getage(); 
	
	void setage(int a); 	//setter functions
	void setname(char* n);

	virtual void speak(); 	//speak (virtual)
	virtual void action(); 	//action (virtual)
	
	void birthday(); 	    //birthday
	void introduce(); 	    //introduce
	
	animal();
	animal(char* name, int age);
	~animal();
protected:
    char name[25]; 
	int age;
};

//setting classes for animals using base class
class dog : public animal 
{ 	virtual void speak();
};

class cat : public animal
{    virtual void speak();
};

class straydog : public dog
{	 virtual void speak();
	 virtual void action();
};

class petdog : public dog
{	 virtual void action();
};


//Get Functions 
char* animal::getname()
{	return name;}
int animal::getage()
{	return age;}


//Set Functions
void animal::setname(char* n)
{	strcpy(name, n);}
void animal::setage(int a)
{	age = a;}


//BIRTHDAY function 
void animal::birthday() //adds +1 to age
{	age++;}

//INTRODUCE function 
void animal::introduce() //just a message
{	cout << "Hello my name is " << name << " and I am " << age << " years old!" << endl;} 


//SPEAK Functions of each class
void animal::speak()
{	cout << "I am not a talking type of animal" << endl;}
void dog::speak()
{	cout << "Bark! Bark!" << endl;}
void cat::speak()
{	cout << "Meow! Meow!" << endl;}
void straydog::speak()
{	cout << "Woof! Woof!" << endl;}



//ACTION functions
void animal::action()
{	cout << "I could be doing anything" << endl;}

void straydog::action()
{	cout << "Chases Car" << endl;}

void petdog::action()
{	cout << "Fetching a Stick" << endl;}


animal::animal() //Initial
{	age = 0;}
animal::animal(char* n, int a) //Animal Name+age
{	
	strcpy(name, n);
	age = a;
}

animal::~animal() //Destructor
{}

int main() //Main Function
{
	int a;
	int window; 
	char rand[10],tem[2];
	tem[1] = '\0'; 
	
	animal**animals = new animal*[7]; //Assigning Array values
	animals[1] = new animal();  
	animals[2] = new animal();
	animals[3] = new animal();
	animals[4] = new dog();
	animals[5] = new cat();
	animals[6] = new straydog();
	animals[7] = new petdog();
	
	for (a = 1; a < 8; a++) //For loop for Animal Numbering
	{
		tem[0] = a + '0';
		    strcpy(rand, "Animal #");
		    strcat(rand, tem);
		    animals[a]->setname(rand);
	}
	
	for (a = 1; a < 8; a++) //For Loop for Animal Talking
	{
		cout << endl << "Animal: " << a << endl;
	
		animals[a]->birthday();
		
		cout << "Introduction:" << endl; 
		animals[a]->introduce();
		
		cout << "I say:" << endl;
		animals[a]->speak();
		
		cout << "My action:" << endl;
		animals[a]->action();
	}
	
cin >> window; //to keep window open
return 0;
}
