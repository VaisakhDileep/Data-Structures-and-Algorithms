/*
Created by  : Vaisakh Dileep
Date        : 19, June, 2021
Description : This program creates a weighed undirected graph from user.
*/

#include<iostream>

#include<iomanip>

#include<limits>

#include<vector>

using namespace std;

struct Weighed_Undirected_Graph
{
    vector<vector<int>*> *A;
};

struct Weighed_Edge
{
    int vertex_1;

    int vertex_2;

    int weight;
};

void display_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if((wu_graph == nullptr) or (wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        cout<<"[\n]";

        return ;
    }

    cout<<"[\n     ";
    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        cout<<setw(3)<<i<<" ";
    }
    cout<<"\n";

    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        cout<<setw(3)<<left<<i<<right<<"[ ";
        for(int j {0}; j < wu_graph->A->size(); j++)
        {
            if(wu_graph->A->at(i)->at(j) == INT_MAX)
            {
                cout<<"INF"<<" ";
            }
            else
            {
                cout<<setw(3)<<wu_graph->A->at(i)->at(j)<<" ";
            }
        }
        cout<<"]\n";
    }
    cout<<"]";
}

void delete_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        return ;
    }

    for(int i {0}; i < wu_graph->A->size(); i++)
    {
        delete wu_graph->A->at(i);
    }

    delete wu_graph->A;
}

void add_edge_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge w_edge)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        wu_graph->A = new vector<vector<int>*> {new vector<int> {}};
    }

    if((w_edge.vertex_1 < 0) or (w_edge.vertex_2 < 0))
    {
        throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
    }

    if((w_edge.vertex_1 < wu_graph->A->size()) and (w_edge.vertex_2 < wu_graph->A->size()))
    {
        wu_graph->A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = wu_graph->A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;
    }
    else
    {
        int new_n {(w_edge.vertex_1 > w_edge.vertex_2) ? w_edge.vertex_1 + 1 : w_edge.vertex_2 + 1};

        Weighed_Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

        for(int i {0}; i < new_n; i++)
        {
            temp.A->at(i) = new vector<int>(new_n, INT_MAX);
        }

        for(int i {0}; i < wu_graph->A->size(); i++)
        {
            for(int j {0}; j < wu_graph->A->at(0)->size(); j++)
            {
                temp.A->at(i)->at(j) = wu_graph->A->at(i)->at(j);
            }
        }

        temp.A->at(w_edge.vertex_1)->at(w_edge.vertex_2) = temp.A->at(w_edge.vertex_2)->at(w_edge.vertex_1) = w_edge.weight;

        delete_weighed_undirected_graph(wu_graph);

        wu_graph->A = temp.A;

        for(int i {0}; i < wu_graph->A->size(); i++)
        {
            if(wu_graph->A->at(i)->at(i) == INT_MAX)
            {
                wu_graph->A->at(i)->at(i) = 0;
            }
        }
    }
}

void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    if(wu_graph == nullptr)
    {
        throw string {"ERROR - Invalid operation, graph is not valid ....."};
    }

    int num_edges {};

    cout<<"Enter the number of edges present in the graph: ";

    cin>>num_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout<<"\nStart entering the edges in the format \"{vertex_1, vertex_2, weight}\": \n";

    for(int i {0}; i < num_edges; i++)
    {
        int vertex_1 {}, vertex_2 {}, weight {};

        string user_input {};

        cout<<"> ";

        getline(cin, user_input);

        istringstream iss {user_input};

        iss.ignore(); // This will ignore "{".

        iss>>vertex_1;

        iss.ignore(); // This will ignore ",".

        iss>>vertex_2;

        iss.ignore(); // This will ignore ",".

        iss>>weight;

        try
        {
            add_edge_weighed_undirected_graph(wu_graph, Weighed_Edge {vertex_1, vertex_2, weight});
        }
        catch(string &ex)
        {
            throw string {"ERROR - Invalid operation, given edge is not valid ....."};
        }
    }
}

void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph)
{
    try
    {
        create_weighed_undirected_graph(wu_graph);
    }
    catch(string &ex)
    {
        cout<<ex;
    }
}

int main()
{
    Weighed_Undirected_Graph wu_graph {};

    handle_create_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    return 0;
}