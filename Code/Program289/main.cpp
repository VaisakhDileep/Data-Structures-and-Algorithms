/*
Created by  : Vaisakh Dileep
Date        : 30, June, 2021
Description : This program displays a weighed directed graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Node
{
    int vertex;

    int weight;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

struct Weighed_Directed_Graph
{
    Linked_list **A;

    int n;
};

namespace prototype_1 // Here we print every vertex.
{
    void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
    {
        if(wd_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < wd_graph->n; i++)
        {
            cout<<setw(3)<<left<<i;

            if(wd_graph->A[i] == nullptr)
            {
                cout<<" -> "<<"X\n";
            }
            else
            {
                Node *last {wd_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }
}

namespace prototype_2 // Here we print only the vertices that have at least one edge.
{
    void display_weighed_directed_graph(Weighed_Directed_Graph *wd_graph)
    {
        if(wd_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < wd_graph->n; i++)
        {
            if(wd_graph->A[i] == nullptr)
            {
                continue;
            }
            else
            {
                cout<<setw(3)<<left<<i;

                Node *last {wd_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -["<<setw(3)<<last->weight<<"]-> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }
}

int main()
{
    Weighed_Directed_Graph wd_graph {new Linked_list*[3] {}, 3};

    wd_graph.A[0] = new Linked_list {new Node {2, 10, nullptr}};

    wd_graph.A[2] = new Linked_list {new Node {4, 15, nullptr}};

    wd_graph.A[0]->head->next = new Node {7, 45, nullptr};

    cout<<"wd_graph [prototype 1]: \n";
    prototype_1::display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    cout<<"wd_graph [prototype 2]: \n";
    prototype_2::display_weighed_directed_graph(&wd_graph);
    cout<<"\n";

    return 0;
}