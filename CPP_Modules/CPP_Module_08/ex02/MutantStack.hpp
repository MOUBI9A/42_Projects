#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template<typename T> // the template parameter T is the type of the elements in the stack
class MutantStack : public std::stack<T> {
public:
	// the typedefs to define the iterator types
	typedef typename std::stack<T>::container_type::iterator iterator; 

	// the constructor and destructor 
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	~MutantStack() {}

	// the assignment operator
	MutantStack &operator=(const MutantStack &other) 
	{
		std::stack<T>::operator=(other);
		return *this;
	}

	// the member functions that return iterators to the beginning and the end of the stack 
	iterator begin()
	{
		return std::stack<T>::c.begin();
	}
	iterator end()
	{
		return std::stack<T>::c.end();
	}
};


#endif // MUTANTSTACK_HPP