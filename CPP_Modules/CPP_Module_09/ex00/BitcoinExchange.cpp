/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-moue <hel-moue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 01:32:40 by amait-ou          #+#    #+#             */
/*   Updated: 2024/12/23 18:54:16 by hel-moue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

void read_data(std::map<std::string, float> &m, std::string path)
{
    std::ifstream   db;
    std::string     t;
    std::string     d;
    size_t          p;
    float           v;
    char            *ptr;

    db.open(path.c_str());
    if (!db.is_open())
        throw std::string("failed to read from database file");
    std::getline(db, t);
    while (std::getline(db, t))
    {
        p = t.find(",");
        d = t.substr(0, p);
        v = strtof(t.substr(p + 1).c_str(), &ptr);
        m.insert(std::make_pair(d, v));
    }
}

int check_value(std::string &s)
{
    size_t  i(0);
    int     n;
    if (s[i] == '-' || s[i] == '+')
        ++i;
    while (i < s.length())
    {
        if (isdigit(s[i]) || s[i] == '.')
            ++i;
        else
            return (1);
    }
    n = atoi(s.c_str());
    if (n > 1000 || n < 0)
        return (2);
    return (0);
}

int check_key(std::string &s)
{
    size_t      c(0);
    size_t      i(0);
    std::string y;
    std::string m;
    std::string d;
    size_t      f;
    size_t      l;
    
    while (i < s.length())
    {
        if (s[i] == '-')
            ++c;
        ++i;
    }
    if (c > 2 || c < 2)
        return (1);
    i = 0;
    while (i < s.length())
    {
        if (!(isdigit(s[i]) || s[i] == '-'))
            return (2);
        ++i;
    }
    f = s.find('-');
    l = s.rfind('-');
    if (f == std::string:: npos || l == std::string::npos)
        return (3);
    y = s.substr(0, f);
    m = s.substr(f + 1, l - f - 1);
    d = s.substr(l + 1);
    if (atoi(y.c_str()) > 2023 || atoi(y.c_str()) < 2009)
        return (4);
    if (atoi(m.c_str()) > 12 || atoi(m.c_str()) < 1)
        return (4);
    if (atoi(d.c_str()) > 31 || atoi(d.c_str()) < 1)
        return (4);
    return (0);
}









//TODO :
//dont forget to add trim when u check the date and value to delete spaces !






std::string	trim(const std::string &str, const std::string &charList){
	size_t	Head;
	size_t	Tail;

	Head = str.find_first_not_of(charList);
	Tail = str.find_last_not_of(charList);
	if (Head != std::string::npos)
		return (str.substr(Head, ++Tail - Head));
	return ("");
}


int check_error(std::string &k, std::string &v)
{
    if (check_key(k) < 4 && check_key(k))
    {
        std::cout << "error: invalid date => " << k << std::endl;
        return (1);
    }
    if (check_key(k) == 4)
    {
        std::cout << "error: date out of range => " << k << std::endl;
        return (1);
    }
    if (check_value(v) == 1)
    {
        std::cout << "error: invalid value => " << v << std::endl;
        return (2);
    }
    if (check_value(v) == 2)
    {
        std::cout << "error: value out of range => " << v << std::endl;
        return (2);
    }
    return (0);
}

void calculate_bitcoin(std::string p, std::map<std::string, float> &m)
{
    char            *ptr;
    float           b;
    std::string     t;
    std::string     d;
    std::string     v;
    size_t          pos;
    std::ifstream   input;
    std::map<std::string, float>::iterator it;

    input.open(p.c_str());
    if (!input.is_open())
        throw std::string ("failed to open input database");
    std::getline(input, t);
    if (t != "date | value")
        throw std::string ("the input file must always starts with \"date | value\"");
    while (std::getline(input, t))
    {
        pos = t.find(" | ");
        if (pos == std::string::npos){
            std::cout << "error: invalid line => " << t << std::endl;
            continue;
        }
        else
        {
            d = t.substr(0, pos);
            v = t.substr(pos + 3);
            if (check_error(d, v))
                continue;
            it = m.find(d);
            if (it != m.end())
            {
                b = strtof(v.c_str(), &ptr);
                std::cout << d << " => " << v << " => "
                    << it->second * b << std::endl;
            }
            else
            {
                it = m.lower_bound(d);
                if (it == m.begin()) {
                    std::cerr << "error: date out of range => " << d << std::endl;
                    continue;
                }
                it--;
                b = strtof(v.c_str(), &ptr);
                std::cout << it->first << " => " << v << " => "
                    << it->second * b << std::endl;
            }
        }
    }
}