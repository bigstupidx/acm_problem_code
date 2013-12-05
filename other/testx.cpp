#include <iostream>

using namespace std;

template <int N>
struct Factorial
{
    enum {value = Factorial::value * N};
};
 
template <>
struct Factorial<1>
{
    enum {value = 1};
};
 
int main(int argc, const char *argv[])
{
    std::cout << Factorial::value << std::endl;
    std::cout << Factorial::value << std::endl;
 
    return 0;
}
