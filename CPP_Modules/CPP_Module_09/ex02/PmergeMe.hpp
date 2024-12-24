#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& src);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& src);

    int ProcessArgs(char** argv);
    void Print();
    std::vector<int> Sort(std::vector<int>& elements);
    std::deque<int> Sort(std::deque<int>& elements);
    int Parse(char const *argv[]);
    void print_time(clock_t start, clock_t end, std::string type);

    std::vector<int> GetElements() const;
    std::deque<int> GetDeque() const;
    clock_t GetVStart() const { return this->v_start; }
    clock_t GetVEnd() const { return this->v_end; }
    clock_t GetDStart() const { return this->d_start; }
    clock_t GetDEnd() const { return this->d_end; }

private:
    clock_t v_start, v_end;
    clock_t d_start, d_end;
    std::vector<int> m_elements;
    std::deque<int> m_deque;
    size_t m_size;
};

#endif // PMERGEME_HPP