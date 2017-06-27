#ifndef H_StackType
#define H_StackType

#include <iostream>
#include <cassert>
#include "stackADT.h"
using namespace std;
template <class Type>
class stackType : public stackADT<Type>
{
public:
	const stackType<Type>& operator=(const stackType<Type>&); //the assignment operator gets overloaded
	void initializeStack(); //intialize the stack to be empty.
	bool isEmptyStack() const; //determines whether stack is empty or not.
	bool isFullStack() const; //determines for the stack is full or not.
	void push(const Type& newItem); //add new item to the stack.
	Type top() const; //returns the top most element of the stack.
	void pop(); //removes the top most element of the stack.
	stackType(int stackSize = 100); //Constructor -- creates an array to hold 100 elements in the form of the stack.
	stackType(const stackType<Type>& otherStack); //Copy constructor
	~stackType(); //Destructor -- Remove all the elements from the stack.
private:
	int maxStackSize; //variable to store the maximum stack size
	int stackTop; //variable to point to the top of the stack
	Type *list; //pointer to the array that holds the stack elements
	void copyStack(const stackType<Type>& otherStack);
	// make a copy of otherStack.
};

template <class Type>
void stackType<Type>::initializeStack() // defines the funcation to initialize stack
{
	stackTop = 0; // assign 0
}//end initializeStack

//defines the function to check the stack is empty
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	// returns stack top
	return (stackTop == 0);
}//end isEmptyStack

//defines the function to check the stack is full
template <class Type>
bool stackType<Type>::isFullStack() const
{
	// returns stack top
	return (stackTop == maxStackSize);
} //end isFullStack

// defines the function to perform push
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	// calls isFullStack()
	if (!isFullStack())
	{
		list[stackTop] = newItem; //add newItem to the
		//top of the stack
		stackTop++; //increment stackTop
	}
	else
		// statement to print out
		cout << "Cannot add to a full stack." << endl;
}//end push

// defines the function to perform top
template <class Type>
Type stackType<Type>::top() const
{
	// calls assert()
	assert(stackTop != 0); //if stack is empty,
	//terminate the program
	return list[stackTop - 1]; //return the element of the
	//stack indicated by
	//stackTop - 1
}//end top

//defines the function to perform pop()
template <class Type>
void stackType<Type>::pop()
{
	// checks isEmptyStack()
	if (!isEmptyStack())
		stackTop--; //decrement stackTop
	else
		cout << "Cannot remove from an empty stack." << endl;
}//end pop

// defines the function to check type
template <class Type>
stackType<Type>::stackType(int stackSize)
{
	// checks the size of stack
	if (stackSize <= 0)
	{
		// statements to print out
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;
		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize; //set the stack size to
	//the value specified by
	//the parameter stackSize
	stackTop = 0; //set stackTop to 0
	list = new Type[maxStackSize]; //create the array to
	//hold the stack elements
}//end constructor


template <class Type>
stackType<Type>::~stackType() //destructor
{
	delete[] list; //deallocate the memory occupied
	//by the array
}//end destructor
template <class Type>
void stackType<Type>::copyStack(const stackType<Type>& otherStack)
{
	delete[] list;
	maxStackSize = otherStack.maxStackSize;
	stackTop = otherStack.stackTop;
	list = new Type[maxStackSize];
	//copy otherStack into this stack
	for (int j = 0; j < stackTop; j++)
		list[j] = otherStack.list[j];
} //end copyStack

template <class Type>
stackType<Type>::stackType(const stackType<Type>& otherStack)
{
	list = nullptr;
	copyStack(otherStack);
}//end copy constructor
template <class Type>
const stackType<Type>& stackType<Type>::operator=
(const stackType<Type>& otherStack)
{
	if (this != &otherStack) //avoid self-copy
		copyStack(otherStack);
	return *this;
} //end operator=
#endif



