#include<iostream>
using namespace std;
//백준 3190 뱀
//boj.kr/3190

int n;
int apple_num;
int cmd_num;

int board[101][101];
char cmd_time[11000];
//배열에 있는 시간에 주어진 명령어.
int snakeh_x[11000]; int snakeh_y[11000];
//배열에 있는 시간에 있던 뱀의 머리위치
int head_x, head_y;
int tail_time;

//1씩 움직이면 우측 회전.
//3씩 움직이면 좌측 회전
int dx[] = { 0, 1 , 0, -1 };
int dy[] = { 1, 0 , -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//freopen("input.txt", "r", stdin);

	cin >> n >> apple_num;
	
	while (apple_num--) {
		int nx, ny;
		cin >> nx >> ny;
		board[nx][ny] = 1;
	}
	cin >> cmd_num;
	while (cmd_num--) {
		int time; char cmd;
		cin >> time >> cmd;
		cmd_time[time] = cmd;
	}

	int time = 0;
	head_x = 1; head_y = 1;
	snakeh_x[time] = head_x; snakeh_y[time] = head_y;
	tail_time = time;
	//나중에 tail 좌표 찾을때 사용함.
	//snakeh_x[tail_time], snakeh_y[tail_time] 으로 찾으면된다.

	board[head_x][head_y] = -1;

	int dir = 0;

	while (1) {
		time++;
		head_x += dx[dir]; head_y += dy[dir];
		if (head_x < 1 or head_x > n or head_y < 1 or head_y > n)break;
		if (board[head_x][head_y] == -1) break;


		snakeh_x[time] = head_x;
		snakeh_y[time] = head_y;

		if (board[head_x][head_y] == 0) {
			//접근한곳이 그냥 땅이라면?
			//꼬리가 하나 줄어들어야함.

			//board[head_x][head_y] = -1; // 밖에서 한번에 처리함.
			int tail_x = snakeh_x[tail_time]; int tail_y = snakeh_y[tail_time];
			//꼬리의 좌표를 찾는다. 
			//tail_time에 뱀이 머리가 존재했던 좌표를 찾으면된다.
			
			board[tail_x][tail_y] = 0;
			tail_time++;

		}
		board[head_x][head_y] = -1;

		//if (cmd_time[time] == 'D') dir += (dir + 1) % 4;
		//if (cmd_time[time] == 'L') dir += (dir + 3) % 4;		
		//실수한 부분.
		if (cmd_time[time] == 'D') dir = (dir + 1) % 4;
		if (cmd_time[time] == 'L') dir = (dir + 3) % 4;
		
	}


	cout << time;

	return 0;
}