#include<stdio.h>
int C[14][15]; //xm 이 13개이므로 필요한 행은 +1개한 14개 
			   //Yn 이 14개이므로 필요한 열은 +1개한 15개
char Xm[13] = { 'q','r','s','t','u','a','b','s','f','d','h','i','j' };
char Yn[14] = { 'r','s','t','g','d','h','t','j','k','u','v','a','b','s' };


/*
int C[4][4];
char Xm[3] = { 'a' , 'b', 'c' };
char Yn[3] = { 'a' , 'c', 'b' };
*/
// Test for LCS ,적은 수로 맞는지 제대로 돌아가는지 확인하기 위해서 썻다가 확인 후 필요없어져서 주석처리했습니다.


int max(int x, int y) { //들어온 수중에서 더 큰 수를 찾는 함수
	if (x >= y) //x가 y보다 크거나 같으면
		return x; // x 리턴
	else //아니라면, 즉 y가 x보다 크면
		return y;// y리턴
}


int LCS(int m, int n) { //LCS 함수

	int i, j;

	for (i = 0; i < m; i++) //C 배열의 각 첫번째 행,열은 0으로 초기화 합니다.
		C[i][0] = 0;
	for (j = 0; j < n; j++)
		C[0][j] = 0;

	for (i = 1; i <= m; i++) //Xm 배열 탐색
		for (j = 1; j <= n; j++) //Yn 배열 탐색
			if (Xm[i - 1] == Yn[j - 1]) //Xm과 Yn이 같다면? , 여기서 -1인이유는 Xm[i]부터 한다면 Xm[1]이 되어서, q가아닌 r부터 비교를 합니다.
				C[i][j] = C[i - 1][j - 1] + 1; //이전 행 -1 ,열 -1 의 자리값에 +1 값을 해주어서 그 자리에 넣어줍니다.
			else
				C[i][j] = max(C[i - 1][j], C[i][j - 1]); // 그렇지 않다면 C[i - 1][j], C[i][j - 1] 중 더 큰놈을 찾아서 잘아서 넣어줍니다.

	return C[m][n]; //LCS를 리턴해줍니다.

}

int main(void) {

	printf("LCS is %d \n \n", LCS(13, 14)); //LCS값을 받아옵니다.
	//printf("LCS  is %d \n\n", LCS(3,3)); //Test for LCS 적은 수로 맞는지 제대로 돌아가는지 확인하기 위해서 썻다가 확인 후 필요없어져서 주석처리했습니다.


	for (int i = 0; i < 14; i++) { //C 배열을 출력합니다.
		for (int j = 0; j < 15; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}

	return 0;

}