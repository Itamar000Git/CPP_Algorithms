//itamarbabai98@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include "Union.hpp"
#include "praiority_Q.hpp"
using namespace graphs;

int main() {
    Graph g(10) ,g1(10) , g2(10) , g3(5) , g4(5);
    Algorithm alg(10);
    

    std::cout<<std::endl;
    std::cout<< "||||||||||||||||||||presentrint BFS algorithm|||||||||||||||||||||||" << std::endl;
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 5, 40);
    g.addEdge(3, 6, 30);
    g.addEdge(2, 6,  7);
    g.addEdge(5, 7, 30);
    g.addEdge(5, 8, 40);
    g.addEdge(0, 8, 50);
    g.addEdge(7, 9, 50);
    g.addEdge(3, 9, 10);
    g.print_graph();
    
    bool connected;  
    //notice that the pointer to the connected is unnecessary, but if you want to check if the graph is connected you can use it
    Graph bfs_g = alg.BFS(g,4, &connected); 
    bfs_g.print_graph();

    // if( connected==0){
    //     std::cout<< 'The graph is not conneced'<<std::endl;
    // }

    std::cout<<std::endl;
    std::cout<< "||||||||||||||||||||Presentrint DFS algorithm|||||||||||||||||||||||" << std::endl;
    g1.addEdge(0, 1, 10);
    g1.addEdge(0, 4, 20);
    g1.addEdge(1, 2, 30);
    g1.addEdge(1, 3, 40);
    g1.addEdge(2, 3, 60);
    g1.addEdge(3, 4, 70);
    g1.addEdge(1, 4, 50);
    g1.addEdge(2, 5, 40);
    g1.addEdge(3, 6, 30);
    g1.addEdge(2, 6,  7);
    g1.addEdge(5, 7, 30);
    g1.addEdge(5, 8, 40);
    g1.addEdge(0, 8, 50);
    g1.addEdge(7, 9, 50);
    g1.addEdge(3, 9, 10);
    g1.print_graph();
  
    Graph dfs_g = alg.main_DFS(g1,2);
    dfs_g.print_graph();


    std::cout<<std::endl;
    std::cout<< "||||||||||||||||||||Presentrint DIJKESTRA algorithm|||||||||||||||||||||||" << std::endl;
    g2.addEdge(0, 1, 50);
    g2.addEdge(0, 3, 30);
    g2.addEdge(1, 2, 20);
    g2.addEdge(1, 4, 40);
    g2.addEdge(2, 5, 30);
    g2.addEdge(5, 0, 40);
    g2.addEdge(3, 6, 20);
    g2.addEdge(4, 7, 50);
    g2.addEdge(5, 8, 40);
    g2.addEdge(6, 9, 60);
    g2.addEdge(7, 8, 10);
    g2.addEdge(8, 9, 20);
    g2.print_graph();

    Graph dijkestra_g = alg.dijkstra(g2,2);
    
    dijkestra_g.print_graph();


    std::cout<<std::endl;
    std::cout<< "||||||||||||||||||||Presentrint KRUSKAL algorithm|||||||||||||||||||||||" << std::endl;
    Algorithm alg1(5);
    g3.addEdge(0, 1, 50);
    g3.addEdge(0, 4, 20);
    g3.addEdge(1, 2, 30);
    g3.addEdge(1, 3, 30);
    g3.addEdge(2, 3, 10);
    g3.addEdge(3, 4, 100);
    g3.addEdge(1, 4, 20);
    g3.print_graph();
    Graph kruskal_tree = alg1.kruskal(g3);
    kruskal_tree.print_graph();
    std::cout<< "weight of the tree is: " << kruskal_tree.get_graph_wheight() << std::endl;


    
    std::cout<<std::endl;
    std::cout<< "||||||||||||||||||||Presentrint PRIM algorithm|||||||||||||||||||||||" << std::endl;
    g4.addEdge(0, 1, 50);
    g4.addEdge(0, 4, 20);
    g4.addEdge(1, 2, 30);
    g4.addEdge(1, 3, 30);
    g4.addEdge(2, 3, 10);
    g4.addEdge(3, 4, 100);
    g4.addEdge(1, 4, 20);
    g4.print_graph();

    Graph prim_tree = alg1.prim(g4);
    prim_tree.print_graph();
    std::cout<< "weight of the tree is: " << prim_tree.get_graph_wheight() << std::endl;

        return 0;
}
