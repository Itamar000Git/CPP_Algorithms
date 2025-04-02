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

    Graph Algorithm::BFS(Graph &gr , int s)  { //find the shortest path from single source
        enum Color { WHITE, GRAY, BLACK };
        int vertex_num = gr.get_vertex(); 
        if(vertex_num==0){
            throw std::runtime_error("Grph is empty");
        }
        if(s>vertex_num || s<0){
            throw std::out_of_range("Source vertex out of bound");
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
        int connected=1; //reference int that equal to 1 if the graph connected and 0 if not.

        ///////////////////////////prints/////////////////////////
        std::cout<<"d:" ;
        for (int i =0; i<vertex_num;i++){
            std::cout<<" '" << d[i] << "' ,";
            if( d[i]==inf){
               connected=0;
               
            }
        }
        std::cout<<std::endl;
        std::cout<<"pi:" ;

        for (int i =0; i<vertex_num;i++){
            std::cout<<"'" << pi[i] << "' ,";
        }
        std::cout<<std::endl;
        
        if( connected==0){
            std::cout<< "The graph is not conneced"<<std::endl;
        }
         ///////////////////////////end prints/////////////////////////

        Graph bfs_g(vertex_num); 

        gr.create_graph(bfs_g , pi, d, vertex_num, gr); //function that create graph from that ditails.

        return bfs_g;
    }

    void Algorithm::DFS_visit(Graph &gr , int u , int*color , int *pi ,int *d , int *f,int &time)
    {   
        int vertex_num=gr.get_vertex();
        color[u]=1;
        time=time+1;
        d[u]=time;
        for(int i =0 ;i < vertex_num  ; i++){
            if( gr.has_edge(u,i,false)){

                if(color[i]==0){
                    pi[i]=u;
                    DFS_visit(gr,i,color,pi,d,f,time);
                }
               
            }
        }
        color[u]=2;
        f[u]=time;
        time=time+1;

        return;
    }

    Graph Algorithm::main_DFS(Graph &gr , int s)
    {   
        int inf = std::numeric_limits<int>::max();
        int vertex_num = gr.get_vertex(); 
        int color [vertex_num]{0}; //0 = W , 1 = G, 2 = B
        int pi[vertex_num];
        int d[vertex_num];
        int f[vertex_num];
        int time=0;
        

        for( int j =0 ;j< vertex_num ; j++){
            pi[j]=-1;
            d[j]=inf;
            f[j]=inf;
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

        gr.create_graph(dfs_g , pi, d, vertex_num, gr);

        return dfs_g;

    }

    Graph Algorithm::dijkstra(Graph &gr , int s)
    {

        int vertex_num = gr.get_vertex(); 
        int inf = std::numeric_limits<int>::max();
        int d[vertex_num];
        int pi[vertex_num];
        int u;
        //Queue Q = Queue(vertex_num);
        praiority_Q Q  = praiority_Q(s);
        for( int j =0 ;j< vertex_num ; j++){
            d[j]=inf;
            pi[j]=-1;
            //Q.push(j);

        }
        for(int i =0 ; i< vertex_num; i++)
        {
            for(int j =0 ;j< vertex_num; j++)
            {
                if(gr.has_edge(i,j,true))
                {
                    
                    Q.pra_push(i,j,gr.get_weight(i,j));
                    
                }
            }
        }
        d[s]=0;
        while (!Q.Q_is_empty())
        {
            u=Q.pra_pop();
            for(int i =0 ;i < vertex_num  ; i++){
                if( gr.has_edge(u,i,true)){
                    relax(u, i , gr.get_weight(u,i), d, pi);
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
        

        Graph dijes(vertex_num); 

        gr.create_graph(dijes , pi ,d , vertex_num, gr);

       
        return dijes;
    }

    void Algorithm::relax(int u , int v , int w, int * d , int * pi)  //need to updeate praiotiry Q
    { 
        if(d[v] > d[u] + w ){
            d[v] = d[u] + w;
            pi[v]=u;
        }
     }
    
    
    Graph Algorithm::kruskal(Graph &gr){
        

       // int index=-1; //with call to min_edge we get 2 index to the miminal edge
        int inf=std::numeric_limits<int>::max();
        //int min = inf;
        int w , u , v;
        
        UnionFind mst = UnionFind(MAXN);  //as default we start with 0
        int vertex_num= gr.get_vertex();
        int pi[vertex_num] , d[vertex_num];
        for( int i=0 ;i< vertex_num ; i++){
            pi[i]=-1;
            d[i]=inf; //can be rank array
        }

        int edges_num = vertex_num * (vertex_num - 1) / 2; //n choos 2;
        int edges[edges_num][3];
        int num_of_edges=0;
        int e_count=0;

        for( int i =0 ; i< vertex_num ;i++){
            num_of_edges=gr.get_size(i);
            int list[num_of_edges];    
            gr.get_vertex_list(i,list);
            for(int j =0 ; j<num_of_edges ; j++) //creates tripple from each edge
            {
                w= gr.get_weight(i,list[j]);
                edges[e_count][0] = w;   
                edges[e_count][1] = i;     
                edges[e_count][2] = list[j]; 
                e_count++;
            }
        }


        for( int i =0 ; i< e_count-1;i++){//bubble sort
            for( int j =0 ; j< e_count-i-1 ;j++){
                if(edges[j][0]>edges[j+1][0]){
                    w=edges[j][0];
                    u=edges[j][1];
                    v=edges[j][2];
                    edges[j][0]=edges[j+1][0];
                    edges[j][1]=edges[j+1][1];
                    edges[j][2]=edges[j+1][2];
                    edges[j+1][0] = w;
                    edges[j+1][1] = u;
                    edges[j+1][2] = v;
                }
            }
        }
        for (int i = 0; i < e_count; i++) {
            int w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];
    
            if (mst.find(u)!=mst.find(0)) {
                mst.Union(u, v);
                pi[v] = u;
                d[v] = w;
                //gr.set_weight(u, v, inf);
            }
        }
        std::cout<<"pi:" ;

        for (int i =0; i<vertex_num;i++){
            std::cout<<"'" << pi[i] << "' ,";
        }
        std::cout<<std::endl;
    


        //mst.printTree(vertex_num);
        //mst.print(vertex_num);        
        Graph kruskal_g(vertex_num); 

        gr.create_graph(kruskal_g, pi, d, vertex_num, gr);
        return kruskal_g;
       //return NULL;
    }


    void Algorithm::min_edge(Graph &gr , int *arr){
        int inf= std::numeric_limits<int>::max();
        int vertex_num= gr.get_vertex() , w , indexi = -1 , indexj=-1 , min=inf;
        
        for( int i=0 ; i < vertex_num; i++){
            for( int j = 0 ; j < vertex_num ; j++){
                if (gr.has_edge(i,j,true)){ //directed
                    w=gr.get_weight(i,j);
                    if(w < min){
                        min = w;
                        indexi=i;
                        indexj = j;
                    }
                }
            }
        }
        gr.set_weight(indexi,indexj,inf);
        gr.set_weight(indexj,indexi, inf);
        arr[0] = indexi;
        arr[1] = indexj;
         
    }
    
    /////////////////////////////stopped here
    // Graph Algorithm::prim(Graph &gr){
    //     praiority_Q Q  = praiority_Q();
    //     int vertex_num = gr.get_vertex();
    //     int inf = std::numeric_limits<int>::max();
    //     int pi[vertex_num];
    //     bool in_mst[vertex_num] = {false};

    //     for( int j =0 ;j< vertex_num ; j++){
    //         pi[j]=-1;
    //     }
    //     Q.pra_push_key(0,0,0,inf); 
    //     for(int i =0 ; i< vertex_num; i++)
    //     {
    //         for(int j =0 ;j< vertex_num; j++)
    //         {
    //             if(gr.has_edge(i,j,true))
    //             {
    //                 std::cout<<i<<j<<std::endl;
    //                 Q.pra_push_key(i,j,gr.get_weight(i,j),inf); //need to change to push by key and pop by key and update key
    //                 //Q.pra_push_key(j,i,gr.get_weight(i,j),inf);
    //             }
    //         }
    //     }
      
    //     // int i;
    //     // for(i =0 ; i< vertex_num; i++)
    //     // {
    //     //   if(gr.has_edge(0,i,true))
    //     //   {
    //     //    Q.set_key(0,i,0); 
    //     //    break;   
    //     //   }
    //     // }
    //     // if(i==vertex_num)
    //     // {
    //     //     throw std::runtime_error("The graph is not connected");
    //     //     return gr;
    //     // }

    //    // pi[0]=-1;
    //    //Q.set_key(0, 0, 0);

        
    //     int neigbors;
        
    //     while(!Q.Q_is_empty())
    //     {
    //         int u=Q.pra_pop_key();
    //         std::cout<<u<<" is poped"<<std::endl;
    //         in_mst[u] = true;
    //         int list[vertex_num];
    //         int neigbors;
    //         gr.get_vertex_list(u,list);
    //         neigbors=gr.get_size(u);

    //         for(int i =0 ;i < neigbors ; i++)
    //         {
    //             int v = list[i];
    //             if(!in_mst[v]  ){

    //                 std::cout<<"////////"<<std::endl;
    //                 std::cout<<u<<v<<std::endl;
    //                 if( gr.get_weight(u,v)<Q.get_key(u,v)){
    //                     Q.set_key(u,v,gr.get_weight(u,v));
    //                     pi[v]=u;
    //                     Q.pra_pop_key();
    //                 }
                 
    //             }
    //         }
            

    //     }
    //     return gr;
    // } 


    Graph Algorithm::prim(Graph &g){ ////////////////////////////////////////check again
        //int v = g.get_vertex();
        int key[V]; 
        int parent[V]; 
        bool inMST[V]; 
        int list[V];
        int neigbors;

        for (int i = 0; i < V; ++i) {
            key[i] = std::numeric_limits<int>::max();
            parent[i] = -1;
            inMST[i] = false;
        }

        key[0] = 0;

        for (int count = 0; count < V - 1; ++count) {
       
            int u = -1;
            int minKey = std::numeric_limits<int>::max();
            for (int i = 0; i < V; ++i) {
                if (!inMST[i] && key[i] < minKey) {
                    minKey = key[i];
                    u = i;
                }
            }

            if (u == -1) break; 

            inMST[u] = true;
            g.get_vertex_list(u, list);
            neigbors = g.get_size(u);
            for (int i = 0; i < neigbors; i++) {
                int v = list[i];
                if (v == u) continue; 
                int weight = g.get_weight(u, v);
                if (weight != std::numeric_limits<int>::max() && !inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        Graph mst(V);
        for (int i = 1; i < V; ++i) {
            if (parent[i] != -1) {
                mst.addEdge(parent[i], i, key[i],true);
            }
        }

        //delete[] key;
        //delete[] parent;
        //delete[] inMST;

        return mst;
    }

}