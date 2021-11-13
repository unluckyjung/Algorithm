#include<bits/stdc++.h>
#define pp pair<int,int>
#define x first
#define y second

using namespace std;

const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
bool visited[52][52];
queue<pp> q;
int n, m;

class Solution {
public:

    void Bfs(vector<vector<int>>& image, int newColor, int start_color) {
        while (!q.empty()) {
            pp cur = q.front(); q.pop();
            
            for (int dir = 0; dir < 4; ++dir) {
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (image[nx][ny] != start_color) continue;
                visited[nx][ny] = true;
                image[nx][ny] = newColor;
                q.push({ nx,ny });
            }
        }
    }

	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        memset(visited, false, sizeof(visited));
        q = queue<pp>();
        n = image.size();
        m = image[0].size();

        visited[sr][sc] = true;
        int start_color = image[sr][sc];
        image[sr][sc] = newColor;

        q.push({ sr,sc });
        Bfs(image, newColor, start_color);

        return image;
	}
};


int main() {

    vector<vector<int>> input_vec{ {0,0,0},{0,0,0} };
    int sr = 1, sc = 0, newColor = 2;

    Solution ret;
    vector<vector<int>> result = ret.floodFill(input_vec, sr, sc, newColor);

    for (int i = 0; i < n; ++i) {
        for (int ii = 0; ii < m; ++ii) {
            cout << result[i][ii] << " ";
        }
        cout << "\n";
    }
    return 0;
}