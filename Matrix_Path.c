#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//�迭�� �������
void print_array (int array[][5])
{
    for (int i = 0; i < 25; i++) {
        //hi , ro �������� ����
        int lo = i / 5;    //�� 
        int hi = i % 5;    //��
        if (hi == 0)
            printf("\n");
        printf("%d ", array[lo][hi]);
    }
    printf("\n\n");
}


// ������ ��� -> 2���� ��ķ� ��ȯ���ִ� �Լ�
void matrixFolder(int origin_one[25] , int origin_two[][5])
{
    for (int i = 0; i < 25; i++) {
        int lo = i / 5;    //�� 
        int hi = i % 5;    //��
        origin_two[lo][hi] = origin_one[i];
    }
}


//max ��� ��� ���ϴ� �Լ�
void matrixPath(int matrix[][5], int modified[][5])
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 0 && j == 0) /*i,j = 0 �̹Ƿ� 0��0�� ����*/
                modified[0][0] = matrix[0][0];
            else if (i == 0 && j != 0) /*���� ���� ���ذ��鼭 ���������� �̵�*/
                modified[0][j] = modified[i][j - 1] + matrix[i][j];
            else if (i != 0 && j == 0) /*������ ���� ���ذ��鼭 �������� �̵�*/
                modified[i][j] = modified[i - 1][j] + matrix[i][j];
            else {
                modified[i][j] = modified[i - 1][j] + matrix[i][j];
                if (modified[i - 1][j] < modified[i][j - 1])
                    modified[i][j] = modified[i][j - 1] + matrix[i][j];
            }
        }
    }
}

//��� ��� �Լ�
void findPath(int matrix[][5], int modified[][5], int path[][5])
{
    int row = 4;
    int col = 4;
    while (row >= 0 && col >= 0)
    {   
        path[row][col] = 1;
        int value = modified[row][col] - matrix[row][col];
        if (col == 0) /* col = 0 �̶�� �ش� row �������� ���� ��� ���*/
            row--;
        else if (row == 0) /* row = 0 �̶�� �ش� col �������� ���� ��� ���*/
            col--;
        else if (value == modified[row - 1][col])     /*��� ������*/
            row--;
        else
            col--;
    }
}


/* ���� �Լ��� */

//��� ����ġ ����Լ�
void executeCalculatePath(int origin_one[25],int origin_two[][5], int modified[][5])
{
    matrixFolder(origin_one, origin_two);
    
    printf(" +++++++++ calculate Path Matrix : Start +++++++++\n");
    matrixPath(origin_two, modified);
    print_array(modified);
    printf(" +++++++++ calculate Path Matrix : End +++++++++\n");
    printf("\n\n");
}

//��� ��� �Լ� (������ ��� Ȱ��)
void executeprintPath(int matrix[][5], int modified[][5], int path[][5])
{
    printf(" +++++++++ print Path : Start +++++++++\n");
    printf(" 0 = ��� �ƴ�\n 1 = ��� \n");
    findPath(matrix, modified, path);
    print_array(path);
    printf(" +++++++++ print Path : End +++++++++\n");
}



int main()
{
    /*�ʿ��ѹ迭 ����*/
    int origin_two[5][5] = { 0, };
    int origin_one[25] = { 0,8,13,18,20,3,0,7,8,10,4,11,0,10,7,6,6,7,0,11,10,6,2,1,0 };
    int modified[5][5] = { 0, };
    int path[5][5] = { 0, };
   
    
    executeCalculatePath(origin_one , origin_two , modified);
    executeprintPath(origin_two , modified , path);

    return 0;
}