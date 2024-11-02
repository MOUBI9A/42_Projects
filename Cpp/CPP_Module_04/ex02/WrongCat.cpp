#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat", "WrongCat") {
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string name) : WrongAnimal("WrongCat", name) {
    std::cout << "WrongCat name constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = wrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
    std::cout << "WrongCat assignation operator called" << std::endl;
    if (this == &wrongCat)
        return *this;
    this->set_type(wrongCat.get_type());
    this->set_name(wrongCat.get_name() + " cpy");
    return *this;
}

void WrongCat::makeSound() const {
    std::cout << "Meow Meow from the wrong one 🐈🐈🐈" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}
