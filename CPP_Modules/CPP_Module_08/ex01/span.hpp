
#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
		// _n is the maximum number of elements that can be stored in the vector
		// _v is the vector that stores the elements
		unsigned int _n;
		std::vector<int> _v;
	
	public:
		// Constructors and Destructors 
		Span(unsigned int n);
		Span(const Span &span);
		~Span();
		// Operator Overloads
		Span &operator=(const Span &span);
		// // Getters and Setters
		// std::vector<int> getV() const;
		// void setV(std::vector<int> v);
		// void setN(unsigned int n);
		// unsigned int getN() const;
		// Member Functions
		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		unsigned int size() const;
		// Exceptions
		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};


};

#endif