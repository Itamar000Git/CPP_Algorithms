//itamarbabai98@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Edge.hpp"
#include "praiority_Q.hpp"

namespace graphs
{

    Graph::Graph(int num)
        {
            V=num; 
            g_list = new Edge*[V]();
            size = new int[V]();
        
        }

    void Graph::addEdge ( int u,int v, int w , bool directed)
        {

            if (v >= V || u >= V || v < 0 || u < 0) { //not neccesary
                std::cout << "Invalid vertex index!" << std::endl;
                return;
            }


           
            if (g_list[u] == nullptr) {
                g_list[u] = new Edge[V](); 
            }
         
            g_list[u][size[u]] = Edge( v, w);
            size[u]++;
            
            if(!directed){
            if(g_list[v]==nullptr){
                g_list[v]=new Edge[V]();
            }
            
    
            g_list[v][size[v]] = Edge(u, w);
            size[v]++;
    
        }
     
        }

        bool Graph::has_edge(int u, int v, bool directed) { // checks if the edge exists

            int list[V];
            int neighbor_num = this->get_size(u);

            for (int i = 0; i < neighbor_num; i++) {
                if(g_list[u][i].get_neighbor()==v){
                    return true;
                }
            }

            if (directed) {
                return false;
            }
        
            int list2[V];

            for (int i = 0; i < neighbor_num; i++) {
                if(g_list[v][i].get_neighbor()==u){
                    return true;
                }
            }
            
        
            return false; 
        }

        void Graph::removeEdge ( int u, int v, bool directed)
        {
            //int s1=size[u];
            int list[V];
            get_vertex_list(u,list);
            if(has_edge(u,v,directed)){   
                for(int i=0; i<size[u];i++){
                   if(list[i]==v){
                        for(int j=i;j<size[v]; j++){
                            g_list[u][j]=g_list[u][j+1];
                        }
                        size[u]--;
                        break;
                    }
                }
                if(directed==false){
                    //int s2=size[v];
                    int list2[V];
                    get_vertex_list(v,list2);
                    for(int i=0; i<size[v];i++){
                        if(list2[i]==u){
                            for(int j=i;j<size[v]; j++){
                                g_list[v][j]=g_list[v][j+1];
                            }
                        size[v]--;
                        break;
                        }
                    }
                }
            }
                
            else{ 
                std::cout<<"Edge not Exist"<<std::endl;
            }
        }
        void Graph::print_graph ()
        {
            std::cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\print\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<std::endl;
            for(int i=0; i<V ;i++){
                std::cout<<"{";
                std::cout<<i<<" :";
                for(int j=0; j<size[i]; j++){
                    std::cout<<"(v- "<<g_list[i][j].get_neighbor()<<" w- " <<g_list[i][j].get_weigt();
                    if(j!=size[i]-1){
                        std:: cout << ") , ";
                    }
                }
                std::cout<<")}"<<std::endl;
            }


        }

        int Graph::get_vertex()
        {
            return V;
        }
        void Graph::get_vertex_list(int u , int * list) //insert to given list all neighbors indexs
        {  
        
            int j=0;
            for(int i = 0 ;i<V; i++){
                if(has_edge(u,i,true)){
                    list[j]=i;
                    j++;
                }
            }

        }

        int Graph::get_size(int u) //returns the number of edges
        {
            
           return size[u];
        }

        int Graph::get_neigbor(int src , int neigbor_num) //returns the neigbor by order
        {
            return g_list[src][neigbor_num].get_neighbor();
        }

        void Graph::create_graph(Graph &new_g , int * pi ,int *d, int vertex_num , Graph &original){
            for( int i = 0; i <vertex_num ; i++){
                if(pi[i]>=0){ // build the tree by order for bfs
                    //int weight = original.get_weight(pi[i], i); 
                    int weight =d[i];
                    new_g.addEdge(pi[i], i, weight , true);
                    //new_g.addEdge(pi[i],i, g_list[pi[i]][i].get_weigt());
                }
            }
            //new_g.print_graph();
        }

        int Graph::get_weight(int u, int v) //returnt the weight of tow
        {
            int adj =size[u];
            for (int i =0 ; i <adj ; i++)
            {
                if(g_list[u][i].get_neighbor() == v){
                    return g_list[u][i].get_weigt();
                }
            }
            return -1; 
        }

        void Graph::set_weight(int indexi,int indexj ,int val){
            g_list[indexi][indexj].set_weigt(val);
        }


        Graph::~Graph() {
            if(g_list !=nullptr){
            for (int i = 0; i < V; i++) {
                if (g_list[i] != nullptr) {
                    delete[] g_list[i];  
                    //g_list[i] = nullptr;
                }
            }
            delete []g_list;
            //g_list=nullptr;  
            delete[] size;
            //size=nullptr;    
            }
        }



} // namespace graph          