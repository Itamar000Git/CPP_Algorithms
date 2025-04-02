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

        void addEdge (int u,int v, int w , bool directed=false);
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
        ~Graph();
    };

        
} // namespace graphs
#endif

