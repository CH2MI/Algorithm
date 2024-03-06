#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int N;
	cin >> N;

	int suma = 0, sumb = 0;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		suma += t;
	}
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		sumb += t;
	}
	cout << sumb << ' ' << suma;
}