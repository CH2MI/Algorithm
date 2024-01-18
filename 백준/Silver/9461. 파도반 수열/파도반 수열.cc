#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int N;
		cin >> N;
		vector<long long int> v;
		v.insert(v.begin(), { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 });
		if (N < 11) cout << v[N] << '\n';
		else {
			for (int i = 11; i <= N; i++) {
				v.push_back(v[i - 1] + v[i - 5]);
			}
			cout << v[N] << '\n';
		}
	}
}