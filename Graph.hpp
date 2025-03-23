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
        void addEdge (int v, int u, int w);
        void removeEdge (int v , int u);
        void print_graph ();
        bool has_edge(int v, int u);
        int get_vertex();
        int get_size(int u);
        ~Graph();
    };

        
} // namespace graphs
#endif

