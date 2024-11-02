/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:03:25 by hel-moue          #+#    #+#             */
/*   Updated: 2024/10/13 12:38:37 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inter.hpp"
#include <string>

void increment(int &n) 
{
    n++;
}

void addHello(std::string &s) 
{
    s += " Hello\n";
}

int main()
{
    // Test integer
    int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, increment);
    for (int i = 0; i < 5; i++)
        printvalue(intArray[i]);  // 2 3 4 5 6
    std::cout << std::endl;

    // Test string 
    std::string strArray[] = {"brahim", "mestafa", "lbachir"};
    iter(strArray, 3, addHello);
    for (int i = 0; i < 3; i++) 
        printvalue(strArray[i]); 
    std::cout << std::endl;

    return 0;
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }
