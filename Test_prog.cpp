//itamarbabai98@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include"Union.hpp"
#include "praiority_Q.hpp"
#include "doctest.h"
using namespace graphs;

TEST_CASE("Testing the graph functions"){
    std::cout<<"||||||||||||||||||||Testing the graph functions|||||||||||||||||||||||"<<std::endl;
    Graph g1(5);
    int connected = 0;    
    g1.addEdge(0, 1, 10,false);
    g1.addEdge(0, 4, 20,false);
    g1.addEdge(1, 2, 30,false);
    g1.addEdge(1, 3, 40,false);
    g1.addEdge(2, 3, 60,false);
    g1.addEdge(3, 4, 70,false);
    g1.addEdge(1, 4, 50,false);

    CHECK(g1.has_edge(0, 1,false) == true);//check if the edge was added
    g1.removeEdge(0, 1,false);
    g1.removeEdge(0, 4,false);

    CHECK(g1.has_edge(0, 1,false) == false);//check if the edge was removed
    CHECK(g1.has_edge(0, 4,false) == false);

    int list[5];
    CHECK_THROWS_AS(Graph(-1), std::invalid_argument); //check if its possible to create a graph with negative vertices
    CHECK_THROWS_AS(Graph(0), std::invalid_argument);   //check if its possible to create a graph with 0 vertices
    CHECK_THROWS_AS(g1.has_edge(-1,4,false) , std::out_of_range);      //check if its possible to check an edge with negative index
    CHECK_THROWS_AS(g1.addEdge(-1,4,30,false) , std::out_of_range);  //check if its possible to add an edge with negative index
    CHECK_THROWS_AS(g1.removeEdge(0, 4,false), std::runtime_error);  //check if its possible to remove an edge that not exist
    CHECK_THROWS_AS(g1.get_vertex_list(0,nullptr), std::invalid_argument); //check if its possible to get a vertex list with null pointer
    CHECK_THROWS_AS(g1.get_vertex_list(-1,list), std::out_of_range);// //check if its possible to get a vertex list with negative index
   
}


TEST_CASE("Testing the BFS function") {
    std::cout<<"||||||||||||||||||||Testing the BFS functions|||||||||||||||||||||||"<<std::endl;
    Graph g2(10);
    Algorithm alg(10);
    bool connected = false;    
    alg.BFS(g2,0,&connected);
    g2.addEdge(0, 1, 10);
    g2.addEdge(0, 4, 20);
    g2.addEdge(0, 8, 50);
    g2.addEdge(1, 2, 30);
    g2.addEdge(1, 3, 40);
    g2.addEdge(1, 4, 50);
    g2.addEdge(2, 3, 60);
    g2.addEdge(2, 5, 40);
    g2.addEdge(2, 6, 7);
    g2.addEdge(3, 4, 70);
    g2.addEdge(3, 9, 10);
    g2.addEdge(3, 6, 30);
    g2.addEdge(5, 7, 30);
    g2.addEdge(5, 8, 40);
    g2.addEdge(7, 9, 50);

   
    Graph bfs_g = alg.BFS(g2,0,&connected);
    CHECK(connected == true);
    int list[10];
    bfs_g.print_graph();
    bfs_g.get_vertex_list(0,list);
   
    CHECK(bfs_g.get_size(0) == 3); 
    CHECK(bfs_g.get_size(1) == 2);
    CHECK(bfs_g.get_size(2) == 1); //8 takes the 5 before 2, and 1 takes the 3 before 2
    CHECK(list[0] == 1); // the order of the neigbors
    CHECK(list[1] == 4); 
    CHECK(list[2] == 8);
    CHECK(bfs_g.get_weight(0, 1) == 1);
    CHECK(bfs_g.get_weight(1, 2) == 2);

    //check if the BFS function works on a disconnected graph
    g2.removeEdge(0, 8,false);
    g2.removeEdge(0, 1,false);
    g2.removeEdge(0, 4,false);
    
    Graph bfs_g2 = alg.BFS(g2,0,&connected);
    bfs_g2.print_graph();
    CHECK(connected == false);
    CHECK(bfs_g2.get_size(0) == 0); //check if the size of the vertex is 0
    CHECK(bfs_g2 .has_edge(0, 1,false) == false);
    CHECK(bfs_g2.has_edge(0, 4,false) == false);
    CHECK(bfs_g2.has_edge(0, 8,false) == false);

    g2.addEdge(0, 8,false);
    Graph bfs_g3 = alg.BFS(g2,0,&connected); 
    CHECK(connected == true);
  
    CHECK_THROWS_AS(alg.BFS(g2,10), std::out_of_range); //check if its possible to run BFS on a vertex that not exist
    CHECK_THROWS_AS(alg.BFS(g2,-1), std::out_of_range);  

 }
