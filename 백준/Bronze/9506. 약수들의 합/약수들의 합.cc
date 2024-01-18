#include <iostream>
#include <vector>
using namespace std;

int main() {
	while (true) {
		int n;
		vector<int> a;
		cin >> n;
		if (n == -1) break;
		int sum = 0;
		for (int i = 1; i <= n / 2; i++) {
			if (n % i == 0) {
				sum += i;
				a.push_back(i);
			}
		}
		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < a.size(); i++) {
				cout << a[i];
				if (i != a.size() - 1) cout << " + ";
			}
		}
		else cout << n << " is NOT perfect.";	
		cout << endl;
	}
}