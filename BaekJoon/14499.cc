#include<iostream>
using namespace std;

//백준 14499 주사위 굴리기 (삼성 역량테스트 기출)
//boj.kr/14499

int board[21][21];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0 ,0 };

int dice[6];

int n, m;
int x, y;

int cmd_num;

void move_dice(int dir) {
	//주사위 굴리기.
	int next_dice[6] = { 0 };
	//다음 주사위 위치를 저장할 배열.
	//주사위가 굴러갈떄마다 바뀌는 전개도의 모양을 생각해보면 된다.
	if (dir == 0) {
		next_dice[0] = dice[0];
		next_dice[1] = dice[4];
		next_dice[2] = dice[2];
		next_dice[3] = dice[5];
		next_dice[4] = dice[3];
		next_dice[5] = dice[1];
		//동쪽으로 구르게 될경우.
		//다음 주사위의 0번과 2번 인덱스의 값은 그대로 있고.
		//다른 인덱스의 값들은 한칸씩 바뀐다.
	}
	else if (dir == 1) {
		next_dice[0] = dice[0];
		next_dice[1] = dice[5];
		next_dice[2] = dice[2];
		next_dice[3] = dice[4];
		next_dice[4] = dice[1];
		next_dice[5] = dice[3];
	}
	else if (dir == 2) {
		next_dice[0] = dice[1];
		next_dice[1] = dice[2];
		next_dice[2] = dice[3];
		next_dice[3] = dice[0];
		next_dice[4] = dice[4];
		next_dice[5] = dice[5];
	}
	else if (dir == 3) {
		next_dice[0] = dice[3];
		next_dice[1] = dice[0];
		next_dice[2] = dice[1];
		next_dice[3] = dice[2];
		next_dice[4] = dice[4];
		next_dice[5] = dice[5];
	}
	for (int i = 0; i < 6; ++i) {
		dice[i] = next_dice[i];
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> n >> m >> x >> y >> cmd_num;
	for (int i = 0; i < n; ++i) {
		for (int ii = 0; ii < m; ++ii) {
			cin >> board[i][ii];
		}
	}

	while (cmd_num--) {
		int dir; cin >> dir;
		dir--;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 or nx >= n or ny < 0 or ny >= m)continue;

		move_dice(dir);

		if (board[nx][ny] == 0) {
			board[nx][ny] = dice[3];
			//주사위의 바닥을 가르키는 인덱스는 3
		}
		else {
			dice[3] = board[nx][ny];
			board[nx][ny] = 0;
		}
		x = nx; y = ny;
		cout << dice[1] << "\n";
	}

	return 0;
}