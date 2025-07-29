#include<iostream>
#include<vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int tar)
{
    int m = mat.size(), n = mat[0].size();
    int r=0, c=n-1;

    while (r<m && c>=0)
    {
        if(tar == mat[r][c])
        {
            return true;
        }
        else if(tar < mat[r][c])
        {
            c--;
        }
        else
        {
            r++;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1,4,7,15},{2,5,8,17},{3,6,9,18},{6,11,13,20},{9,13,15,30}};
    int target = 18;

    cout << searchMatrix(matrix, target);
}