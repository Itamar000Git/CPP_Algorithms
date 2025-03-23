//itamarbabai98@gmail.com
#ifndef ALGORITHMS_HEADER
#define ALGORITHMS_HEADER
#include "Graph.hpp"
namespace graphs
{
    class Algorithm{
    private:
        // Graph graph;
        int V;
    public:
        Algorithm(int num);
        Graph BFS(Graph gr , int s);
        Graph DFS(Graph gr , int s);
        Graph dijkstra(Graph gr , int s);
        Graph prim(Graph gr);
        Graph kruskal(Graph gr);

    };


}   

#endif