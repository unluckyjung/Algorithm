#include <bits/stdc++.h>
int main()
{
    char s[100];

    while (scanf("%[^\n]\n", s) == 1)   //맨 마지막에 \n를 넣어서 공백문자까지 받아오기를 기대해야 한다.
    {
        printf("%s\n", s);
    }
    return 0;
}