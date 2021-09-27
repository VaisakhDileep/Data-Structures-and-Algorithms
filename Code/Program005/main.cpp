/*
Created by  : Vaisakh Dileep
Date        : 26, April, 2021
Description : This program helps to understand pointer to a structure.
*/

#include<iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void display_rectangle(Rectangle temp)
{
    cout<<"Length : "<<temp.length<<"\n";
    cout<<"Breadth: "<<temp.breadth;
}

void display_rectangle(Rectangle *temp)
{
    cout<<"Length : "<<temp->length<<"\n";
    cout<<"Breadth: "<<temp->breadth;
}

int main()
{
    Rectangle r1 {10, 15};

    Rectangle *p {&r1}; // Declaration + Initialization

    p -> length = 20;
    p -> breadth = 30;

    cout<<"r1: \n";
    display_rectangle(r1); // Rectangle object.
    cout<<"\n";
    
    cout<<"*p: \n";
    display_rectangle(p); // Rectangle object pointer.
    cout<<"\n";

    p = new Rectangle {40, 60}; // Dynamically created Rectangle object.

    cout<<"*p: \n";
    display_rectangle(p);
    cout<<"\n";

    return 0;
}