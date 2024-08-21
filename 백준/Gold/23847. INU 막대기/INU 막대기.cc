#include <iostream>
#include <algorithm>
using namespace std;

int N;

int L[6];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	cin >> N;

	while (N--) {
		string s;
		int len;
		cin >> s >> len;
		
		if (s == "II") L[0] += len;
		else if (s == "NN") L[1] += len;
		else if (s == "UU") L[2] += len;
		else if (s == "IN" || s == "NI") L[3] += len;
		else if (s == "NU" || s == "UN") L[4] += len;
		else L[5] += len;	
	}

	int mx = 0;
	
	// I, N, U 각각으로만 구성될 때
	if (!L[3] && !L[4] && !L[5]) mx = max({ L[0], L[1], L[2] });

	// I-N, U로 구성될 때
	else if (L[3] && !L[4] && !L[5]) mx = max({ L[2], L[0] + L[1] + L[3] });

	// N-U, I로 구성될 때
	else if (!L[3] && L[4] && !L[5]) mx = max({ L[0], L[1] + L[2] + L[4] });

	// U-I, N로 구성될 때
	else if (!L[3] && !L[4] && L[5]) mx = max({ L[1], L[0] + L[2] + L[5] });

	// I-N-U로 구성될 때
	else mx = L[0] + L[1] + L[2] + L[3] + L[4] + L[5];

	cout << mx;
}