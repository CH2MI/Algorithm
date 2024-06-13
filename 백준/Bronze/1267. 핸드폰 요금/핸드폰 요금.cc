#include <iostream>
using namespace std;
 
int main(void)
{
	int N, m = 0, y = 0;
	cin >> N;
 
	while(N--) {
		int t; cin >> t;
		y += (t / 30 + 1) * 10;
		m += (t / 60 + 1) * 15;
	}
	if (m < y) cout << "M " << m;
	else if (m > y) cout << "Y " << y;
	else cout << "Y M " << m;
 
}