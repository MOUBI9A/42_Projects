#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = "default idea number " + std::to_string(i);
    }
}

std::string Brain::Get_Idea(int index) const{
    return this->ideas[index];
}

void Brain::Set_Idea(int index, std::string idea){
    ideas[index] = idea;
}

void Brain::Print_Ideas() const{
    for (int i = 0; i < 100; i++) {
        std::cout << "Idea " << i << ": " << Get_Idea(i) << std::endl;
    }
}

Brain::Brain(const Brain &other) {
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++) {
        this->Set_Idea(i, other.ideas[i] + " (copy)");
    }
}

Brain &Brain::operator=(const Brain &other) {
    std::cout << "Brain assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    for (int i = 0; i < 100; i++) {
        this->Set_Idea(i, other.ideas[i] + " (assign)");
    }
    return *this;
}

Brain::~Brain() {
    std::cout << "Brain destructor called" << std::endl;
}
