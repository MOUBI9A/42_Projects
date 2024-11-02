
#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "WrongDog.hpp"

// int main() {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* j = new WrongDog();
//     const WrongAnimal* i = new WrongCat();
//     std::cout << j->get_type() << " " << std::endl;
//     std::cout << i->get_type() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     delete meta;
//     delete j;
//     delete i;
//     return 0;
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->get_type() << std::endl;
    i->makeSound(); 
    std::cout << i->get_type() << std::endl;
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete i;
    delete j;
    
    std::cout<<"\033[31m--------------------------------------------\033[0m"<<std::endl;
    const WrongAnimal* justanimal = new WrongAnimal();
    const WrongAnimal* notaCat = new WrongCat();
    
    justanimal->makeSound();
    notaCat->makeSound();
    
    delete justanimal;
    delete notaCat;
    return 0;
}