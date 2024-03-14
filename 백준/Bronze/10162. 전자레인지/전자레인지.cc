#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int T;
	cin >> T;
	
	int a = 0, b = 0, c = 0;
	
	a = T / 300;
	T %= 300;
	b = T / 60;
	T %= 60;
	c = T / 10;
	
	// 나머지가 남으면 T초를 맞출 수 없다.
	if (T % 10 != 0) cout << "-1";
	else cout << a << ' ' << b << ' ' << c;
}
