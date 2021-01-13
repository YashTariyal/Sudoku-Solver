#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
bool row(int r ,int col ,int n);
bool coloumn(int r ,int col ,int n);
bool square(int r ,int col ,int n);

int matrix[9][9];
int main()
{
        //variable use
        int gap = 0, r, col, t;
        bool x = 1;
        char c[20];
        cout << "  Write the sudoku problem manually (w) or read from file (r)? ";
        cin >> c[0];
        if(c[0]=='r')
        {
                        cout << "Write the sudoku filename: ";
                        cin >> c;
                        cout << endl;
                        ifstream file(c);
                        for(int i=0;i<9;i++)
                        {
                                for(int j=0;j<9;j++)
                                {
                                        file >> matrix[i][j];
                                        if(!matrix[i][j])
                                                gap++;
                                }
                        }
                        file.close();
        }else if(c[0] == 'w')
        {
                        for(int i=0; i<9; i++)
                                for(int j=0; j<9; j++)
                                {
                                        do{
                                        cout << "Please enter " << i+1 << ". row " << j+1 << ". number: ";
                                        cin >> matrix[i][j];
                                        }while( matrix[i][j] <= 0 &&  matrix[i][j] > 10);
                                        if( matrix[i][j] == 0)
                                                gap++;
                                }
        }else
        {
                        cout << "exiting..." << endl;
                        return 0;
        }
        while(gap && x)
        {
                x=0;
                for(int i=0; i<9; i++)
                {
                        for(int j = 0; j < 9; j++)
                        {
                                if(matrix[i][j] != 0)
                                        continue;
                                t=0;
                                for(int y=1; y<10; y++)
                                {
                                        if(row(i, j, y) && coloumn(i, j, y) && square(i, j, y))
                                        {
                                                if(t == 0)
                                                        t = y;
                                                else
                                                    {
                                                        t = 0;
                                                        break;
                                                    }
                                        }
                                }
                        if(t != 0)
                        {
                                matrix[i][j] = t;
                                x = 1;
                                gap--;
                        }
                }
        }
        }
        if(!x)
                cout << "It cannot be solved" << endl;
        else if(!gap)
                        cout << "solved" << endl;
                cout << endl;
                for(int i=0; i<9; i++)
                {
                        for(int j=0; j<9; j++)
                        {
                                cout << matrix[i][j] << " ";
                        }
                        cout << endl;
                }
        cout << endl;
}

bool row(int r, int col, int n)
{
        for(int g=0; g<9; g++)
        {

                if(matrix[r][g] == n)
                {
                        return 0;
                }
        }
        return 1;
}
bool coloumn(int r, int col, int n)
{
        for(int g=0; g<9; g++)
        {
                if(matrix[g][col] == n)
                        return 0;
        }
        return 1;
}
bool square(int r, int col, int n)
{
        int row = ceil((r+1)/3.);
        int coloumn = ceil((col+1)/3.);
        for(int g=(row - 1)*3; g < ((row - 1)*3 +3); g++)
                for(int h = (coloumn-1)*3; h <((coloumn - 1)*3 +3);h++)
                {
                        if(matrix[g][h] == n)
                                return 0;
                }
        return 1;
}