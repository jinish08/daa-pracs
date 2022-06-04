#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int n, int col, int row)
{
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool nqueen(vector<vector<int>> &board, int n, int col)
{
    if (col >= n)
    {
        return true;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, n, col, i))
        {
            board[i][col] = 1;

            if (nqueen(board, n, col + 1))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> board(8, vector<int>(8, 0));
    int n = 8;

    nqueen(board, n, 0);

    for (auto it : board)
    {
        for (auto jt : it)
        {
            cout << jt << " ";
        }
        cout << endl;
    }

    return 0;
}