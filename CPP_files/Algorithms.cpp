//itamarbabai98@gmail.com
#include <iostream>
#include <limits> 
#include "Graph.hpp"
#include "Algorithms.hpp"
#include "Queue.hpp"
#include "praiority_Q.hpp"
#include "Union.hpp"

namespace graphs
{   
    Algorithm::Algorithm(int num){//constructor to the algorithm object
        V=num;
    }

    Graph Algorithm::BFS(Graph &gr , int s , bool * connected)  { //find the shortest path from single source
        if(s>=gr.get_vertex() || s<0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(gr.get_vertex()==0){
            throw std::runtime_error("Grph is empty");
        }
        std::cout<<"BFS algorithm"<<std::endl;
        enum Color { WHITE, GRAY, BLACK };
        int vertex_num = gr.get_vertex(); 
        if(vertex_num==0){
            throw std::runtime_error("Grph is empty");
        }


        int inf = std::numeric_limits<int>::max();
        Color color [vertex_num]; //0 = W , 1 = G, 2 = B
        int d[vertex_num];
        int pi[vertex_num];
        for( int j =0 ;j< vertex_num ; j++){ //initial all distance to inf , all parants to -1 and all colors to white.
            d[j]=inf;
            pi[j]=-1;
            color[j]=WHITE;
        }
           

        int u, list[vertex_num], neigbors;

        Queue Q = Queue(vertex_num); //create the queue 
        color[s] = GRAY; //start with the source 
        d[s]=0; //the distance from itself its 0
        Q.push(s);
        while(!Q.is_empty()){ //the loop that scans all conected graph
            u=Q.pop(); //pop the first in the simple queue 
            gr.get_vertex_list(u,list); // insert to list all neigbors
            neigbors= gr.get_size(u);  // get neigbors number
            for(int i =0 ;i < neigbors ; i++){ //for all neigbors
                if(color[list[i]]==WHITE) //if never visited
                {
                    color[list[i]]=GRAY; // change to  - in prograss (GRAY)
                    d[list[i]]=d[u]+1; //update the distncr frome source
                    pi[list[i]]=u; // update the 
                    Q.push(list[i]); //insert the visited neigbor to the queue
                }
            }
            color[u]=BLACK; // once all neigbors updated, the prosses ends for u
        }
        
        if(connected != nullptr){
            *connected=true;
        }

        ///////////////////////////prints/////////////////////////

        std::cout<<"d:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<" '" << d[i] << "' ,";
            if( d[i]==inf && connected != nullptr){ //if there is a vertex that not connected to the source
               *connected=false;
               
            }
        }
        std::cout<<std::endl;
        std::cout<<"pi:" ;

        for (int i =0; i<vertex_num;i++){
            std::cout<<"'" << pi[i] << "' ,";
        }
        std::cout<<std::endl;
        


        Graph bfs_g(vertex_num); 

        gr.create_graph(bfs_g , pi, d, vertex_num, gr); //function that create graph from that ditails.

        return bfs_g;
    }

    void Algorithm::DFS_visit(Graph &gr , int u , int*color , int *pi ,int *d , int *f,int &time) //recursive function that visit all the graph
    {   
        if(u>=gr.get_vertex() || u<0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(gr.get_vertex()==0){
            throw std::runtime_error("Grph is empty");
        }
        if(color == nullptr || pi == nullptr || d == nullptr || f == nullptr){
            throw std::invalid_argument("Pointer to color, pi, d or f is null");
        }

        int vertex_num=gr.get_vertex(); 
        color[u]=1;
        time=time+1;
        d[u]=time;
        for(int i =0 ;i < vertex_num  ; i++){
            if( gr.has_edge(u,i,false)){ //if there is an edge from u to i

                if(color[i]==0){ // and if i is not visited
                    pi[i]=u; //u is the parent of i
                    DFS_visit(gr,i,color,pi,d,f,time); //recursive call to visit i
                }
               
            }
        }
        color[u]=2; //when all the neigbors are visited, we can mark u as black
        f[u]=time; // finish time of u
        time=time+1;

        return;
    }

    Graph Algorithm::main_DFS(Graph &gr , int s)
    {  
        if(gr.get_vertex() == 0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(s>=gr.get_vertex() || s<0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(gr.get_vertex()==0){
            throw std::runtime_error("Grph is empty");
        }
        std::cout<<"DFS algorithm"<<std::endl;

        int inf = std::numeric_limits<int>::max();
        int vertex_num = gr.get_vertex(); 
        int color [vertex_num]; //0 = W , 1 = G, 2 = B
        int pi[vertex_num];
        int d[vertex_num];
        int f[vertex_num];
        int time=0;
        

        for( int j =0 ;j< vertex_num ; j++){ //initial all distance to inf , all parants to -1 and all colors to white.
            pi[j]=-1;
            d[j]=inf;
            f[j]=inf;
            color[j]=0;
        }
        for ( int i =s; i <vertex_num ;i ++){
            if( color[i] == 0){
            DFS_visit(gr, (i%vertex_num),color,pi,d ,f,time);
            }
        }

        std::cout<<"d:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<" '" << d[i] << "' ,";
        }
        std::cout<<std::endl;

        std::cout<<"f:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<" '" << f[i] << "' ,";
        }
        std::cout<<std::endl;
        
        std::cout<<"pi:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<"'" << pi[i] << "' ,";
        }
        std::cout<<std::endl;
        
        Graph dfs_g(vertex_num); 

        gr.create_graph(dfs_g , pi, d, vertex_num, gr); //create graph from that ditails.

        return dfs_g;

    }

