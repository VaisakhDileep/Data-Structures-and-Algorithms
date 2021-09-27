/*
Created by  : Vaisakh Dileep
Date        : 17, August, 2021
Description : This program finds the length of the union of line segments(Klee's algorithm).
*/

#include<iostream>

#include<vector>

#include<algorithm>

using namespace std;

int length_union_line_segments(vector<pair<int, int>> *line_segments)
{
    vector<pair<int, bool>> points(2 * line_segments->size());

    for(int i {0}; i < line_segments->size(); i++)
    {
        points.at(2 * i) = pair<int, bool> {line_segments->at(i).first, false}; // "false" means starting point of the line.

        points.at(2 * i + 1) = pair<int, bool> {line_segments->at(i).second, true}; // "true" means ending point of the line.
    }

    sort(points.begin(), points.end());

    int length {}, counter {};

    for(int i {0}; i < points.size(); i++)
    {
        if(counter > 0)
        {
            length += (points.at(i).first - points.at(i - 1).first);
        }

        if(points.at(i).second == true)
        {
            counter--;
        }
        else
        {
            counter++;
        }
    }
    return length;
}

int main()
{
    vector<pair<int, int>> line_segments {{3, 5}, {1, 5}, {5, 10}, {11, 15}};

    cout<<"length_union_line_segments(line_segments): "<<length_union_line_segments(&line_segments)<<"\n";

    return 0;
}