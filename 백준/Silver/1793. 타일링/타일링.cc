#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Integer {
	string _value;

public:
	Integer(string value = "0") {
		_value = value;
	}

	Integer operator +(const Integer& B) {
		string result;
		string a;
		string b;

		if (_value.size() > B._value.size()) {
			a = _value; b = B._value;
		}
		else {
			a = B._value; b = _value;
		}

		int len_a = a.size(), len_b = b.size();
		int carry = 0;
		
		for (int i = 0; i < len_a; i++) {
			int x = a[len_a - i - 1] - '0';
			int y = 0;
			if (len_b - i - 1 >= 0) y = b[len_b - i - 1] - '0';

			int ret = x + y + carry;
	
			result.push_back(ret % 10 + '0');
			carry = ret / 10;
		}
		if (carry) result.push_back(carry + '0');
		reverse(result.begin(), result.end());
		return Integer(result);
	}

	friend ostream& operator<<(ostream& os, const Integer& A);
};
	
ostream& operator<<(ostream& os, const Integer& A) {
	os << A._value;
	return os;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vector<Integer> dp(251);

	dp[0] = dp[1] = Integer("1");

	for (int i = 2; i <= 250; i++) {
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];
	}

	int n;
	while (cin >> n) {
		cout << dp[n] << '\n';
	}
}