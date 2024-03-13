#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

    int cute[2] = { 0, };
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        
        ++cute[t];
    }
    
    if (cute[0] > cute[1]) cout << "Junhee is not cute!";
    else cout << "Junhee is cute!";
}
