// #include <bits/stdc++.h>

// using namespace std;

// vector<string> board;
// int n;
// int answer;

// int dx[] = {1, 0};
// int dy[] = {0, 1};

// void find_ans()
// {
//     for (int i = 0; i < n; ++i)
//     {
//         for (int ii = 0; ii < n; ++ii)
//         {
//             if (ii + 1 < n)
//             {
//                 if (board[i][ii] == board[i][ii + 1]){

//                 }
                    
//             }
//             if (i + 1 < n)
//             {
//                 if (board[i][ii] == board[i + 1][ii])
//                 {
                    
//                 }
//             }
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     cin >> n;

//     for (int i = 0; i < n; ++i)
//     {
//         string line;
//         cin >> line;
//         board.push_back(line);
//     }

//     for (int col = 0; col < n; ++col)
//     {
//         for (int row = 0; row < n; ++row)
//         {
//             if (col < n - 1)
//             {
//                 swap(board[col][row], board[col+1][row]));
//             }
//             if (row < n - 1)
//             {
//                 swap(board[col][row], board[col][row + 1]);
//             }
//         }
//     }
//     return 0;
// }