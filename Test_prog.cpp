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

TEST_CASE("testing the grph function"){
    std::cout<<"TEST |||||||||||||||||||||||||||||||||||||||||||"<<std::endl;
    Graph g1(5);
    int connected = 0;    
    g1.addEdge(0, 1, 10,false);
    g1.addEdge(0, 4, 20,false);
    g1.addEdge(1, 2, 30,false);
    g1.addEdge(1, 3, 40,false);
    g1.addEdge(2, 3, 60,false);
    g1.addEdge(3, 4, 70,false);
    g1.addEdge(1, 4, 50,false);

    CHECK(g1.has_edge(0, 1,false) == true);
    g1.removeEdge(0, 1,false);
    g1.removeEdge(0, 4,false);
    CHECK(g1.has_edge(0, 1,false) == false);
    CHECK(g1.has_edge(0, 4,false) == false);
    
}


TEST_CASE("testing the bfs function") {
  
    Graph g2(10);
    int connected = 0;    
    g2.addEdge(0, 1, 10,false);
    g2.addEdge(0, 4, 20,false);
    g2.addEdge(0, 8, 50,false);
    g2.addEdge(1, 2, 30,false);
    g2.addEdge(1, 3, 40,false);
    g2.addEdge(1, 4, 50,false);
    g2.addEdge(2, 3, 60,false);
    g2.addEdge(2, 5, 40,false);
    g2.addEdge(2, 6, 7,false);
    g2.addEdge(3, 4, 70,false);
    g2.addEdge(3, 9, 10,false);
    g2.addEdge(3, 6, 30,false);
    g2.addEdge(5, 7, 30,false);
    g2.addEdge(5, 8, 40,false);
    g2.addEdge(7, 9, 50,false);




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
    
    Graph bfs_g2 = alg.BFS(g2,0);
    bfs_g2.print_graph();

    CHECK(bfs_g2 .has_edge(0, 1,false) == false);
    CHECK(bfs_g2.has_edge(0, 4,false) == false);
    CHECK(bfs_g2.has_edge(0, 8,false) == false);


        
    //for(int i=0;i<)
    // CHECK(fact(0) == 1); // should fail
    // CHECK(fact(1) == 1);
    // CHECK(fact(2) == 2);
    // CHECK(fact(3) == 6);
    // CHECK(fact(10) == 3628800);
}