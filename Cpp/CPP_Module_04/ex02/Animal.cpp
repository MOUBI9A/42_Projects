#include "Animal.hpp"

Animal::Animal() : type("Animal"), name("Animal") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type), name("Animal") {
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(std::string type, std::string name) : type(type), name(name) {
    std::cout << "Animal type constructor called" << std::endl;
}

Animal::Animal(const Animal &animal){
    std::cout << "Animal copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
    std::cout << "Animal assignation operator called" << std::endl;
    if (this == &animal)
        return *this;
    this->set_type(animal.get_type());
    this->name = animal.get_name() + " cpy";
    return *this;
}


void Animal::set_type(std::string type) {
    this->type = type;
}

std::string Animal::get_type() const {
    return this->type;
}

void Animal::set_name(std::string name) {
    this->name = name;
}

std::string Animal::get_name() const {
    return this->name;
}

Animal::~Animal() {
    std::cout << "Animal default destructor called" << std::endl;
}