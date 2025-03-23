//itamarbabai98@gmail.com
#include <iostream>
#include <limits> 
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"

namespace graphs
{   
    Algorithm::Algorithm(int num){
        V=num;
    }

    Graph Algorithm::BFS(Graph gr , int s)  {
        int vertex_num = gr.get_vertex(); 
        int inf = std::numeric_limits<int>::max();
        int color [vertex_num]{0}; //0 = W , 1 = G, 2 = B
        int d[vertex_num];
        int pi[vertex_num];
        for( int j =0 ;j< vertex_num ; j++){
            d[j]=inf;
            pi[j]=-1;
        }
           
        int u,adj;

        Queue Q = Queue(vertex_num);
        color[s] = 1;
        d[s]=0;
        Q.push(s);
        while(!Q.is_empty()){
            u=Q.pop();
            adj=gr.get_size(u);
            for(int i=0; i<adj; i++){///not the correct adj neeed to add function that 
                if(color[i]==0){        //color[gr[u][i].neigbor]
                    color[i]=1;
                    d[i]=d[i]+1;
                    pi[i]=u;
                    Q.push(i);
                }
            }
            color[u]=2;
        }
        //need to create graph from d and pi
        
        return NULL;
    }
    // Graph DFS(Graph gr , int s);
    // Graph dijkstra(Graph gr , int s);
    // Graph prim(Graph gr);
    // Graph kruskal(Graph gr);



}