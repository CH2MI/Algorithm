#include <iostream>
#define PI 3.1415926535897932384626
using namespace std;

int main() {
    double n;
    scanf("%lf", &n);
    printf("%.6lf\n%.6lf", n * n * PI, n * n * 2);
}