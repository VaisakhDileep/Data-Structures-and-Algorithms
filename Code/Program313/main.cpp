/*
Created by  : Vaisakh Dileep
Date        : 9, July, 2021
Description : This program demonstrates depth first search for a weighed undirected graph represented using adjacency matrix.
*/

#include<iostream>

#include<iomanip>

#include<vector>

using namespace std;

namespace Weighed_Undirected_Graph_Using_Adjacency_Matrix // Weighed Undirected Graph is designed using Adjacency Matrix representation.
{
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

    void create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
    {
        if(wu_graph == nullptr)
        {
            throw string {"ERROR - Invalid operation, graph is not valid ....."};
        }

        for(int i {0}; i < num_edges; i++)
        {
            try
            {
                add_edge_weighed_undirected_graph(wu_graph, w_edges[i]);
            }
            catch(string &ex)
            {
                throw string {"ERROR - Invalid operation, given set of edges is not valid ....."};
            }
        }
    }

    void handle_create_weighed_undirected_graph(Weighed_Undirected_Graph *wu_graph, Weighed_Edge *w_edges, int num_edges)
    {
        try
        {
            create_weighed_undirected_graph(wu_graph, w_edges, num_edges);
        }
        catch(string &ex)
        {
            cout<<ex;
        }
    }
}

using namespace Weighed_Undirected_Graph_Using_Adjacency_Matrix;

void depth_first_search(Weighed_Undirected_Graph *wu_graph, int node, int *visited)
{
    if(visited[node] == 0)
    {
        cout<<node<<" ";

        visited[node] = 1;

        for(int i {0}; i < wu_graph->A->size(); i++)
        {
            if((wu_graph->A->at(node)->at(i) != INT_MAX) and (visited[i] == 0)) // Not necessary to include "visited[i] == 0", but saves recursive calls.
            {
                depth_first_search(wu_graph, i, visited);
            }
        }
    }
}

void handle_depth_first_search(Weighed_Undirected_Graph *wu_graph, int root = 0)
{
    if(wu_graph == nullptr)
    {
        cout<<"ERROR - Invalid operation, graph is not valid .....";

        return ;
    }

    if((wu_graph->A == nullptr) or (wu_graph->A->size() == 0))
    {
        cout<<"ERROR - Invalid operation, graph is empty .....";

        return ;
    }

    if(root < 0)
    {
        cout<<"ERROR - Invalid root vertex, vertex cannot be negative .....";

        return ;
    }

    depth_first_search(wu_graph, root, new int[wu_graph->A->size()] {0});
}

int main()
{
    Weighed_Undirected_Graph wu_graph {};

    Weighed_Edge w_edges[9] {Weighed_Edge {0, 1, 10}, Weighed_Edge {0, 2, 20}, Weighed_Edge {0, 3, 30}, Weighed_Edge {1, 2, 40}, Weighed_Edge {3, 4, 50}, Weighed_Edge {2, 4, 60}, Weighed_Edge {4, 5, 70}, Weighed_Edge {4, 6, 80}, Weighed_Edge {3, 2, 90}};

    handle_create_weighed_undirected_graph(&wu_graph, w_edges, 9);

    cout<<"wu_graph: \n";
    display_weighed_undirected_graph(&wu_graph);
    cout<<"\n";

    cout<<"DFS(wu_graph): ";
    handle_depth_first_search(&wu_graph);
    cout<<"\n";

    handle_depth_first_search(&wu_graph, -1);
    cout<<"\n";

    return 0;
}