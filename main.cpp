//This program displays the different sub-class messages and actions after user input. It uses Animal as the parent class and divides
//between the dog and cat classes for the child classes. This is then divided into further sub-classes. All functions are related to 
//the function and uses simple display messages to display the final result.

//#include "stdafx.h" //for VS studio 
#include <iostream> 
#include <string>
#include <cstring>
using namespace std;

class animal //base class (TOP)
{
public:
	char* getname(); 	    //getter functions
	int getage(); 
	
	void setage(int a); 	//setter functions
	void setname(char* n);

	virtual void speak(); 	//speak (virtual)
	virtual void action(); 	//action (virtual)
	
	void introduce(); 	    //introduce
	void birthday();
	
	animal();
	animal(char* name, int age);
	~animal();
protected:
    char name[25]; 
	int age;
};

//setting classes for animals using base class, all these animals are related in nature.
//all classes have speak function in common. 
class dog : public animal // Class 1
{ 	virtual void speak();
};

class cat : public animal // Class 2
{    virtual void speak();
};

class straydog : public dog // Sub-Class 1a 
{	virtual void speak();
	virtual void action();
};

class petdog : public dog // Sub-Class 1b
{	virtual void speak();
	virtual void action();
};

class huskydog : public dog // Sub-Class 1c
{   virtual void speak();
    virtual void action();
};

class whitecat : public animal // Sub-Class 2a
{   virtual void speak();
    virtual void action();
};

class browncat : public animal // Sub-Class 2b
{   virtual void speak();
    virtual void action();
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

//INTRODUCE function 
void animal::introduce() //just a message
{	cout << "Hello my number is " << name << " and I am " << age << " years old!" << endl;} 

//Birthday function
void animal::birthday()
{
	age++;
}

//SPEAK Functions of each class
void animal::speak()
{	cout << "I am not a talking type of animal" << endl;}
void dog::speak()
{	cout << "Bark! Bark!" << endl;}
void cat::speak()
{	cout << "Meow! Meow!" << endl;}
void straydog::speak()
{	cout << "Woof! Woof!" << endl;}
void petdog::speak()
{	cout << "Gimme Bone!" << endl;}
void huskydog::speak()
{	cout << "Husk! Husk!" << endl;}
void whitecat::speak()
{	cout << "Food! Meow!" << endl;}
void browncat::speak()
{	cout << "Toys! Meow!" << endl;}


//ACTION functions
void animal::action()
{	cout << "I could be doing anything" << endl;}
void straydog::action()
{	cout << "Chases Car" << endl;}
void petdog::action()
{	cout << "Fetching a Stick" << endl;}
void huskydog::action()
{	cout << "Climbing a Snow Mountain" << endl;}
void whitecat::action()
{	cout << "Sleeping Quietly" << endl;}
void browncat::action()
{	cout << "Jumping Around to Play" << endl;}

animal::animal() //Initial
{	age = 5;}
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
	char c;
	tem[1] = '\0'; 
	
	animal**animals = new animal*[8];   //Assigning Array values
	animals[1] = new animal();  
	animals[2] = new dog();
	animals[3] = new straydog();
	animals[4] = new huskydog();
	animals[5] = new petdog();
	animals[6] = new cat();
	animals[7] = new browncat();
	animals[8] = new whitecat();
	
	for (a = 1; a < 9; a++) //For loop for Animal Numbering
	{
		tem[0] = a + '0';
		    strcpy(rand, "Animal #");
		    strcat(rand, tem);
		    animals[a]->setname(rand);
	}
	
	//Creating a menu system, using if functions and feedbacking back to array to get the appropriate classes
	//Also has an input for user to go back to main menu to restart process.
	menu:
	cout << "Choose action:" << endl << "1-Create Your Animal!" <<  endl << "0-Exit"<< endl;
	cin >> c;
	if (c=='1')
	{ 
	    cout <<  endl << "**Choose Your Animal Cat/Dog Using the Numbers**" <<  endl << "1.Dog / 2.Cat" << endl << "9.Return to Main Menu" << endl << "0.Exit Program"<< endl;
	    cin >> c;
	    
	    if (c=='1')
	    {
	       cout << endl << "**Choose Your Favourite Dog Using the Numbers**" <<  endl << "3.Stray Dog / 4.Husky Dog / 5.Pet Dog" << endl << "9.Return to Main Menu" << endl << "0.Exit Program"<< endl;
	       cin >> c;
	       if (c=='3')
	       {
	            a=3;
	            cout << endl << "Dog: " << a << endl;
	            animals[a]->birthday();
		        cout << "Introduction: Stray Dog" << endl; 
		        animals[a]->introduce();
		        cout << "I say:" << endl;
		        animals[a]->speak();
		        cout << "My action:" << endl;
		        animals[a]->action();
		        return 0;
	       }
	       if (c=='4')
	       {
	            a=4;
	            cout << endl << "Dog: " << a << endl;
	            animals[a]->birthday();
		        cout << "Introduction: Husky Dog" << endl; 
		        animals[a]->introduce();
		        cout << "I say:" << endl;
		        animals[a]->speak();
		        cout << "My action:" << endl;
		        animals[a]->action();
		        return 0;
	       }
	       if (c=='5')
	       {
	            a=5;
	            cout << endl << "Dog: " << a << endl;
	            animals[a]->birthday();
		        cout << "Introduction: Pet Dog" << endl; 
		        animals[a]->introduce();
		        cout << "I say:" << endl;
		        animals[a]->speak();
		        cout << "My action:" << endl;
		        animals[a]->action();
		        return 0;
	       }
	       else if (c=='9')
	        goto menu;
	       else if (c=='0')
	        return 0;
	       else
		   {
		    cout << "Invalid Input" << endl;
		    goto menu;
		   }
	    }
	    else if (c=='2')
	    {
	       cout << endl << "**Choose Your Favourite Cat Using the Numbers**" <<  endl << "7.Brown Cat / 8.White Cat" << endl << "9.Return to Main Menu" << endl << "0.Exit Program"<< endl;
	       cin >> c;
	       if (c=='7')
	       {
	           a=7;
	            cout << endl << "Cat: " << a << endl;
	            animals[a]->birthday();
		        cout << "Introduction: Brown Cat" << endl; 
		        animals[a]->introduce();
		        cout << "I say:" << endl;
		        animals[a]->speak();
		        cout << "My action:" << endl;
		        animals[a]->action();
		        return 0;
	       }
	       if (c=='8')
	       {
	            a=8;
	            cout << endl << "Cat: " << a << endl;
	            animals[a]->birthday();
		        cout << "Introduction: White Cat" << endl; 
		        animals[a]->introduce();
		        cout << "I say:" << endl;
		        animals[a]->speak();
		        cout << "My action:" << endl;
		        animals[a]->action();
		        return 0;
	       }
	       else if (c=='9')
	        goto menu;
	       else if (c=='0')
	        return 0;
	       else
		   {
		    cout << "Invalid Input" << endl;
		    goto menu;
		   }
	    }
	    else
		   {
		    cout << "Invalid Input" << endl;
		    goto menu;
		   }
	}
	else if (c=='9')
	    goto menu;
	else if (c == '0')
	    return 0;
	else
	   {
	    cout << "Invalid Input" << endl;
	    goto menu;
	   }

//cin >> window; //to keep window open
return 0;
}

