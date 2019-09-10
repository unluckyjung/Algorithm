#include <bits/stdc++.h>
using namespace std;

int main()
{
	int hour1, hour2;
	int min1, min2;
	int sec1, sec2;

	int hour, min, sec;

	scanf("%d:%d:%d", &hour1, &min1, &sec1);
	scanf("%d:%d:%d", &hour2, &min2, &sec2);

	sec = sec2 - sec1;
	min = min2 - min1;
	hour = hour2 - hour1;

	if (sec < 0) {
		sec += 60;
		min--;
	}

	if (min < 0) {
		min += 60;
		hour--;
	}

	if (hour < 0) {
		hour += 24;
	}

	printf("%02d:%02d:%02d",hour,min,sec);

	return 0;
}