/*
Created by  : Vaisakh Dileep
Date        : 1, October, 2021
Description : This program checks if a hamiltonian cycle exists in the undirected graph.
*/

// This algorithm will work only if the graph is connected.

#include<iostream>

#include<vector>

#include<iomanip>

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

bool is_valid(Undirected_Graph *u_graph, vector<int> *cycle, int vertex, int cycle_index)
{
    if(u_graph->A->at(cycle->at(cycle_index - 1))->at(vertex) == 0)
    {
        return false;
    }

    for(int i {0}; i < cycle_index; i++)
    {
        if(cycle->at(i) == vertex)
        {
            return false;
        }
    }

    return true;
}

bool check_hamiltonian_cycle(Undirected_Graph *u_graph, vector<int> *vertices, vector<int> *cycle, int cycle_index, int source)
{
    if(cycle_index == vertices->size())
    {
        cycle->at(cycle_index) = source;

        if(u_graph->A->at(cycle->at(cycle_index - 1))->at(source) == 1)
        {
            return true;
        }

        cycle->at(cycle_index) = -1;

        return false;
    }

    for(int i {0}; i < vertices->size(); i++)
    {
        if(vertices->at(i) == source)
        {
            continue;
        }

        if(is_valid(u_graph, cycle, vertices->at(i), cycle_index) == true)
        {
            cycle->at(cycle_index) = vertices->at(i);

            for(int i {0}; i < cycle->size(); i++)
            {
                cout<<cycle->at(i)<<" ";
            }
            cout<<"\n";

            if(check_hamiltonian_cycle(u_graph, vertices, cycle, cycle_index + 1, source) == true)
            {
                return true;
            }

            cycle->at(cycle_index) = -1;
        }
    }

    return false;
}

bool handle_check_hamiltonian_cycle(Undirected_Graph *u_graph, vector<int> *cycle)
{
    if(u_graph == nullptr)
    {
        cout<<"ERROR - Invalid operation, given graph is not valid .....";

        return false;
    }

    if(u_graph->A == nullptr)
    {
        cout<<"ERROR - Invalid operation, given graph is empty .....";

        return false;
    }

    unordered_set<int> vertices_set {};

    for(int i {0}; i < u_graph->A->size(); i++)
    {
        for(int j {0}; j < u_graph->A->size(); j++)
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

    cycle->resize(vertices_vector.size() + 1);

    for(int i {0}; i < cycle->size(); i++)
    {
        cycle->at(i) = -1;
    }

    int source {vertices_vector[0]};

    cycle->at(0) = source;

    return check_hamiltonian_cycle(u_graph, &vertices_vector, cycle, 1, source);
}

void display_hamiltonian_cycle(vector<int> *cycle)
{
    if(cycle == nullptr)
    {
        return ;
    }

    for(int i {0}; i < cycle->size(); i++)
    {
        if(cycle->at(i) == -1)
        {
            cout<<"Hamiltonian path does not exist.";

            return ;
        }
    }

    for(int i {0}; i < cycle->size(); i++)
    {
        cout<<cycle->at(i)<<" ";
    }
}

int main()
{
    Undirected_Graph u_graph {new vector<vector<int>*> {}};

    // Edge edges[5] {Edge {0, 1}, Edge {1, 2}, Edge {2, 3}, Edge {2, 0}, Edge {3, 0}}; // This graph contains a hamiltonian cycle.

    // Edge edges[7] {Edge {0, 1}, Edge {0, 2}, Edge {1, 2}, Edge {1, 4}, Edge {4, 3}, Edge {2, 3}, Edge {3, 5}}; // This graph does not contain a hamiltonian cycle.

    Edge edges[8] {Edge {0, 1}, Edge {0, 2}, Edge {1, 2}, Edge {1, 4}, Edge {4, 3}, Edge {2, 3}, Edge {3, 5}, Edge {5, 2}}; // This graph contains a hamiltonian cycle.

    handle_create_undirected_graph(&u_graph, edges, 8);

    cout<<"u_graph: \n";
    display_undirected_graph(&u_graph);
    cout<<"\n";

    vector<int> cycle {};

    cout<<"check_hamiltonian_cycle(u_graph, cycle): "<<handle_check_hamiltonian_cycle(&u_graph, &cycle)<<"\n";

    cout<<"cycle: ";
    display_hamiltonian_cycle(&cycle);
    cout<<"\n";

    return 0;
}