    Graph Algorithm::dijkstra(Graph &gr , int s)
    {
        if(gr.get_vertex() == 0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(s>gr.get_vertex() || s<0){
            throw std::out_of_range("Source vertex out of bound");
        }
        if(gr.get_vertex()==0){
            throw std::runtime_error("Grph is empty");
        }
        std::cout<<"Dijkstra algorithm"<<std::endl;

        int vertex_num = gr.get_vertex(); 
        int inf = std::numeric_limits<int>::max();
        int d[vertex_num];
        int pi[vertex_num];
        int u;
        int list[vertex_num];
        int neigbors;
        praiority_Q Q(s,d); //Create the praiority queue
        for( int j =0 ;j< vertex_num ; j++){ //initial all distance to inf , all parants to -1
            d[j]=inf/2;
            pi[j]=-1;
        }

        for(int i =0 ; i< vertex_num; i++)
        {
            neigbors= gr.get_size(i);  // get neigbors number
            gr.get_vertex_list(i,list); // insert to list all neigbors
            for(int j=0;j<neigbors;j++){
                if(gr.has_edge(i,list[j],true)){
                    if(gr.get_weight(i,list[j]) < 0){
                        throw std::runtime_error("Negative weight edge");
                        return NULL;
                    }
                    Q.pra_push(i,list[j],gr.get_weight(i,list[j])); //Push all the edges to the queue
                }
            }

        }
        
        d[s]=0;
        while (!Q.Q_is_empty())
        {
            u=Q.pra_pop(); //pop the vertex with the minimum weight
            neigbors= gr.get_size(u);  // get neigbors number
            gr.get_vertex_list(u,list); // insert to list all neigbors
            for(int j=0;j<neigbors;j++){
                if(gr.has_edge(u,list[j],true)){
                    if(d[list[j]] > d[u] + gr.get_weight(u,list[j])){ //if the distance to the neigbor is greater than the distance to the vertex + the weight of the edge
                            d[list[j]] = d[u] + gr.get_weight(u,list[j]); //relax the edge
                            pi[list[j]]=u;
                            Q.pra_update();
          
                    }
                }
            }

        }

        std::cout<<"d:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<" '" << d[i] << "' ,";
        }
        std::cout<<std::endl;
        std::cout<<"pi:" ;

        for (int i =0; i<vertex_num;i++){
            std::cout<<"'" << pi[i] << "' ,";
        }
        std::cout<<std::endl;
        

        Graph dijes (vertex_num);
        gr.create_graph(dijes , pi ,d , vertex_num, gr);
       
        return dijes;
    }


