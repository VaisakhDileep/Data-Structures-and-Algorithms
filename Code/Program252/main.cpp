/*
Created by  : Vaisakh Dileep
Date        : 20, June, 2021
Description : This program displays an undirected graph.
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

struct Undirected_Graph
{
    Linked_list **A;

    int n;
};

namespace prototype_1 // Here we print every vertex.
{
    void display_undirected_graph(Undirected_Graph *u_graph)
    {
        if(u_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < u_graph->n; i++)
        {
            cout<<setw(3)<<left<<i;

            if(u_graph->A[i] == nullptr)
            {
                cout<<" -> "<<"X\n";
            }
            else
            {
                Node *last {u_graph->A[i]->head};

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
    void display_undirected_graph(Undirected_Graph *u_graph)
    {
        if(u_graph == nullptr)
        {
            return ;
        }

        for(int i {0}; i < u_graph->n; i++)
        {
            if(u_graph->A[i] == nullptr)
            {
                continue;
            }
            else
            {
                cout<<setw(3)<<left<<i;

                Node *last {u_graph->A[i]->head};

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
    Undirected_Graph u_graph {new Linked_list*[5] {}, 5};

    u_graph.A[0] = new Linked_list {new Node {4, nullptr}};
    u_graph.A[4] = new Linked_list {new Node {0, nullptr}};

    u_graph.A[1] = new Linked_list {new Node {3, nullptr}};
    u_graph.A[3] = new Linked_list {new Node {1, nullptr}};

    u_graph.A[3]->head->next = new Node {0, nullptr};
    u_graph.A[0]->head->next = new Node {3, nullptr};

    cout<<"u_graph [prototype 1]: \n";
    prototype_1::display_undirected_graph(&u_graph); // "X" means no edges for the vertex.
    cout<<"\n";

    cout<<"u_graph [prototype 2]: \n";
    prototype_2::display_undirected_graph(&u_graph);
    cout<<"\n";

    return 0;
}