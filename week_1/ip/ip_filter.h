#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>

struct ip4_adress {
    std::array<unsigned char, 4> adress;
    unsigned char & operator[] (int index);
    unsigned char operator[] (int index) const;
};
 

std::istream& operator>>(std::istream& os, ip4_adress& ip);


std::ostream& operator<<(std::ostream& os, const ip4_adress& ip);

bool operator<(ip4_adress& lhs, ip4_adress& rhs);

template <typename F>
void print_ip_pool(const std::vector<ip4_adress> & ip_pool, F&& filter);