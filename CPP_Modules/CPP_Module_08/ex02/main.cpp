#include "MutantStack.hpp"
#include <iostream>

int main(){
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top is : "<<mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top is : "<<mstack.top() << std::endl;
	std::cout << "size is :"<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "size is :"<< mstack.size() << std::endl;
	return 0;
}