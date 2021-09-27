#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool isValidSudoku(vector<vector<char>> &board)
{
    int rowIndex = 0;
    for (auto row: board)
    {
        int colIndex = 0;
        for (auto col: row)
        {
            if (col != '.')
            {
                //Check row for validity
                if (count(row.begin(), row.end(), col) > 1)
                {
                    return false;
                } 
                //Check column for validity
                int columnRepeatCount = 0;
                for (auto row: board)
                {
                    if (row[colIndex] == col)
                    {
                        columnRepeatCount++;
                    }
                    if (columnRepeatCount >  1)
                    {
                        return false;
                    }
                }
                //Check Block
                int blockRepeats = 0;
                int rowBlockStart = rowIndex - rowIndex % 3;
                int colBlockStart = colIndex - colIndex % 3;
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        char value = board[rowBlockStart + i][colBlockStart + j];
                        if (value == col)
                        {
                            blockRepeats++;
                        }

                        if (blockRepeats > 1)
                        {
                            return false;
                        }
                    }
                } 
            }
            colIndex++;
        }
        rowIndex++;
    }
    return true;
}
int main()
{
    vector<vector<char>> board = {vector<char> {'5','3','.','.','7','.','.','.','.'}, 
                                  vector<char> {'6','.','.','1','9','5','.','.','.'}, 
                                  vector<char> {'.','9','8','.','.','.','.','6','.'}, 
                                  vector<char> {'8','.','.','.','6','.','.','.','3'}, 
                                  vector<char> {'4','.','.','8','.','3','.','.','1'}, 
                                  vector<char> {'7','.','.','.','2','.','.','.','6'}, 
                                  vector<char> {'.','6','.','.','.','.','2','8','.'}, 
                                  vector<char> {'.','.','.','4','1','9','.','.','5'}, 
                                  vector<char> {'.','.','.','.','8','.','.','7','9'}};
    bool isValid = isValidSudoku(board);
    cout << isValid << endl;

}