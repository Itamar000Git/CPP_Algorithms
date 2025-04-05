//itamarbabai98@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Edge.hpp"
#include "praiority_Q.hpp"

namespace graphs
{

    Graph::Graph(int num)
        {
            if (num <= 0) {
                throw std::invalid_argument("Number of vertices must be positive");
                return;
            }

            V=num; 
            g_list = new Edge*[V]();

            if (g_list == nullptr) {
                throw std::runtime_error("Memory allocation failed");
                return;
            }

            size = new int[V]();

            if (size == nullptr) {
                throw std::runtime_error("Memory allocation failed");
                delete[] g_list; // Clean up previously allocated memory
                return;
            }
        
        }


    Graph::Graph(const Graph &other){
        V = other.V;
        size = new int[V]();
        g_list = new Edge*[V]();

        if (g_list == nullptr || size == nullptr) {
            throw std::runtime_error("Memory allocation failed");
            return;
        }

        for (int i = 0; i < V; i++) {
            size[i] = other.size[i];
            g_list[i] = new Edge[size[i]]();

            if (g_list[i] == nullptr) {
                throw std::runtime_error("Memory allocation failed");
                return;
            }

            for (int j = 0; j < size[i]; j++) {
                g_list[i][j] = other.g_list[i][j];
            }
        }
    }


    void Graph::addEdge ( int u,int v, int w , bool directed)
        {

            if (v >= V || u >= V || v < 0 || u < 0) {
                throw std::out_of_range("Vertex index out of bounds");
                return;
            }
            if(this->has_edge(u,v,true)){
                throw std::runtime_error("Edge already exists");
                return;
            }
            if (g_list[u] == nullptr) {
                g_list[u] = new Edge[V](); 
            }
         
            g_list[u][size[u]] = Edge(v, w);
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
            if (u >= V || v >= V || u < 0 || v < 0) {
                throw std::out_of_range("Vertex index out of bounds");
                return NULL;
            }

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



    void Graph::removeEdge(int u, int v, bool directed) {
        if (u >= V || v >= V || u < 0 || v < 0) {
            throw std::out_of_range("Vertex index out of bounds");
        }

    
        if (has_edge(u, v, directed)) {
            int t = size[u];
            for (int i = 0; i < t; i++) {
                if (g_list[u][i].get_neighbor() == v) {
                    for (int j = i; j < t - 1; j++) {
                        g_list[u][j] = g_list[u][j + 1];
                    }
                    size[u]--;
                    break;
                }
            }
    
            if (!directed) {

                int t = size[v];
                for (int i = 0; i < t; i++) {
                    if (g_list[v][i].get_neighbor() == u) {
                        for (int j = i; j < t - 1; j++) {
                            g_list[v][j] = g_list[v][j + 1];
                        }
                        size[v]--;
                        break;
                    }
                }
            }
        } else {
            throw std::runtime_error("Edge does not exist");
        }
    }

    void Graph::print_graph ()
        {
            int t =0;
            std::cout<<"printed graph: "<<::std::endl;
            for(int i=0; i<V ;i++){
                std::cout<<"{";
                std::cout<<i<<" :";
            
                t=size[i];
                for(int j=0; j<t; j++){
                    std::cout<<"(v- "<<g_list[i][j].get_neighbor()<<" w- " <<g_list[i][j].get_weigt();
                    if(j!=t-1){
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
            if (u >= V || u < 0) {
                throw std::out_of_range("Vertex index out of bounds");
                return;
            }
            if(list == nullptr){
                throw std::invalid_argument("List pointer is null");
                return;
            }
        
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
            if (vertex_num <= 0) {
                throw std::invalid_argument("Number of vertices must be positive");
                return;
            }
            // if(new_g.get_vertex() != vertex_num){
            //     throw std::invalid_argument("The new graph must have the same number of vertices");
            //     return;
            // }
            if(pi == nullptr || d == nullptr) {
                throw std::invalid_argument("Pointer to pi or d is null");
                return;
            }
            // if(original.get_vertex() != vertex_num){
            //     throw std::invalid_argument("The original graph must have the same number of vertices");
            //     return;
            // }
            for( int i = 0; i <vertex_num ; i++){
                if(pi[i]>=0){ // build the tree by order
                    int weight =d[i];
                    new_g.addEdge(pi[i], i, weight , true);
                }
            }
        }
    int Graph::get_weight(int u, int v) //returns the weight 
        {
            if (u >= V || v >= V || u < 0 || v < 0) {
                throw std::out_of_range("Vertex index out of bounds");
                return -1;
            }
            if(!has_edge(u,v,true)){
                throw std::runtime_error("Edge does not exist");
                return -1;
            }
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
            if (indexi >= V || indexj >= V || indexi < 0 || indexj < 0) {
                throw std::out_of_range("Vertex index out of bounds");
                return;
            }
            if(!has_edge(indexi,indexj,true)){
                throw std::runtime_error("Edge does not exist");
                return;
            }
            int adj = size[indexi];
            for (int i = 0; i < adj; i++) {
                if (g_list[indexi][i].get_neighbor() == indexj) {
                    g_list[indexi][i].set_weigt(val);
                    return;
                }
            }
            throw std::runtime_error("Edge not found in adjacency list");

        }
    

    int Graph::get_graph_wheight(){
        int sum = 0;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < size[i]; j++) {
                sum += g_list[i][j].get_weigt();
            }
        }
        return sum ; // Since the graph is undirected, we divide by 2
    }



        Graph::~Graph() {
        if(g_list !=nullptr){
            for (int i = 0; i < V; i++) {
                if (g_list[i] != nullptr) {
                    delete[] g_list[i];       
                }
            }
        delete []g_list;
        delete[] size;
        }
    }



} // namespace graph          