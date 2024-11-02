#include "Cat.hpp"

Cat::Cat() : Animal("Cat", "Cat") {
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string name) : Animal("Cat", name) {
    std::cout << "Cat name constructor called" << std::endl;
}

void Cat::makeSound() const {
    std::cout << "Meow Meow 🐈🐈🐈" << std::endl;
}

Cat::Cat(const Cat &cat) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
    std::cout << "Cat assignation operator called" << std::endl;
    if (this == &cat)
        return *this;
    this->set_type(cat.get_type());
    this->set_name(cat.get_name() + " cpy");
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
