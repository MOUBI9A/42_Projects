#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
class Dog : public Animal {
    public:
        Dog();
        Dog(std::string name);
        Dog(const Dog &);
        Dog &operator=(const Dog &);
        ~Dog();

        virtual void makeSound() const;
};
#endif 
