//itamarbabai98@gmail.com
#include <iostream>
#include "Graph.hpp"
#include "Queue.hpp"
#include "Algorithms.hpp"
using namespace graphs;

int main() {
    Graph g(5); // יצירת גרף עם 5 צמתים
    
    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
   // g.addEdge(2, 3, 60);
   //g.addEdge(3, 4, 70);
    
 
    g.print_graph();

    Queue q(3);

    try {
        q.push(10);
        q.push(20);
        q.push(30);
        q.push(40);  

    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::cout << q.pop() << std::endl;  
        std::cout << q.pop() << std::endl;  
        std::cout << q.pop() << std::endl;  
        std::cout << q.pop() << std::endl;  

    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    Algorithm alg(5);
    alg.BFS(g,0);
  
        return 0;
}
