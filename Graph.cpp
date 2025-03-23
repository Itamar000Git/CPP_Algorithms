//itamarbabai98@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Edge.hpp"

namespace graphs
{

    Graph::Graph(int num)
        {
            V=num; 
            g_list = new Edge*[V]();
            size = new int[V]();
        
        }

        void Graph::addEdge (int v, int u, int w)
        {

            if (v >= V || u >= V || v < 0 || u < 0) { //not neccesary
                std::cout << "Invalid vertex index!" << std::endl;
                return;
            }

            if(g_list[v]==nullptr){
                g_list[v]=new Edge[V]();
            }

    
            g_list[v][size[v]] = Edge(u, w);
            size[v]++;
    
           
            if (g_list[u] == nullptr) {
                g_list[u] = new Edge[V](); 
            }
         
            g_list[u][size[u]] = Edge( v, w);
            size[u]++;
            
     
        }

        bool Graph::has_edge(int v, int u){ //checks if the edge exist
            for(int i=0; i<size[v]; i++){
                if(g_list[v][i].get_neighbor()==u){
                    return true;
                }
            }

            for(int i=0; i<size[u]; i++){
                if(g_list[u][i].get_neighbor()==v){
                    return true;
                }
            }
            return false;
        }

        void Graph::removeEdge (int v , int u)
        {
            if(has_edge(v,u)){
                for(int i=0; i<size[v];i++){
                    if(g_list[v][size[i]].get_neighbor()==u){
                        for(int j=i;j<size[v]; j++){
                            g_list[v][j]=g_list[v][j+1];
                        }
                        size[v]--;
                        break;
                    }
                }

                for(int i=0; i<size[u];i++){
                    if(g_list[u][size[i]].get_neighbor()==v){
                        for(int j=i;j<size[v]; j++){
                            g_list[u][j]=g_list[u][j+1];
                        }
                        size[u]--;
                        break;
                    }
                }
                
            }else{ 
                std::cout<<"Edge not Exist"<<std::endl;
            }
        }
        void Graph::print_graph ()
        {
           
            for(int i=0; i<V ;i++){
                std::cout<<"{";
                std::cout<<i<<" :";
                for(int j=0; j<size[i]; j++){
                    std::cout<<"V - "<<g_list[i][j].get_neighbor()<<" W - " <<g_list[i][j].get_weigt();
                    if(j!=size[i]-1){
                        std:: cout << " , ";
                    }
                }
                std::cout<<"}"<<std::endl;
            }

        }

        int Graph::get_vertex()
        {
            return V;
        }

        int Graph::get_size(int u) //returns the number of edges
        {
           return size[u];
        }
        
        Graph::~Graph()
        {
            for(int i=0;i<V; i++){
                delete[] g_list[i];
                
            }
            delete[] g_list;
            delete[] size;
        }

} // namespace graph          