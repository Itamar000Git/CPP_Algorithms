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
    bool connected = false;    
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

    Algorithm alg(10);

    Graph bfs_g = alg.BFS(g2,0);
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

    g2.removeEdge(0, 8,false);
    g2.removeEdge(0, 1,false);
    g2.removeEdge(0, 4,false);
    
    Graph bfs_g2 = alg.BFS(g2,0,&connected);
    bfs_g2.print_graph();
    CHECK(connected == false);
    CHECK(bfs_g2.get_size(0) == 0);
    CHECK(bfs_g2 .has_edge(0, 1,false) == false);
    CHECK(bfs_g2.has_edge(0, 4,false) == false);
    CHECK(bfs_g2.has_edge(0, 8,false) == false);

    CHECK_THROWS_AS(alg.BFS(g2,10), std::out_of_range); //check if its possible to run BFS on a vertex that not exist
    CHECK_THROWS_AS(alg.BFS(g2,-1), std::out_of_range);    

}

// TEST_CASE("Testing the DFS function") {
// }
// TEST_CASE("Testing the Dijkestra function"){

// }