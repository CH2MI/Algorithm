#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, count = 0;
	set<int> A, B;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		int t;
		cin >> t;
		A.insert(t);
	}
	for (int i = 0; i < b; i++) {
		int t;
		cin >> t;
		if (!A.count(t)) count++;
		B.insert(t);
	}
	for (auto iter = A.begin(); iter != A.end(); iter++) 
		if (!B.count(*iter)) count++;
	
	cout << count;
}