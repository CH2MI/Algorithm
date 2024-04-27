/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    while(true) {
        string s;
        getline(cin, s);
        if (s == "#") break;
    
        int cnt = 0;
        for (auto i : s) {
            switch (i) {
                case 'A': case 'E': case 'I': case 'O': case 'U':
                case 'a': case 'e': case 'i': case 'o': case 'u':
                {
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}
