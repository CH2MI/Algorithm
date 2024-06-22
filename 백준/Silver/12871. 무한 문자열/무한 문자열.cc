#include <iostream>
#include <numeric>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

	int len_s = s.size();
	int len_t = t.size();

	int Lcm = lcm(len_s, len_t);
	
	string S, T;
	for (int i = 0; i < Lcm / len_s; i++) {
		S.append(s);
	}
	for (int i = 0; i < Lcm / len_t; i++) {
		T.append(t);
	}
	cout << (S == T);
}