//itamarbabai98@gmail.com

#ifndef GRAPG_HEADER
#define GRAPG_HEADER
#include "Edge.hpp"

namespace graphs
{
    class Graph{
    private:
        int V;
        int *size;
        Edge **g_list;
        
    public:
        Graph(int num);
        Graph(const Graph &other);
        Graph& operator=(const Graph &other){
            if (this != &other) {
                for (int i = 0; i < V; i++) {
                    delete[] g_list[i];
                }
                delete[] g_list;
                delete[] size;

                V = other.V;
                size = new int[V]();
                g_list = new Edge*[V]();

                if (g_list == nullptr || size == nullptr) {
                    throw std::runtime_error("Memory allocation failed");
                    return *this;
                }

                for (int i = 0; i < V; i++) {
                    size[i] = other.size[i];
                    g_list[i] = new Edge[size[i]]();

                    if (g_list[i] == nullptr) {
                        throw std::runtime_error("Memory allocation failed");
                        return *this;
                    }

                    for (int j = 0; j < size[i]; j++) {
                        g_list[i][j] = other.g_list[i][j];
                    }
                }
            }
            return *this;

        }
        void addEdge (int u,int v, int w = 1 , bool directed=false);
        void removeEdge (int v , int u,bool directed = false);
        void print_graph ();
        bool has_edge(int u ,int v, bool directed);
        int get_vertex();
        void get_vertex_list( int u, int * list);
        int get_size(int u);
        int get_neigbor(int src , int neigbor_num);
        int get_weight(int u, int v);
        void set_weight(int indexi,int indexj, int val);
        void create_graph(Graph &new_g , int * pi ,int *d, int vertex_num , Graph &original);
        int get_graph_wheight();
        
        ~Graph();
    };

        
} // namespace graphs
#endif

