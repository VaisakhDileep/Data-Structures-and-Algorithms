/*
Created by  : Vaisakh Dileep
Date        : 2, October, 2021
Description : This program arranges 'n' queens in a (n X n) chess board in a way such that they won't attack each other.
*/

#include<iostream>

#include<vector>

using namespace std;

void create_chess_board(vector<vector<int>*> **chess_board, int n) // 'n' is the number of rows or columns.
{
    if(chess_board == nullptr)
    {
        // throw string {"ERROR - Invalid operation, given matrix is not valid ....."}; // Make sure to handle it.

        return ;
    }

    *chess_board = new vector<vector<int>*>(n, nullptr);

    for(int i {0}; i < n; i++)
    {
        (*chess_board)->at(i) = new vector<int>(n, 0);
    }
}

bool is_valid(vector<vector<int>*> *chess_board, int row, int column)
{
    for(int i {0}; i < row; i++) // Check above.
    {
        if(chess_board->at(i)->at(column) == 1)
        {
            return false;
        }
    }

    int r {row - 1}, c {column - 1};

    while((r >= 0) and (c >= 0)) // left-upper diagonal.
    {
        if(chess_board->at(r)->at(c) == 1)
        {
            return false;
        }

        r--;
        c--;
    }

    r = row - 1;
    c = column + 1;

    while((r >= 0) and (c < chess_board->size())) // right-upper diagonal.
    {
        if(chess_board->at(r)->at(c) == 1)
        {
            return false;
        }

        r--;
        c++;
    }

    return true;
}

bool can_place_n_queens(vector<vector<int>*> *chess_board, int row)
{
    if(row == chess_board->size())
    {
        return true;
    }

    for(int i {0}; i < chess_board->size(); i++)
    {
        if(is_valid(chess_board, row, i))
        {
            chess_board->at(row)->at(i) = 1;

            if(can_place_n_queens(chess_board, row + 1) == true)
            {
                return true;
            }

            chess_board->at(row)->at(i) = 0;
        }
    }

    return false;
}

bool handle_can_place_n_queens(vector<vector<int>*> **chess_board, int n)
{
    if(chess_board == nullptr)
    {
        cout<<"ERROR - Invalid operation, given matrix is not valid .....";

        return false;
    }

    if(n <= 0)
    {
        cout<<"ERROR - Invalid operation, size of the matrix cannot be lesser 1 .....";

        return false;
    }

    create_chess_board(chess_board, n);

    return can_place_n_queens(*chess_board, 0);
}

void display_chess_board(vector<vector<int>*> *chess_board)
{
    if(chess_board == nullptr)
    {
        return ;
    }

    for(int i {0}; i < chess_board->size(); i++)
    {
        for(int j {0}; j < chess_board->at(i)->size(); j++)
        {
            cout<<chess_board->at(i)->at(j)<<" ";
        }

        cout<<"\n";
    }
}

int main()
{
    vector<vector<int>*> *chess_board {};

    cout<<"handle_can_place_n_queens(chess_board, 4): "<<handle_can_place_n_queens(&chess_board, 4)<<"\n";

    cout<<"chess_board(chess_board):\n";
    display_chess_board(chess_board);
    cout<<"\n";

    return 0;
}