TEST_CASE("Testing the Queue function") {
    std::cout<<"||||||||||||||||||||Testing the Queue functions|||||||||||||||||||||||"<<std::endl;
    Queue q(3);
    CHECK(q.is_empty() == true); // Check if the queue is empty
    CHECK_THROWS_AS(q.pop(), std::runtime_error); // Check if popping from an empty queue throws an error

    q.push(1);
    q.push(2);
    q.push(3);
    CHECK(q.is_empty() == false); // Check if the queue is not empty
    CHECK_THROWS_AS(q.push(4), std::runtime_error); // Check if pushing to a full queue throws an error
    CHECK(q.pop() == 1); // Check if the first element popped is correct
    CHECK_THROWS_AS(Queue q1(-1), std::invalid_argument); // Check if creating a queue with negative size throws an error
}

 TEST_CASE("Testing the DFS function") {
    std::cout<<"||||||||||||||||||||Testing the DFS functions|||||||||||||||||||||||"<<std::endl;
    Graph g3(10);
    g3.addEdge(0, 1, 10);
    g3.addEdge(0, 4, 20);
    g3.addEdge(0, 8, 50);
    g3.addEdge(1, 2, 30);
    g3.addEdge(1, 3, 40);
    g3.addEdge(1, 4, 50);
    g3.addEdge(2, 3, 60);
    g3.addEdge(2, 5, 40);
    g3.addEdge(2, 6, 7);
    g3.addEdge(3, 4, 70);
    g3.addEdge(3, 9, 10);
    g3.addEdge(3, 6, 30);
    g3.addEdge(5, 7, 30);
    g3.addEdge(5, 8, 40);
    g3.addEdge(7, 9, 50);
    g3.print_graph();
    Algorithm alg(10);
    Graph dfs_g = alg.main_DFS(g3,0);
    dfs_g.print_graph();
    CHECK_THROWS_AS(alg.main_DFS(g3,10), std::out_of_range); //check if its possible to run DFS on a vertex that not exist
    CHECK_THROWS_AS(alg.main_DFS(g3,-1), std::out_of_range); //check if its possible to run DFS on a vertex that not exist


    int list[10];
    dfs_g.get_vertex_list(0,list);
   
    CHECK(dfs_g.get_size(0) == 1); //only 1 neigbor (no back edges)
    CHECK(list[0] == 1); // the order of the neigbors

    dfs_g.get_vertex_list(3,list);
    CHECK(dfs_g.get_size(3) == 3);
    CHECK(list[0] == 4); // vertex 3 took the 4 from 1 old neibor's 

    dfs_g.get_vertex_list(5,list);
    CHECK(dfs_g.get_size(5) == 1); 
    CHECK(list[0] == 8);// vertex 5 took the 8 from 1 old neibor's 
    

    Graph g4(10);
    g4.addEdge(0, 1, 10);
    g4.addEdge(0, 4, 20);
    g4.addEdge(1, 2, 30);
    g4.addEdge(1, 3, 40);
    g4.addEdge(1, 4, 50);
    g4.addEdge(2, 3, 60);
    g4.addEdge(2, 5, 40);
    g4.addEdge(3, 4, 70);
    g4.addEdge(7, 9, 50);
    g4.addEdge(7, 6, 50);
    g4.addEdge(8, 9, 50);
    g4.addEdge(5, 6, 50);
    g4.addEdge(5, 7, 50);
    g4.addEdge(5, 9, 50);
    g4.print_graph();

    g4.removeEdge(5,6);
    g4.removeEdge(5,7);
    g4.removeEdge(5,9);

    Graph dfs_g4 = alg.main_DFS(g4,0); //run DFS on a disconnected graph
    CHECK(dfs_g4.has_edge(0, 6,false) == false);
    CHECK(dfs_g4.has_edge(1, 6,false) == false);
    CHECK(dfs_g4.has_edge(2, 6,false) == false);
    CHECK(dfs_g4.has_edge(3, 6,false) == false);
    CHECK(dfs_g4.has_edge(4, 6,false) == false);
    CHECK(dfs_g4.has_edge(5, 6,false) == false);
    
    bool connected = NULL;
    alg.BFS(dfs_g4,0,&connected);
    CHECK(connected == false); //check if the graph is disconnected
    
    dfs_g4.print_graph();
 }

