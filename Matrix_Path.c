#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//배열을 출력해줌
void print_array (int array[][5])
{
    for (int i = 0; i < 25; i++) {
        int lo = i / 5;    //행 
        int hi = i % 5;    //열
        if (hi == 0)
            printf("\n");
        printf("%d ", array[lo][hi]);
    }
}


// 일차원 행렬 -> 2차원 행렬로 변환해주는 함수
void matrixFolder(int origin_one[25] , int origin_two[][5])
{
    for (int i = 0; i < 25; i++) {
        int lo = i / 5;    //행 
        int hi = i % 5;    //열
        origin_two[lo][hi] = origin_one[i];
    }
}


//max 행렬 경로 구하는 함수
void matrixPath(int matrix[][5], int modified[][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0) 
                modified[0][0] = matrix[0][0];
            else if (i == 0 && j != 0)
                modified[0][j] = modified[i][j - 1] + matrix[i][j];
            else if (i != 0 && j == 0)
                modified[i][j] = modified[i - 1][j] + matrix[i][j];
            else {
                modified[i][j] = modified[i - 1][j] + matrix[i][j];
                if (modified[i - 1][j] < modified[i][j - 1])
                    modified[i][j] = modified[i][j - 1] + matrix[i][j];
            }
        }
    }
}

//경로 출력 함수
void findPath(int matrix[][5], int modified[][5], int path[][5])
{
    int row = 4;
    int col = 4;
    while (row >= 0 && col >= 0)
    {   
        path[row][col] = 1;
        int value = modified[row][col] - matrix[row][col];
        if (col == 0)
            row--;
        else if (row == 0)
            col--;
        else if (value == modified[row - 1][col])
            row--;
        else
            col--;
    }
}

int main()
{
    int origin_two[5][5] = { 0, };
    int origin_one[25] = { 0,8,13,18,20,3,0,7,8,10,4,11,0,10,7,6,6,7,0,11,10,6,2,1,0 };
    matrixFolder(origin_one, origin_two);
    int modified[5][5] = { 0, };
    int path[5][5] = { 0, };
    matrixPath(origin_two,  modified);
    print_array(modified);
    printf(" \n");
    findPath(origin_two, modified, path);
    print_array(path);
    return 0;
}