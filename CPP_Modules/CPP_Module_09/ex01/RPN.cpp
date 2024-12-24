#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input), _result(0), _error(false)
{
    std::string token;
    std::istringstream iss(input);
    while (std::getline(iss, token, ' '))
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
            {
                _error = true;
                return;
            }
            float a = _stack.top();
            _stack.pop();
            float b = _stack.top();
            _stack.pop();
            if (token == "+")
                _stack.push(b + a);
            else if (token == "-")
                _stack.push(b - a);
            else if (token == "*")
                _stack.push(b * a);
            else if (token == "/")
            {
                if (a == 0)
                {
                    _error = true;
                    return;
                }
                _stack.push(b / a);
            }
        }
        else
        {
            if (token.find_first_not_of("0123456789") != std::string::npos)
            {
                _error = 1;
                return;
            }
            //TODO 
            _stack.push(std::atoi(token.c_str()));
        }
    }
    if (_stack.size() != 1)
        _error = 1;
    else
        _result = _stack.top();
}

RPN::~RPN() {}

RPN::RPN(const RPN &src) : _stack(src._stack), _input(src._input), _result(src._result), _error(src._error) {}

RPN &RPN::operator=(const RPN &src)
{
    if (this == &src)
        return *this;
    _stack = src._stack;
    _input = src._input;
    _result = src._result;
    _error = src._error;
    return *this;
}

