#include<bits/stdc++.h>
using namespace std;

double arr[1000] = { 0, };

int main() {
	int count;
	double sum = 0;
	scanf("%d", &count);
	for (int i = 0; i < count; ++i) {
		scanf("%lf", &arr[i]);
	}

	sort(arr, arr+sizeof(arr) / sizeof(double),greater<double>());
	double max = arr[0];
	for (int i = 0; i < count; ++i) {
		sum += arr[i] / max * 100;
	}
	printf("%lf\n", sum / count);

	return 0;
}