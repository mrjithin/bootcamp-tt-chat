#include <iostream>
#include <string>
#include <optional>

using namespace std;

int main(){
    string s1="abcds";
    string s2="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaasaaaa";
    optional<int> a=5;
    optional<int> b(nullopt_t);
    cout<<s1<<"\n";
    cout<<s2<<"\n";
    cout<<*a<<"\n";
    cout<<*b<<"\n";
    return 0;
}