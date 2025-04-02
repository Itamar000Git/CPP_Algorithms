//itamarbabai98@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
#include"Union.hpp"
#include "praiority_Q.hpp"
using namespace graphs;

int main() {
    Graph g(10) ,g1(5) , g2(10) ;
  
    //int connected = 0;    
    // g.addEdge(0, 1, 10,false);
    // g.addEdge(0, 4, 20,false);
    // g.addEdge(1, 2, 30,false);
    // g.addEdge(1, 3, 40,false);
    // g.addEdge(2, 3, 60,false);
    // g.addEdge(3, 4, 70,false);
    // g.addEdge(1, 4, 50,false);
    // g.addEdge(2, 5, 40,false);
    // g.addEdge(3, 6, 30,false);
    // g.addEdge(2, 6, 7,false);
    // g.addEdge(5, 7, 30,false);
    // g.addEdge(5, 8, 40,false);
    // g.addEdge(0, 8, 50,false);
    // g.addEdge(7, 9, 50,false);
    // g.addEdge(3, 9, 10,false);

    
 
    //  g.print_graph();
    //  g.has_edge(0, 1,false);
    //   g.removeEdge(0, 1,false);
    //   g.print_graph();
    // if(g.has_edge(0, 1,false) == true) {
    //     std::cout << "Edge exists" << std::endl;
    // } else {
    //     std::cout << "Edge does not exist" << std::endl;
    // }

    // praiority_Q pq;
    // pq.pra_push(0, 1, 20);
    // pq.pra_push(0, 4, 10);
    // pq.pra_push(1, 3, 15);
    // pq.pra_push(2, 3, 5);
    // pq.pra_push(3, 4, 25);

    // pq.print(); 

    // std::cout << "Min pop: " << pq.pra_pop() << std::endl; // אמור להוציא 2
    // pq.print();


    // Queue q(3);

    // try {
    //     q.push(10);
    //     q.push(20);
    //     q.push(30);
    //     q.push(40);  

    // } catch (const std::runtime_error& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    // try {
    //     std::cout << q.pop() << std::endl;  
    //     std::cout << q.pop() << std::endl;  
    //     std::cout << q.pop() << std::endl;  
    //     std::cout << q.pop() << std::endl;  

    // } catch (const std::runtime_error& e) {
    //     std::cout << "Error: " << e.what() << std::endl;
    // }

    Algorithm alg(10);

    // Graph bfs_g = alg.BFS(g,4);
    // bfs_g.print_graph();

    // if( connected==0){
    //     std::cout<< 'The graph is not conneced'<<std::endl;
    // }

   
    // Graph dfs_g = alg.main_DFS(g,2);
    // dfs_g.print_graph();

    // g1.addEdge(0, 1, 10,false);
    // g1.addEdge(0, 4, 20,false);
    // g1.addEdge(1, 2, 30,false);
    // g1.addEdge(1, 3, 40,false);
    // g1.addEdge(2, 3, 60,false);
    // g1.print_graph();
    // Graph dijkestra_g = alg.dijkstra(g1,4);
    // dijkestra_g.print_graph();


    // UnionFind uf(10); // יצירת Union-Find עם 10 אלמנטים

    // uf.Union(1, 2);
    // uf.Union(2, 3);
    // uf.Union(4, 5);
    // uf.Union(6, 7);
    // uf.Union(5, 6);

    // std::cout << "Are 1 and 3 connected? " << uf.connected(1, 3) << std::endl; // true (1)
    // std::cout << "Are 4 and 7 connected? " << uf.connected(4, 7) << std::endl; // true (1)
    // std::cout << "Are 1 and 5 connected? " << uf.connected(1, 5) << std::endl; // false (0)

    // uf.Union(3, 4);

    // std::cout << "Are 1 and 5 connected after union? " << uf.connected(1, 5) << std::endl; // true (1)



    g2.addEdge(0, 1, 50,false);
    g2.addEdge(0, 4, 20,false);
    g2.addEdge(1, 2, 30,false);
    g2.addEdge(1, 3, 30,false);
    g2.addEdge(2, 3, 60,false);
    g2.addEdge(3, 4, 100,false);
    g2.addEdge(1, 4, 20,false);
    //g2.addEdge(2, 5, 40,false);
    g2.addEdge(3, 6, 30,false);
    g2.addEdge(2, 6, 7,false);
   // g2.addEdge(5, 7, 30,false);
    //g2.addEdge(5, 8, 40,false);
    g2.addEdge(0, 8, 50,false);
    g2.addEdge(7, 9, 100,false);
    g2.addEdge(3, 9, 10,false);

    // g2.print_graph();
    // Graph kruskal_tree = alg.kruskal(g2);
    // kruskal_tree.print_graph();

    g2.print_graph();
    Graph prim_tree = alg.prim(g2);
    prim_tree.print_graph();

        return 0;
}
