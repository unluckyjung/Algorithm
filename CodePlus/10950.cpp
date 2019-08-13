#include<bits/stdc++.h>

int main() {
    int t;
	int n1, n2;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n1, &n2);   //이런식으로 하나하나씩 결과를 내도 괜찮다.
        printf("%d\n", n1+n2);
    }
	return 0;
}