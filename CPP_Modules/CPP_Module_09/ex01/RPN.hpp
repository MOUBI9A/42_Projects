#ifndef RNP_HPP
#define RNP_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>
#include <climits>



class RPN
{
    private:

    std::stack<float> _stack;
    std::string _input;
    float _result;
    bool _error;

    public:
    
    RPN(std::string input);
    ~RPN();
    RPN(const RPN &src);
    RPN &operator=(const RPN &src);


    std::stack<float> getStack() const { return _stack; }
    std::string getInput() const { return _input; }
    int getError() const { return _error; }
    int getResult() const { return _result; }
};










#endif // RNP_HPP