#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "stackType.h"
using namespace std;
int main()
{
	//Declration of variable
	double GPA;
	double highestGPA;
	string name;

	// stack(100) is object of class stackType
	stackType<string> stack(100);
	ifstream infile;

	// opening data.txt file using open()
	infile.open("Data.txt");

	if (!infile) // checking of weather data.txt file exist or not
	{
		cout << "The input file does not "
			<< "exist. Program terminates!"
			<< endl;
		return 1;
	}
	cout << fixed << showpoint; // to set manipulator for on output screen
	cout << setprecision(2); // to set precision for on output screen
	infile >> GPA >> name; // data from file is taken to GPA and name variable
	highestGPA = GPA; //GPA is assigned to highestGPA
	while (infile) //loop continues untill we dont get EOF Character
	{
		if (GPA > highestGPA) // if GPA is high than highestGPA
		{
			stack.initializeStack(); // call initializeStack() of stackType class
			if (!stack.isFullStack()) // if stack is not full
				stack.push(name);
			highestGPA = GPA; //GPA is assigned to highestGPA
		}
		else if (GPA == highestGPA) // if GPA is equal to highestGPA
		if (!stack.isFullStack())
			stack.push(name);
		else                // if GPA is less than highestGPA
		{
			cout << "Stack overflows. "
				<< "Program terminates!"
				<< endl;
			return 1; //exit program
		}
		infile >> GPA >> name; //data from file is taken to GPA and name variable
	}
	cout << "Highest GPA = " << highestGPA
		<< endl; //Step 8
	cout << "The students holding the "
		<< "highest GPA are:" << endl;
	while (!stack.isEmptyStack()) // loop continues untill stack dont become empty
	{
		cout << stack.top() << endl; //print top element of stack
		stack.pop(); //pop for stack
	}
	cout << endl;
	system("pause");
}