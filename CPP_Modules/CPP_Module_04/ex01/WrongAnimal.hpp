#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


#include <iostream>

class WrongAnimal{
    protected :
        std::string type;
        std::string name;
    public :
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(std::string type, std::string name);
        WrongAnimal(const WrongAnimal &WrongAnimal);

        WrongAnimal &operator=(const WrongAnimal &WrongAnimal);

        void makeSound() const;

        void        set_type(std::string type);
        std::string get_type() const;
        void        set_name(std::string name);
        std::string get_name() const;

        ~WrongAnimal();
};


#endif 