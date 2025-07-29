#include<iostream>
using namespace std;

int main()
{
    int matrix[4][3] = {{1,2,3}, {5,9,6}, {4,8,1}};
    int rows=3, cols = 3;
    int tar = 8; 
    pair<int,int> idx = {-1, -1};

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(matrix[i][j]==tar)
            {
                idx = {i,j};
                cout << idx.first << " " << idx.second;
                break;
            }
        }
    }
}