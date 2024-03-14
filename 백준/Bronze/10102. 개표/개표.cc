#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int V;
	cin >> V;
	cin.ignore();
	
	int vote[2] = { 0, };
	while (V--) {
	    ++vote[cin.get() - 'A'];
	}
	
	if (vote[0] < vote[1]) cout << 'B';
	else if (vote[0] > vote[1]) cout << 'A';
	else cout << "Tie";
}
