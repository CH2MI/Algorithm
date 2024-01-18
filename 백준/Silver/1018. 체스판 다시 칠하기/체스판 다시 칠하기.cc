#include <iostream>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;
	cin.ignore();
	char** a = new char*[M];
	for (int i = 0; i < M; i++) {
		a[i] = new char[N];
		for (int j = 0; j < N; j++) 
			a[i][j] = cin.get();
		cin.ignore();
	}
	int score = 65;
	for (int i = 0; i < M - 7; i++) {
		for (int j = 0; j < N - 7; j++) {
			int t, s1 = 0, s2 = 0;
			if (a[i][j] == 'W') t = 1;
			else t = 0;
			for (int i1 = i; i1 < i + 8; i1++) {
				for (int j1 = j; j1 < j + 8; j1++) {
					int temp = (i1 + j1) % 2;
					if (t && !temp && a[i1][j1] == 'B') s1++;
					else if (t && temp && a[i1][j1] == 'W') s1++;
					else if (!t && !temp && a[i1][j1] == 'W') s1++;
					else if (!t && temp && a[i1][j1] == 'B') s1++;
					else s2++;
				}
			}
			if (s1 > s2) s1 = s2;
			if (score > s1) score = s1;
		}
	}
	cout << score;
}