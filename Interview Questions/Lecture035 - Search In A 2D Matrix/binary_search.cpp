#include<iostream>
#include<vector>
using namespace std;

bool searchInRow(vector<vector<int>>& mat, int target, int row)
{
    int n = mat[0].size();
    int st = 0, end = n-1;
    while (st <= end)
    {
        int mid = st + (end-st)/2;
        if(target == mat[row][mid])
        {
            return true;
        }
        else if(target > mat[row][mid])
        {
            st = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target)
{
    //BS on total rows
    int m = mat.size(), n = mat[0].size();

    int startRow = 0, endRow = m-1;
    while (startRow <= endRow)      
    {
        int midRow = startRow + (endRow - startRow)/2;

        if(target >= mat[midRow][0] && target <= mat[midRow][n-1])
        {
            //found the row => BS on this row
            return searchInRow(mat, target, midRow);
        }
        else if(target >= mat[midRow][n-1])
        {
            //down => right
            startRow = midRow + 1;
        }
        else
        {
            //up => left
            endRow = midRow - 1;
        }
    }
    
}

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{10,18,20},{24,26,31},{33,34,56}};
    int target = 33;
    cout << searchMatrix(matrix, target);
}