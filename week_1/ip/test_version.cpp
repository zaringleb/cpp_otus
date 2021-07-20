#define BOOST_TEST_MODULE test_ip

#include "ip_filter.cpp"
#include <boost/test/unit_test.hpp>
#include <sstream>

BOOST_AUTO_TEST_SUITE(test_ip)

BOOST_AUTO_TEST_CASE(test_ip_out)
{
    std::stringstream ss;
    ip4_adress ip({1, 123, 2, 4});
    ss << ip;
    BOOST_CHECK(ss.str() == std::string("1.123.2.4"));
}

BOOST_AUTO_TEST_CASE(test_ip_in)
{
    std::stringstream ss("1.123.2.4");
    ip4_adress ip;
    std::array<unsigned char, 4> adress{1, 123, 2, 4};
    ss >> ip;
    BOOST_CHECK(ip.adress == adress);
}

}
