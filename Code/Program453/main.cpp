/*
Created by  : Vaisakh Dileep
Date        : 30, September, 2021
Description : This program checks if the graph can be coloured with at most 'n' colours(backtracking approach).
*/

#include<iostream>

#include<vector>

#include<iomanip>

#include<map>

#include<unordered_set>

using namespace std;

namespace Undirected_Graph_Using_Adjacency_Matrix // Undirected Graph is designed using Adjacency Matrix representation.
{
    struct Undirected_Graph
    {
        vector<vector<int>*> *A;
    };

    struct Edge
    {
        int vertex_1;

        int vertex_2;
    };

    void display_undirected_graph(Undirected_Graph *u_graph)
    {
        if((u_graph == nullptr) or (u_graph->A == nullptr) or (u_graph->A->size() == 0))
        {
            cout<<"[\n]";

            return ;
        }

        cout<<"[\n     ";
        for(int i {0}; i < u_graph->A->size(); i++)
        {
            cout<<setw(3)<<i<<" ";
        }
        cout<<"\n";

        for(int i {0}; i < u_graph->A->size(); i++)
        {
            cout<<setw(3)<<left<<i<<right<<"[ ";
            for(int j {0}; j < u_graph->A->size(); j++)
            {
                cout<<setw(3)<<u_graph->A->at(i)->at(j)<<" ";
            }
            cout<<"]\n";
        }
        cout<<"]";
    }

    void delete_undirected_graph(Undirected_Graph *u_graph)
    {
        if(u_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
        {
            return ;
        }

        for(int i {0}; i < u_graph->A->size(); i++)
        {
            delete u_graph->A->at(i);
        }

        delete u_graph->A;
    }

    void add_edge_undirected_graph(Undirected_Graph *u_graph, Edge edge)
    {
        if(u_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        if((u_graph->A == nullptr) or (u_graph->A->size() == 0))
        {
            u_graph->A = new vector<vector<int>*> {new vector<int> {}};
        }

        if((edge.vertex_1 < 0) or (edge.vertex_2 < 0))
        {
            throw string {"ERROR - Invalid operation, given edge contains negative vertex ....."};
        }

        if((edge.vertex_1 < u_graph->A->size()) and (edge.vertex_2 < u_graph->A->size()))
        {
            u_graph->A->at(edge.vertex_1)->at(edge.vertex_2) = u_graph->A->at(edge.vertex_2)->at(edge.vertex_1) = 1;
        }
        else
        {
            int new_n {(edge.vertex_1 > edge.vertex_2) ? edge.vertex_1 + 1 : edge.vertex_2 + 1};

            Undirected_Graph temp {new vector<vector<int>*>(new_n, nullptr)};

            for(int i {0}; i < new_n; i++)
            {
                temp.A->at(i) = new vector<int>(new_n, 0);
            }

            for(int i {0}; i < u_graph->A->size(); i++)
            {
                for(int j {0}; j < u_graph->A->at(0)->size(); j++)
                {
                    temp.A->at(i)->at(j) = u_graph->A->at(i)->at(j);
                }
            }

            temp.A->at(edge.vertex_1)->at(edge.vertex_2) = temp.A->at(edge.vertex_2)->at(edge.vertex_1) = 1;

            delete_undirected_graph(u_graph);

            u_graph->A = temp.A;
        }
    }

    void create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
    {
        if(u_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        for(int i {0}; i < num_edges; i++)
        {
            try
            {
                add_edge_undirected_graph(u_graph, edges[i]);
            }
            catch(string &ex)
            {
                throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
            }
        }
    }

    void handle_create_undirected_graph(Undirected_Graph *u_graph, Edge *edges, int num_edges)
    {
        try
        {
            create_undirected_graph(u_graph, edges, num_edges);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

using namespace Undirected_Graph_Using_Adjacency_Matrix;

bool is_valid(Undirected_Graph *u_graph, map<int, string> *vertex_to_colour, int vertex, string colour) // Here we check only the given vertex's edges.
{
    for(int i {0}; i < u_graph->A->size(); i++)
    {
        if(i == vertex) // self loop.
        {
            continue;
        }

        if((u_graph->A->at(vertex)->at(i) == 1) and (vertex_to_colour->find(i) != vertex_to_colour->end()))
        {
            if(colour == (*vertex_to_colour)[i])
            {
                return false;
            }
        }
    }

    return true;
}

bool can_colour_graph(Undirected_Graph *u_graph, vector<string> *colours, map<int, string> *vertex_to_colour, vector<int> *vertices, int vertex_index)
{
    if(vertex_index == vertices->size())
    {
        return true;
    }

    for(int i {0}; i < colours->size(); i++)
    {
        if(is_valid(u_graph, vertex_to_colour, vertices->at(vertex_index), colours->at(i)))
        {
            (*vertex_to_colour)[vertices->at(vertex_index)] = colours->at(i);

            if(can_colour_graph(u_graph, colours, vertex_to_colour, vertices, vertex_index + 1) == true)
            {
                return true;
            }

            (*vertex_to_colour).erase(vertices->at(vertex_index));
        }
    }

    return false;
}

bool handle_can_colour_graph(Undirected_Graph *u_graph, vector<string> *colours, map<int, string> *vertex_to_colour)
{
    if(u_graph == nullptr)
    {
        cout<<"ERROR - Invalid operation, given graph is not valid .....";

        return false;
    }

    if(colours == nullptr)
    {
        cout<<"ERROR - Invalid operation, colours array is not valid .....";

        return false;
    }

    if(u_graph->A == nullptr)
    {
        cout<<"ERROR - Invalid operation, given graph is empty .....";

        return false;
    }

    if(colours->size() == 0)
    {
        cout<<"ERROR - Invalid operation, colours array is empty .....";

        return false;
    }

    unordered_set<int> vertices_set {};

    for(int i {0}; i < u_graph->A->size(); i++)
    {
        for(int j {i}; j < u_graph->A->size(); j++)
        {
            if(u_graph->A->at(i)->at(j) == 1)
            {
                vertices_set.insert(i);
                vertices_set.insert(j);
            }
        }
    }

    vector<int> vertices_vector {};

    for(auto itr {vertices_set.begin()}; itr != vertices_set.end(); itr++)
    {
        vertices_vector.push_back(*itr);
    }

    return can_colour_graph(u_graph, colours, vertex_to_colour, &vertices_vector, 0);
}

void display_vertex_colour(map<int, string> *vertex_to_colour)
{
    if(vertex_to_colour == nullptr)
    {
        return ;
    }

    for(auto itr {vertex_to_colour->begin()}; itr != vertex_to_colour->end(); itr++)
    {
        cout<<(itr->first)<<" : "<<(itr->second)<<"\n";
    }
}

int main()
{
    Undirected_Graph u_graph {new vector<vector<int>*> {}};

    Edge edges[6] {Edge {0, 1}, Edge {0, 2}, Edge {1, 3}, Edge {2, 3}, Edge {0, 3}, Edge {1, 2}};

    handle_create_undirected_graph(&u_graph, edges, 6);

    cout<<"u_graph: \n";
    display_undirected_graph(&u_graph);
    cout<<"\n";

    vector<string> colours {"red", "green", "blue"};

    map<int, string> vertex_to_colour {};

    cout<<"can_colour_graph(u_graph, colours): "<<handle_can_colour_graph(&u_graph, &colours, &vertex_to_colour)<<"\n";

    cout<<"vertex_colour: \n";
    display_vertex_colour(&vertex_to_colour);
    cout<<"\n";

    return 0;
}