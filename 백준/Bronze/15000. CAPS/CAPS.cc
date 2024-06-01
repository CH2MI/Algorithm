#include <iostream>

int main()
{
    std::string s;
    std::cin >> s;
    
    for (auto& i : s) {
        i -= 32;
    }
    
    std::cout << s;
}