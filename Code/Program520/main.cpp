/*
Created by  : Vaisakh Dileep
Date        : 10, December, 2021
Description : This program sorts a string using count sort.
*/

#include<iostream>

using namespace std;

void sort_string(string *str) // This method will only work for strings that contain only lower-case characters.
{
    if(str == nullptr)
    {
        throw string {"ERROR - Invalid operation, string is not valid ....."};
    }

    int char_count[26] {};

    for(int i {0}; i < str->size(); i++)
    {
        if(!islower(str->at(i)))
        {
            throw string {"ERROR - Invalid operation, string should only contain lower-case alphabets ....."};
        }

        char_count[str->at(i) - 'a']++;
    }

    int idx {0};

    for(int i {0}; i < 26; i++)
    {
        for(int j {0}; j < char_count[i]; j++)
        {
            str->at(idx) = 'a' + i;

            idx++;
        }
    }
}

void handle_sort_string(string *str)
{
    try
    {
        sort_string(str);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    string str {"franklinclinton"};

    cout<<"str[before]: "<<str<<"\n\n";

    handle_sort_string(&str);

    cout<<"str[after]: "<<str<<"\n";

    return 0;
}