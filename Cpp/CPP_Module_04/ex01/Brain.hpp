#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &Brain);
        Brain &operator=(const Brain &Brain);
        ~Brain();

        void        Set_Idea(int index, std::string idea);
        void        Print_Ideas() const;


        std::string Get_Idea(int index) const;

};

#endif