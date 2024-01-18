#include <iostream>
#include <string>
using namespace std;

int main() {
	string A, B;
	cin >> A >> B;
	int lenA = A.size(), lenB = B.size();
	int** dp = new int* [lenA + 1];
	for (int i = 0; i <= A.size(); i++) 
		dp[i] = new int[lenB + 1]();
	
	for (int i = 1; i <= lenA; i++) {
		for (int j = 1; j <= lenB; j++) {
			if (A[i - 1] == B[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else 
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[lenA][lenB];
}
