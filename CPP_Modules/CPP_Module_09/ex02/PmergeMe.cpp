#include "PmergeMe.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <ctime>

PmergeMe::PmergeMe() : m_size(0) {}

PmergeMe::PmergeMe(const PmergeMe& src) {
    this->m_elements = src.m_elements;
    this->m_deque = src.m_deque;
    this->m_size = src.m_size;
}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& src) {
    if (this == &src)
        return *this;
    this->m_elements = src.m_elements;
    this->m_deque = src.m_deque;
    this->m_size = src.m_size;
    return *this;
}



int PmergeMe::ProcessArgs(char** argv) {
    int elm = 1;
    std::string nb;

    while (argv[elm]) {
        nb = argv[elm];
        if (nb.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error: " << nb << " is not a number" << std::endl;
            return 1;
        }
        this->m_elements.push_back(std::stoi(nb));
        this->m_deque.push_back(std::stoi(nb));
        elm++;
        this->m_size++;
    }
    return 0;
}


void PmergeMe::Print() {
    std::cout << "Vector: ";
    for (size_t i = 0; i < this->m_size; i++)
        std::cout << this->m_elements[i] << " ";
    std::cout << std::endl;
    std::cout << "Deque: ";
    for (size_t i = 0; i < this->m_size; i++)
        std::cout << this->m_deque[i] << " ";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::Sort(std::vector<int>& elements) {
    unsigned int size = elements.size();

    this->v_start = clock();
    if(size < 3)
    {

        if(elements.size() == 2 && elements.at(0) > elements.at(1))
        {
            int tmp = elements.at(0);
            elements.at(0) = elements.at(1);
            elements.at(1) = tmp;
        }
        this->v_end = clock();
        return elements;
    }
    std::vector<std::pair<int, int> > pair;
    std::vector<int> chyata;
    for (size_t i = 0; i < size - 1; i += 2)
    {
        pair.push_back(std::make_pair(elements[i], elements[i + 1]));
    }
    if (size % 2 != 0)
    {
        chyata.push_back(elements[size - 1]);
    }
    for(size_t i = 0; i < pair.size(); ++i)
    {
        if(pair[i].first > pair[i].second)
            std::swap(pair[i].first , pair[i].second);
    }
    std::vector<int> sorted;
    sorted.push_back(pair[0].first);
    for(size_t i = 0; i < pair.size(); ++i)
    {
        sorted.push_back(pair[i].second);
    }
    sorted = Sort(sorted);
    for(size_t i = 1; i < pair.size(); ++i)
    {
        chyata.push_back(pair[i].first);
    }
     for (size_t i = 0; i < chyata.size(); ++i) {
        std::vector<int>::iterator pos = std::upper_bound(sorted.begin(), sorted.end(), chyata[i]);
        sorted.insert(pos, chyata[i]);
    }
    this->v_end = clock();
    return sorted;
}




void PmergeMe::print_time(clock_t start, clock_t end, std::string type)
{
    double time_taken = end - start;
    std::cout << "Time taken by program to sort " << type << " is : "<< time_taken <<" ms" << std::endl;
}




std::deque<int> PmergeMe::Sort(std::deque<int>& elements)
{
    unsigned int size = elements.size();

    this->d_start = clock();
    if(size < 3)
    {

        if(elements.size() == 2 && elements[0] > elements[1])
        {
            int tmp = elements[0];
            elements[0] = elements[1];
            elements[1] = tmp;
        }
        this->d_end = clock();
        return elements;
    }
    std::vector<std::pair<int, int> > pair;
    std::vector<int> chyata;
    for (size_t i = 0; i < size - 1; i += 2)
        pair.push_back(std::make_pair(elements[i], elements[i + 1]));
    if (size % 2 != 0)
        chyata.push_back(elements[size - 1]);
    for(size_t i = 0; i < pair.size(); ++i)
    {
        if(pair[i].first > pair[i].second)
            std::swap(pair[i].first , pair[i].second);
    }
    std::vector<int> sorted;
    sorted.push_back(pair[0].first);
    for(size_t i = 0; i < pair.size(); ++i)
        sorted.push_back(pair[i].second);
    sorted = Sort(sorted);
    for(size_t i = 1; i < pair.size(); ++i)
    {
        chyata.push_back(pair[i].first);
    }
     for (size_t i = 0; i < chyata.size(); ++i)
     {
        std::vector<int>::iterator pos = std::upper_bound(sorted.begin(), sorted.end(), chyata[i]);
        sorted.insert(pos, chyata[i]);
    }
    std::deque<int> sorted_deque;
    for (size_t i = 0; i < sorted.size(); i++)
        sorted_deque.push_back(sorted[i]);
    this->d_end = clock();
    return sorted_deque;
}


std::vector<int> PmergeMe::GetElements() const
{
    return this->m_elements;
}

std::deque<int> PmergeMe::GetDeque() const
{
    return this->m_deque;
}


int PmergeMe::Parse(char const *argv[])
{
    int arg = 1;
    std::string nb;

    while (argv[arg]) {
        nb = argv[arg];
        if (nb.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error: " << nb << " is not a number" << std::endl;
            return 1;
        }
        this->m_elements.push_back(std::stoi(nb));
        this->m_deque.push_back(std::stoi(nb));
        arg++;
        this->m_size++;
    }
    return 0;
}