#include <bits/stdc++.h>
int main()
{
    int n;
    int number;
    int sum = 0;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%1d", &number);  //1은 한자리 길이 만큼씩 뺴온다는 이야기이다. 2면 두자리씩 뺴온다.
        sum += number;
    }
    printf("%d", sum);
    return 0;
}