    Graph Algorithm::kruskal(Graph &gr) {
        std::cout << "Kruskal algorithm" << std::endl;
        if (gr.get_vertex() == 0) {
            throw std::runtime_error("Graph is empty");
        }
        bool connected = false;
        BFS(gr, 0, &connected);
        if (!connected) {
            throw std::runtime_error("Graph is not connected");
        }

        int vertex_num = gr.get_vertex();
        int inf = std::numeric_limits<int>::max();
        int w, u, v;
        UnionFind mst(vertex_num); // Union-Find structure
        int pi[vertex_num], d[vertex_num];
        for (int i = 0; i < vertex_num; i++) {
            pi[i] = -1;
            d[i] = inf;
        }
    
        int edges_num = vertex_num * (vertex_num - 1); // Maximum possible edges
        int edges[edges_num][3]; // Array to store edges
        int e_count = 0;

        for (int i = 0; i < vertex_num; i++) {
            int num_of_neighbors = gr.get_size(i);
            int list[num_of_neighbors];
            gr.get_vertex_list(i, list);
            for (int j = 0; j < num_of_neighbors; j++) {
                    w = gr.get_weight(i, list[j]);
                    edges[e_count][0] = w;
                    edges[e_count][1] = i;
                    edges[e_count][2] = list[j];
                    e_count++;
            }
        }
    
        // Sort edges by weight using bubble sort
        for (int i = 0; i < e_count - 1; i++) {
            for (int j = 0; j < e_count - i - 1; j++) {
                if (edges[j][0] > edges[j + 1][0]) {
                    int temp_w = edges[j][0];
                    int temp_u = edges[j][1];
                    int temp_v = edges[j][2];
                    edges[j][0] = edges[j + 1][0];
                    edges[j][1] = edges[j + 1][1];
                    edges[j][2] = edges[j + 1][2];
                    edges[j + 1][0] = temp_w;
                    edges[j + 1][1] = temp_u;
                    edges[j + 1][2] = temp_v;
                }
            }
        }
    
        for (int i = 0; i < e_count; i++) {
            w = edges[i][0];
            u = edges[i][1];
            v = edges[i][2];
    
            if (mst.find(u) != mst.find(v)) { // Check if u and v are in different sets
               
                if(pi[v] == -1){ // If v is not already in the MST
                    mst.Union(u, v); // Union the sets
                    pi[v] = u; // Set the parent of v to u
                    d[v] = w; // Set the distance of v to the weight of the edge
                }else if( d[v] > w){ // If v is already in the MST and the new edge is smaller
                    mst.Union(u, v); // Union the sets
                    d[v] = w; // Update the distance of v
                    pi[v] = u;
                }
            }
        }
        std::cout << "pi:";
    
        for (int i = 0; i < vertex_num; i++) {
            std::cout << "'" << pi[i] << "' ,";
        }
        std::cout << std::endl;
    
        Graph kruskal_g(vertex_num);
        gr.create_graph(kruskal_g, pi, d, vertex_num, gr);
        return kruskal_g;
    }

    
    Graph Algorithm::prim(Graph &g){ 

        if(g.get_vertex()==0){
            throw std::runtime_error("Grph is empty");
        }
        bool connected = false;
        BFS(g,0,&connected);
        if(connected==false){
            throw std::runtime_error("Graph is not connected");
        }
        std::cout<<"Prim algorithm"<<std::endl;
        int key[V]; 
        int parent[V]; 
        bool inMST[V]; 
        int list[V];
        int neigbors;

        for (int i = 0; i < V; ++i) {// Initialize all keys as infinite
            key[i] = std::numeric_limits<int>::max();
            parent[i] = -1;
            inMST[i] = false;
        }

        key[0] = 0; 

        for (int count = 0; count < V - 1; ++count) {
       
            int u = -1;
            int minKey = std::numeric_limits<int>::max();
            for (int i = 0; i < V; ++i) { //find the vertex with the minimum key value
                if (!inMST[i] && key[i] < minKey) {
                    minKey = key[i];
                    u = i;
                }
            }

            if (u == -1) break; 

            inMST[u] = true; // Mark the picked vertex as processed
            g.get_vertex_list(u, list); // Get the neighbors of u
            neigbors = g.get_size(u);
            for (int i = 0; i < neigbors; i++) { // for each neighbor v of u
                int v = list[i];
                if (v == u) continue; 
                int weight = g.get_weight(u, v);
                if (weight != std::numeric_limits<int>::max() && !inMST[v] && weight < key[v]) { //If v is not in MST and weight of u-v is less than current key value of v
                    key[v] = weight; // Update key value
                    parent[v] = u; // Update parent
                }
            }
        }

        Graph mst(V);
        for (int i = 1; i < V; ++i) { // Create the MST
            if (parent[i] != -1) {
                mst.addEdge(parent[i], i, key[i],true);
            }
        }


        return mst;
    }

}