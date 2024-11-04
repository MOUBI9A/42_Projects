#include "span.hpp"

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &span) : _n(span._n), _v(span._v) {}

Span::~Span() {}


Span &Span::operator=(const Span &span)
{
	 if (this != &span) {
        _n = span._n;
        _v = span._v;
    }
	return *this;
}

const char *Span::FullSpanException::what() const throw()
{
	return "The span is full";
}

const char *Span::NoSpanException::what() const throw()
{
	return "There is no span to find";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to find a span";
}

void Span::addNumber(int n)
{
	if (_v.size() >= _n)
		throw FullSpanException();
	_v.push_back(n);
}

int Span::shortestSpan()
{
	int		min;

	if (_v.size() < 2) 
		throw NotEnoughNumbersException();
	std::vector<int> v = _v; 
	std::sort(v.begin(), v.end());
	min = v.at(1) - v.at(0);
	for (unsigned int i = 1; i < v.size(); i++)
	{
		if (v.at(i) - v.at(i - 1) < min)
			min = v.at(i) - v.at(i - 1);
	}
	return min;
}

int Span::longestSpan()
{
	if (_v.size() < 2) 
		throw NotEnoughNumbersException();
	std::vector<int> v = _v; 
	std::sort(v.begin(), v.end()); 
	return v.at(v.size() - 1) - v.at(0);
}