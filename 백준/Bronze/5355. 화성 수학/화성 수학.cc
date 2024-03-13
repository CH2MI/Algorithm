#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int tc = 0; tc < T; ++tc) {
        double d;
        char c;
        
        cin >> d;
        do {
            c = cin.get();
            switch (c) {
                case '@':
                    d *= 3;
                    break;
                case '%':
                    d += 5;
                    break;
                case '#':
                    d -= 7;
                    break;
            }
        } while(c != '\n');
        
        cout << fixed;
        cout.precision(2);
        cout << d << '\n';
    }
}
