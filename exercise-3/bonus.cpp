#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

struct Abc {
    char a;
    int b;
    char c;
};

int main(){
    Abc abc;
    abc={'a',5,'b'};
    auto byte_ptr=reinterpret_cast<char*>(&abc);
    for (size_t i = 0; i < sizeof(abc)+1; ++i) {
        std::cout  << std::hex << static_cast<int>(byte_ptr[i]) << "\n";
    }
    cout<<abc.a;
}