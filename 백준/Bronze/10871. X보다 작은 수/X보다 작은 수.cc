#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> a;
	int N, X;
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		if (t < X) a.push_back(t);
	}
	for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
}