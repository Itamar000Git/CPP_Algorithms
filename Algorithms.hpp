//itamarbabai98@gmail.com
#ifndef ALGORITHMS_HEADER
#define ALGORITHMS_HEADER
#include "Graph.hpp"
namespace graphs
{
    class Algorithm{
    private:
        int V;
    public:
        Algorithm(int num);
        Graph BFS(Graph &gr , int s);
        
        Graph main_DFS(Graph &gr , int s);
        void DFS_visit(Graph &gr , int u , int*color , int *pi ,int *d , int *f, int &time);

        Graph dijkstra(Graph &gr , int s);
        void relax(int u , int v , int w, int *d,  int *pi);

        Graph prim(Graph &gr);
        Graph kruskal(Graph &gr);

    };


}   

#endif