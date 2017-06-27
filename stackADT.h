
// declares the template class
template <class Type>
class stackADT
{
public:
	virtual void initializeStack() = 0;	// initialize the stack to an empty state.
	virtual bool isEmptyStack() const = 0;	// determine whether the stack is empty.
	virtual bool isFullStack() const = 0; 	// determine whether the stack is full.
	virtual void push(const Type& newItem) = 0; 	// add newItem to the stack.
	virtual Type top() const = 0; 	//Function to return the top element of the stack.
	virtual void pop() = 0; 	//Function to remove the top element of the stack.
};