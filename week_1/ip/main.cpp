#include <algorithm>
#include "ip_filter.h"

template <typename F>
void print_ip_pool(const std::vector<ip4_adress> & ip_pool, F&& filter) {
    for (auto ip: ip_pool) {
        if (filter(ip)) {
            std::cout << ip << std::endl;
        }
    }
}

int main()
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