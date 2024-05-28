#include <iostream>

using namespace std;

int K;
int sudoku[10][10];

bool isValid(int row, int col, int num)
{
	for (int i = 0; i < 9; ++i)
	{
		if (sudoku[row][i] == num)
			return false;
	}

	for (int i = 0; i < 9; ++i)
	{
		if (sudoku[i][col] == num)
			return false;
	}

	int nRow = row - row % 3;
	int nCol = col - col % 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (sudoku[i + nRow][j + nCol] == num)
				return false;
		}
	}

	return true;
}

bool bfs()
{
	int row;
	int col;
	bool isEmpty = false;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] == 0)
			{
				row = i;
				col = j;
				isEmpty = true;
				break;
			}
		}
		if (isEmpty)
			break;
	}

	if (!isEmpty)
		return true;

	for (int num = 1; num <= 9; ++num)
	{
		if (isValid(row, col, num))
		{
			sudoku[row][col] = num;
			if (bfs())
				return true;

			sudoku[row][col] = 0;
		}
	}
	
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			int n;
			cin >> n;
			sudoku[i][j] = n;
		}
	}

	bfs();

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cout << sudoku[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}