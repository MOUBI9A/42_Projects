#include "RPN.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "usage: ./RPN \"expression\"" << std::endl;
        return 1;
    }
    RPN rpn(argv[1]);
    if (rpn.getError())
    {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::cout << rpn.getResult() << std::endl;
    return 0;
}