#include "easyfind.hpp"
// #pragma once

// Test function
// void test_easyfind() {
//     // Test with std::vector
//     std::vector<int> vec;
//     try 
//     {
//         vec.push_back(1);
//         std::vector<int>::iterator it = easyfind(vec, 3);
//         std::cout << "Found " << *it << " in vector" << std::endl;
//     } 
//     catch (const ElementNotFoundException& e) 
//     {
//         std::cout << e.what() << std::endl;
//     }
//     // Test with std::list
//     std::list<int> lst;
//     lst.push_back(10);
//     lst.push_back(20);
//     lst.push_back(30);
//     lst.push_back(40);
//     lst.push_back(50);
//     try 
//     {
//         std::list<int>::iterator it = easyfind(lst, 20);
//         std::cout << "Found " << *it << " in list" << std::endl;
//     }
//     catch (const ElementNotFoundException& e) {
//         std::cout << e.what() << std::endl;
//     }
//     // Test with element not found
//     try
//     {
//         std::vector<int>::iterator it = easyfind(vec, 6);
//         std::cout << "Found " << *it << " in vector" << std::endl;
//     } 
//     catch (const ElementNotFoundException& e) 
//     {
//         std::cout << e.what() << std::endl;
//     }
// }

// int main()
// {
//     test_easyfind();
//     return 0;
// }

// subject test
int main() {
    // Create a vector of integers
    std::vector<int> numbers;

    // 1. Add elements to check automatic resizing
    numbers.push_back(5);  // Add one element
    numbers.push_back(10); // Add another element
    numbers.push_back(15); // Add a third element

    std::cout << "After adding 3 elements:" << std::endl;
    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;

    // 2. Attempt to access an out-of-bounds element
    // Be cautious, as accessing out of bounds can lead to undefined behavior (avoid doing this).
    // std::cout << numbers[5] << std::endl; // This would cause undefined behavior

    // 3. Resize using `resize()` to increase the size
    numbers.resize(5); // Increase size to 5, new elements are initialized to 0
    std::cout << "After resizing to 5:" << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // 4. Reserve more capacity using `reserve()` to check the impact on capacity
    numbers.reserve(10); // Reserve space for 10 elements to avoid future reallocations
    std::cout << "After reserving capacity for 10:" << std::endl;
    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;

    // 5. Test resizing down using `resize()` to a smaller value
    numbers.resize(3); // Decrease size to 3, elements after index 3 are discarded
    std::cout << "After resizing down to 3:" << std::endl;
    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    // 6. Clear all elements using `clear()`
    numbers.clear();
    std::cout << "After clearing all elements:" << std::endl;
    std::cout << "Size: " << numbers.size() << ", Capacity: " << numbers.capacity() << std::endl;
    std::cout << "Is the vector empty? " << (numbers.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
