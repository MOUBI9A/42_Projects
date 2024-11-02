#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog", "WrongDog") {
    std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(std::string name) : WrongAnimal("WrongDog", name) {
    std::cout << "WrongDog name constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &wrongDog) {
    std::cout << "WrongDog copy constructor called" << std::endl;
    *this = wrongDog;
}

WrongDog &WrongDog::operator=(const WrongDog &wrongDog) {
    std::cout << "WrongDog assignation operator called" << std::endl;
    if (this == &wrongDog)
        return *this;
    this->set_type(wrongDog.get_type());
    this->set_name(wrongDog.get_name() + " cpy");
    return *this;
}

void WrongDog::makeSound() const {
    std::cout << "Woof Woof from the wrong one 🐕🐕🐕" << std::endl;
}

WrongDog::~WrongDog() {
    std::cout << "WrongDog destructor called" << std::endl;
}