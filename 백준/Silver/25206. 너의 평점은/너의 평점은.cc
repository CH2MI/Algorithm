#include <iostream>
#include <string>
using namespace std;

int main() {
	float sumCredit = 0.0f, sum = 0.0f, average;
	for (int i = 0; i < 20; i++) {
		string s, grade;
		float credit;
		cin >> s >> credit >> grade;
		sumCredit += credit;
		if (grade == "A+")
			sum += credit * 4.5f;
		else if (grade == "A0")
			sum += credit * 4.0f;
		else if (grade == "B+")
			sum += credit * 3.5f;
		else if (grade == "B0")
			sum += credit * 3.0f;
		else if (grade == "C+")
			sum += credit * 2.5f;
		else if (grade == "C0")
			sum += credit * 2.0f;
		else if (grade == "D+")
			sum += credit * 1.5f;
		else if (grade == "D0")
			sum += credit * 1.0f;
		else if (grade == "P")
			sumCredit -= credit;
	}
	average = sum / sumCredit;
	cout << average;
}