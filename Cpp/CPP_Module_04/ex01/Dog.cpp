#include "Dog.hpp"

Dog::Dog() : Animal("Dog", "Dog") {
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string name) : Animal("Dog", name) {
    std::cout << "Dog name constructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof Woof 🐕🐕🐕" << std::endl;
}

Dog::Dog(const Dog &dog) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
    std::cout << "Dog assignation operator called" << std::endl;
    if (this == &dog)
        return *this;
    this->set_type(dog.get_type());
    this->set_name(dog.get_name() + " cpy");
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}