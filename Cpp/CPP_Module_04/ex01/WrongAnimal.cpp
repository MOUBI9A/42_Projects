#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal"), name("WrongAnimal") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type), name("WrongAnimal") {
    std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type, std::string name) : type(type), name(name) {
    std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal){
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal) {
    std::cout << "WrongAnimal assignation operator called" << std::endl;
    if (this == &WrongAnimal)
        return *this;
    this->set_type(WrongAnimal.get_type());
    this->set_name(WrongAnimal.get_name()+ "_cpy"); 
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "hey bro hru! M the wrong one" << std::endl;
}


void WrongAnimal::set_type(std::string type) {
    this->type = type;
}

std::string WrongAnimal::get_type() const {
    return this->type;
}

void WrongAnimal::set_name(std::string name) {
    this->name = name;
}

std::string WrongAnimal::get_name() const {
    return this->name;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal default destructor called" << std::endl;
}