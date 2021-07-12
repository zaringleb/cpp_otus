#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <algorithm>

struct ip4_adress {
    std::array<int, 4> adress; // better to use uint?
    int& operator[] (int index);
};
 
int& ip4_adress::operator[] (int index)
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


std::ostream& operator<<(std::ostream& os, ip4_adress& ip) { // ip4_adress better be a const
    for(int i=0; i < 3; i++) {
        os << ip[i] << ".";
    }
    os << ip[3];
    return os;
}

bool operator<(ip4_adress& lhs, ip4_adress& rhs) {
    return lhs.adress < rhs.adress;
}

template <typename F>
void print_ip_pool(std::vector<ip4_adress> ip_pool, F&& filter) {
    for (auto ip: ip_pool) {
        if (filter(ip)) {
            std::cout << ip << std::endl;
        }
    }
}

int main(int argc, char const *argv[])
{

    try
    {
        std::vector<ip4_adress> ip_pool;
        std::string line;
        while (std::getline(std::cin, line)){
            ip4_adress adress;
            std::stringstream ss(line);
            ss>>adress;
            ip_pool.push_back(adress);
        }

        std::sort(ip_pool.begin(), ip_pool.end());
        std::reverse(ip_pool.begin(), ip_pool.end());

        print_ip_pool(ip_pool, [](auto){return true;});
        print_ip_pool(ip_pool, [](auto ip){return ip[0] == 1;});
        print_ip_pool(ip_pool, [](auto ip){return ip[0] == 46 && ip[1] == 70;});
        print_ip_pool(ip_pool, [](auto ip){return ip[0] == 46 || ip[1] == 46 || ip[2] == 46 || ip[3] == 46;});

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
