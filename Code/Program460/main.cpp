/*
Created by  : Vaisakh Dileep
Date        : 5, October, 2021
Description : This program checks if a hamiltonian path exists in the undirected graph.
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

bool is_valid(Undirected_Graph *u_graph, vector<int> *path, int vertex, int path_index)
{
    if(path_index == 0)
    {
        return true;
    }

    if(u_graph->A->at(path->at(path_index - 1))->at(vertex) == 0)
    {
        return false;
    }

    for(int i {0}; i < path_index; i++)
    {
        if(path->at(i) == vertex)
        {
            return false;
        }
    }

    return true;
}

bool check_hamiltonian_path_undirected_graph(Undirected_Graph *u_graph, vector<int> *vertices, vector<int> *path, int path_index)
{
    if(path_index == vertices->size())
    {
        return true;
    }

    for(int i {0}; i < vertices->size(); i++)
    {
        if(is_valid(u_graph, path, vertices->at(i), path_index) == true)
        {
            path->at(path_index) = vertices->at(i);

            if(check_hamiltonian_path_undirected_graph(u_graph, vertices, path, path_index + 1))
            {
                return true;
            }

            path->at(path_index) = -1;
        }
    }

    return false;
}

bool handle_check_hamiltonian_path_undirected_graph(Undirected_Graph *u_graph, vector<int> *path)
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

    path->resize(vertices_vector.size());

    for(int i {0}; i < path->size(); i++)
    {
        path->at(i) = -1;
    }

    return check_hamiltonian_path_undirected_graph(u_graph, &vertices_vector, path, 0);
}

void display_hamiltonian_path(vector<int> *path)
{
    if(path == nullptr)
    {
        return ;
    }

    for(int i {0}; i < path->size(); i++)
    {
        if(path->at(i) == -1)
        {
            cout<<"Hamiltonian path does not exist .....";

            return ;
        }
    }

    for(int i {0}; i < path->size(); i++)
    {
        cout<<path->at(i)<<" ";
    }
}

int main()
{
    Undirected_Graph u_graph {new vector<vector<int>*> {}};

    // Edge edges[5] {Edge {1, 0}, Edge {0, 4}, Edge {1, 2}, Edge {2, 4}, Edge {4, 3}}; // This graph contains a hamiltonian path.

    Edge edges[4] {Edge {0, 1}, Edge {1, 4}, Edge {1, 2}, Edge {2, 3}}; // This graph does not contain a hamiltonian path.

    handle_create_undirected_graph(&u_graph, edges, 4);

    cout<<"u_graph: \n";
    display_undirected_graph(&u_graph);
    cout<<"\n";

    vector<int> path {};

    cout<<"check_hamiltonian_path(u_graph, path): "<<handle_check_hamiltonian_path_undirected_graph(&u_graph, &path)<<"\n";

    cout<<"path: ";
    display_hamiltonian_path(&path);
    cout<<"\n";

    return 0;
}