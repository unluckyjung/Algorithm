#include <bits/stdc++.h>

int main()
{
    int t;
    int n1, n2;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%d %d", &n1, &n2);
        printf("Case #%d: %d\n", i, n1 + n2);
    }
    return 0;
}