TEST_CASE("Testing the Dijkestra function"){
std::cout<<"||||||||||||||||||||Testing the Dijkestra functions|||||||||||||||||||||||"<<std::endl;
    Graph g5(10);
    g5.addEdge(0, 1, 10);
    g5.addEdge(0, 3, 30);
    g5.addEdge(1, 2, 20);
    g5.addEdge(1, 4, 40);
    g5.addEdge(2, 5, 30);
    g5.addEdge(3, 6, 20);
    g5.addEdge(4, 7, 50);
    g5.addEdge(5, 8, 40);
    g5.addEdge(6, 9, 60);
    g5.addEdge(7, 8, 10);
    g5.addEdge(8, 9, 20);
    g5.print_graph();

    Algorithm alg(10);
    Graph dijkstra_g = alg.dijkstra(g5,0);
    dijkstra_g.print_graph();
    CHECK(dijkstra_g.get_weight(0, 3) == 30);
    CHECK(dijkstra_g.get_weight(3, 6) == 50);
    CHECK(dijkstra_g.get_weight(6, 9) == 110);

    CHECK(dijkstra_g.has_edge(0,9,true) == false); 
    CHECK(dijkstra_g.has_edge(9,0,true) == false);

    g5.addEdge(0, 9, 10); //adding shorter path
    dijkstra_g = alg.dijkstra(g5,0);
    dijkstra_g.print_graph();
    CHECK(dijkstra_g.get_weight(0, 9) == 10);// Check if the weight of the edge is correct

    g5.removeEdge(0, 9); 
    g5.removeEdge(3, 6);
    g5.removeEdge(5, 8);
    g5.removeEdge(4, 7);
    dijkstra_g = alg.dijkstra(g5,0);
    dijkstra_g.print_graph(); //print the distance as inf when the graph is disconnected

    g5.addEdge(0, 9, -10);
    CHECK_THROWS_AS(alg.dijkstra(g5,0), std::runtime_error); //check if its possible to run Dijkstra on a graph with negative weight
    g5.removeEdge(0, 9);
    CHECK_THROWS_AS(alg.dijkstra(g5,10), std::out_of_range); //check if its possible to run Dijkstra on a vertex that not exist
    CHECK_THROWS_AS(alg.dijkstra(g5,-1), std::out_of_range); //check if its possible to run Dijkstra on a vertex that not exist}
}

TEST_CASE("Testing the Prairity_Q function") {
    praiority_Q pq1;
    int * d = new int[5];
    for (int i = 0; i < 5; i++) {
        d[i] = i+1;
    }
   CHECK_THROWS_AS( pq1 = praiority_Q(-1,d), std::out_of_range); // Check if pushing with negative index throws an error
   praiority_Q pq = praiority_Q(5,d);
   pq.pra_push(0, 1, 20);
   pq.pra_push(0, 4, 10);
   pq.pra_push(1, 3, 15);
   pq.pra_push(2, 3, 5);   
   pq.pra_push(3, 4, 25);
   pq.pra_push(4, 2, 25);
   pq.print();
   CHECK(pq.pra_pop() == 0); // Check if the first element popped is correct     
   d[4]=0;
   pq.pra_update();
   pq.print();
   CHECK(pq.pra_pop() == 4); // Check if the first element popped is correct
   pq.pra_pop();
   pq.pra_pop();
   pq.pra_pop();
   pq.pra_pop();
   pq.pra_pop();
   CHECK(pq.Q_is_empty() == true); // Check if the queue is empty
   CHECK_THROWS_AS(pq.pra_pop(), std::runtime_error); // Check if popping from an empty queue throws an error
}


