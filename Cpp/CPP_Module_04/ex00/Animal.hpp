#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{
    protected :
        std::string type;
        std::string name;
    public :
        Animal();
        Animal(std::string type);
        Animal(std::string type, std::string name);
        Animal(const Animal &animal);

        Animal &operator=(const Animal &animal);

        virtual void makeSound() const;

        void        set_type(std::string type);
        std::string get_type() const;
        void        set_name(std::string name);
        std::string get_name() const;

        virtual ~Animal();
};


#endif 