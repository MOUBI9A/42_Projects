#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"
class WrongCat : public WrongAnimal {
    public:
        WrongCat();
        WrongCat(std::string name);
        WrongCat(const WrongCat &);
        WrongCat &operator=(const WrongCat &);
        ~WrongCat();

        void makeSound() const;
};

#endif 