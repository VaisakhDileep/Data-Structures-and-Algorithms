/*
Created by  : Vaisakh Dileep
Date        : 8, October, 2021
Description : This program checks if the knight situated at the top left corner of the chess board(8x8) can visit all the positions at most once.
*/

#include<iostream>

#include<vector>

#include<iomanip>

using namespace std;

bool is_valid_move(vector<vector<int>*> *chess_board, int row, int column)
{
    if((row >= 0) and (row < 8) and (column >= 0) and (column < 8) and (chess_board->at(row)->at(column) == 0))
    {
        return true;
    }

    return false;
}

bool knights_tour(vector<vector<int>*> *chess_board, int row, int column, vector<pair<int, int>> &moves, int current_move)
{
    if(current_move == 65)
    {
        return true;
    }

    for(int i {0}; i < moves.size(); i++)
    {
        int new_row {row + moves[i].first};

        int new_column {column + moves[i].second};

        if(is_valid_move(chess_board, new_row, new_column) == true)
        {
            chess_board->at(new_row)->at(new_column) = current_move;

            if(knights_tour(chess_board, new_row, new_column, moves, current_move + 1) == true)
            {
                return true;
            }

            chess_board->at(new_row)->at(new_column) = 0;
        }
    }

    return false;
}

bool handle_knights_tour(vector<vector<int>*> **chess_board)
{
    if(chess_board == nullptr)
    {
        cout<<"ERROR - Invalid operation, given chess board is not valid .....";

        return false;
    }

    vector<pair<int, int>> moves {};

    moves.push_back(pair<int, int> {-1, -2});
    moves.push_back(pair<int, int> {-2, -1});
    moves.push_back(pair<int, int> {-2, 1});
    moves.push_back(pair<int, int> {-1, 2});
    moves.push_back(pair<int, int> {1, 2});
    moves.push_back(pair<int, int> {2, 1});
    moves.push_back(pair<int, int> {2, -1});
    moves.push_back(pair<int, int> {1, -2});

    *chess_board = new vector<vector<int>*>(8, nullptr);

    for(int i {0}; i < 8; i++)
    {
        (*chess_board)->at(i) = new vector<int>(8, 0);
    }

    (*chess_board)->at(0)->at(0) = 1;

    return knights_tour(*chess_board, 0, 0, moves, 2);
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
            cout<<setw(2)<<chess_board->at(i)->at(j)<<" ";
        }

        cout<<"\n";
    }
}

int main()
{
    vector<vector<int>*> *chess_board {new vector<vector<int>*> {}};

    cout<<"handle_knights_tour(chess_board): "<<handle_knights_tour(&chess_board)<<"\n\n";

    cout<<"chess board:\n";
    display_chess_board(chess_board);
    cout<<"\n";

    return 0;
}