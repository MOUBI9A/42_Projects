#include "PmergeMe.hpp"
#include <iostream>

int Sort_chek(std::vector<int> elements)
{
    for (size_t i = 0; i < elements.size() - 1; i++)
    {
        if (elements[i] > elements[i + 1])
            return 0;
    }
    return 1;
}


int main(int argc, char const *argv[])
{
   if (argc < 2)
   {
        std::cerr << "Error: No arguments" << std::endl;
        return 1;
    }
    if (argc == 2)
    {
        std::cerr << "Error: Not enough arguments:  i can't sort only one element" << std::endl;
        return 1;
    }
    PmergeMe pm;
    int n = pm.Parse(argv);
    if (n)
        return 1;
    if (Sort_chek(pm.GetElements()))
    {
        std::cout << "input is already sorted" << std::endl;
        return 0;
    }
    
    pm.Print();
    std::vector<int> sorted = pm.GetElements();
    std::deque<int> sorted_deque = pm.GetDeque(); 
    sorted = pm.Sort(sorted);
    sorted_deque = pm.Sort(sorted_deque);
    //print the sorted vector
    std::cout << "Sorted vector: ";
    for (size_t i = 0; i < sorted.size(); i++)
        std::cout << sorted[i] << " ";
    std::cout << std::endl;
    pm.print_time(pm.GetVStart(), pm.GetVEnd(), "vector");


    //print the sorted deque
    std::cout << "Sorted deque: ";
    for (size_t i = 0; i < sorted_deque.size(); i++)
        std::cout << sorted_deque[i] << " ";
    std::cout << std::endl;
    pm.print_time(pm.GetDStart(), pm.GetDEnd(), "deque");


    return 0;

}

