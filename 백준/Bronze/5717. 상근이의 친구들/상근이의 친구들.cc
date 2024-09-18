#include <iostream>

int main() {
    while (1) {
        int a, b;
        std::cin >> a >> b;
        
        if (!a && !b) {
            break;
        }
        
        std::cout << a + b << '\n';
    }
}