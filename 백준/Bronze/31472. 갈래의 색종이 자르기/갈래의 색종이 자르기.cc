#include <iostream>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int W;
	cin >> W;
	W <<= 1;
	int n = (int)sqrt(W);
	cout << (n << 2);
}