TEST_CASE("Testing the Kruskal function") {
    std::cout<<"||||||||||||||||||||Testing the Kruskal functions|||||||||||||||||||||||"<<std::endl;
    Graph g5(5);
    Algorithm alg(5);
    CHECK_THROWS_AS(alg.kruskal(g5), std::runtime_error); // Check if running Kruskal on an empty graph throws an error
    g5.addEdge(0, 1, 50);
    g5.addEdge(0, 4, 20);
    g5.addEdge(1, 2, 30);
    g5.addEdge(1, 3, 30);
    g5.addEdge(2, 3, 60);
    g5.addEdge(3, 4, 100);
    g5.addEdge(1, 4, 20);

    g5.print_graph();

    Graph kruskal_tree = alg.kruskal(g5);
    kruskal_tree.print_graph();
    CHECK(kruskal_tree.get_graph_wheight() == 100); // Check if the weight of the MST is correct
     g5.set_weight(0,4,10);
     g5.set_weight(4,0,10);

    Graph kruskal_tree_1 = alg.kruskal(g5);
    kruskal_tree_1.print_graph();
    std::cout<< "weight of the tree is: " << kruskal_tree_1.get_graph_wheight() << std::endl;
    CHECK(kruskal_tree_1.get_graph_wheight() == 90);

    g5.set_weight(0,1,10);
    g5.set_weight(1,0,10); //force the 0,1 to be in the tree
    g5.print_graph();
    Graph kruskal_tree_2 = alg.kruskal(g5);
    kruskal_tree_2.print_graph();
    std::cout<< "weight of the tree is: " << kruskal_tree_2.get_graph_wheight() << std::endl;
    CHECK(kruskal_tree_2.get_graph_wheight() == 80); // Check if the weight of the MST is correct

    
    g5.removeEdge(1, 2);
    g5.removeEdge(2, 3);
    CHECK_THROWS_AS(alg.kruskal(g5), std::runtime_error); // Check if running Kruskal on a disconnected graph throws an error

}

TEST_CASE("Testing the Union find function") {
    UnionFind uf(10); // Create a Union-Find with 10 elements
    uf.Union(1, 2);
    uf.Union(2, 3);
    uf.Union(4, 5);
    uf.Union(6, 7);
    uf.Union(5, 6);
    
    CHECK(uf.connected(1, 3) == true); // Check if 1 and 3 are connected
    CHECK(uf.connected(4, 7) == true); // Check if 4 and 7 are connected
    CHECK(uf.connected(1, 5) == false); // Check if 1 and 5 are not connected

    uf.Union(3, 4);

    CHECK(uf.connected(1, 5) == true); // Check if 1 and 5 are now connected
}




TEST_CASE("Testing the prim function") {
    Graph g6(1) ,g7(5);
    Algorithm alg(1) , alg1(5);
    Graph prim = alg.prim(g6);
    CHECK(prim.get_graph_wheight() == 0);

    g7.addEdge(0, 1, 50);
    g7.addEdge(0, 4, 20);
    g7.addEdge(1, 2, 30);
    CHECK_THROWS_AS(alg.prim(g7), std::runtime_error); // Check if running Prim on a disconnected graph throws an error

    g7.addEdge(1, 3, 30);
    g7.addEdge(2, 3, 60);
    g7.addEdge(3, 4, 100);
    g7.addEdge(1, 4, 20);
    Graph prim_1 = alg1.prim(g7);
    prim_1.print_graph();
    CHECK(prim_1.get_graph_wheight() == 100); // Check if the weight of the MST is correct

    g7.set_weight(0,4,10);
    g7.set_weight(4,0,10);
    Graph prim_2 = alg1.prim(g7);
    prim_2.print_graph();
    CHECK(prim_2.get_graph_wheight() == 90); // Check if the weight of the MST is correct

    g7.set_weight(0,1,10);
    g7.set_weight(1,0,10); //force the 0,1 to be in the tree
    Graph prim_3 = alg1.prim(g7);
    prim_3.print_graph();
    CHECK(prim_3.get_graph_wheight() == 80); // Check if the weight of the MST is correct


}