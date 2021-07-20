#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>

struct ip4_adress {
    std::array<unsigned char, 4> adress; // better to use uint?
    unsigned char & operator[] (int index);
    unsigned char operator[] (int index) const;
};
 
unsigned char & ip4_adress::operator[] (int index)
{
    return adress[index];
}

unsigned char ip4_adress::operator[] (int index) const
{
    return adress[index];
}


std::istream& operator>>(std::istream& os, ip4_adress& ip) {
    int tmp;
    
    for(int i=0; i < 3; i++) {
        os >> tmp;
        ip[i] = tmp;
        char c;
        os.get(c);
        if (c != '.') {
            throw std::invalid_argument("ip adress separator shoud be .");
        }
    }
    os >> tmp;
    ip[3] = tmp;
    return os;
}


std::ostream& operator<<(std::ostream& os, const ip4_adress& ip) { // ip4_adress better be a const
    for(auto i=0; i < 3; i++) {
        os << +ip[i] << ".";
    }
    os << +ip[3];
    return os;
}

bool operator<(ip4_adress& lhs, ip4_adress& rhs) {
    return lhs.adress < rhs.adress;
}

template <typename F>
void print_ip_pool(const std::vector<ip4_adress> & ip_pool, F&& filter) {
    for (auto ip: ip_pool) {
        if (filter(ip)) {
            std::cout << ip << std::endl;
        }
    }
}

