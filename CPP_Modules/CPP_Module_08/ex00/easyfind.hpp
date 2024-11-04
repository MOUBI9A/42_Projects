#include <algorithm>
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <exception>

// Define a custom exception for when the element is not found
class ElementNotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found";
    }
};

// container: The container to search in (vector, deque, list, set, etc)
// val: The value to search for
// Returns an iterator to the found element, or the end of the container if not found
// find() takes the begin and end iterators of the container, and the value to search for
template <typename T>
typename T::iterator easyfind(T& container, int val){
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end()) {
        throw ElementNotFoundException();
    }
    return it;
}
