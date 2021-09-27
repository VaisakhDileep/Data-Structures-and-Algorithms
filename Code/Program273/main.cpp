/*
Created by  : Vaisakh Dileep
Date        : 27, June, 2021
Description : This program displays a directed graph.
*/

#include<iostream>

#include<iomanip>

using namespace std;

struct Node
{
    int vertex;

    Node *next;
};

struct Linked_list
{
    Node *head;
};

struct Directed_Graph
{
    Linked_list **A;

    int n;
};

namespace prototype_1 // Here we print every vertex.
{
    void display_directed_graph(Directed_Graph *d_graph)
    {
        if(d_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < d_graph->n; i++)
        {
            cout<<setw(3)<<left<<i;

            if(d_graph->A[i] == nullptr)
            {
                cout<<" -> "<<"X\n";
            }
            else
            {
                Node *last {d_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }
}

namespace prototype_2 // Here we print only the vertices that have at least one edge.
{
    void display_directed_graph(Directed_Graph *d_graph)
    {
        if(d_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < d_graph->n; i++)
        {
            if(d_graph->A[i] == nullptr)
            {
                continue;
            }
            else
            {
                cout<<setw(3)<<left<<i;

                Node *last {d_graph->A[i]->head};

                while(last != nullptr)
                {
                    cout<<" -> "<<setw(3)<<last->vertex;

                    last = last->next;
                }
                cout<<"\n";
            }
        }
    }
}

int main()
{
    Directed_Graph d_graph {new Linked_list*[3] {}, 3};

    d_graph.A[0] = new Linked_list {new Node {2, nullptr}};
    
    d_graph.A[2] = new Linked_list {new Node {5, nullptr}};

    d_graph.A[0]->head->next = new Node {7, nullptr};

    cout<<"d_graph [prototype 1]: \n";
    prototype_1::display_directed_graph(&d_graph); // "X" means no edges for the vertex.
    cout<<"\n";

    cout<<"d_graph [prototype 2]: \n";
    prototype_2::display_directed_graph(&d_graph);
    cout<<"\n";

    return 0;
}