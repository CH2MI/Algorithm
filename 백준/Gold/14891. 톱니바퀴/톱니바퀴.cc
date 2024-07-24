#include <iostream>
using namespace std;

inline void CW(short& value) {
	short t = value & 1;
	value = (t << 7) | (value >> 1);
}

inline void CCW(short& value) {
	short t = value & 128;
	value = ((t >> 7) | (value << 1)) & 255;
}

bool Is_Rotate(short left, short right) {
	short l = (left & 32) >> 5;
	short r = (right & 2) >> 1;
	return l ^ r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	short arr[4] = { 0, };

	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			arr[i] <<= 1;
			arr[i] |= s[j] - '0';
		}
	}

	int K; cin >> K;

	for (int cnt = 0; cnt < K; cnt++) {
		int num, ro;
		cin >> num >> ro;
		int rotate[4];
		rotate[num - 1] = ro;

		int lro = ro;
		for (int i = num - 1; i > 0; i--) {

			if (rotate[i] == 0) rotate[i - 1] = 0;
			else if (Is_Rotate(arr[i - 1], arr[i])) {
				rotate[i - 1] = lro * -1;
				lro *= -1;
			}
			else rotate[i - 1] = 0;
		}

		int rro = ro;
		for (int i = num - 1; i < 3; i++) {
			if (rotate[i] == 0) rotate[i + 1] = 0;
			else if (Is_Rotate(arr[i], arr[i + 1])) {
				rotate[i + 1] = rro * -1;
				rro *= -1;
			}
			else rotate[i + 1] = 0;
		}

		for (int i = 0; i < 4; i++) {
			if (rotate[i] == 1) {
				CW(arr[i]);
			}
			else if (rotate[i] == -1) {
				CCW(arr[i]);
			}
		}
	}

	int sum = 0;
	for (int i = 0; i < 4; i++)
		sum += ((arr[i] & 128) >> 7) << i;
	cout << sum << '\n';
	
}
