//itamarbabai98@gmail.com

#include <iostream>
#include "Union.hpp"

namespace graphs{

    UnionFind::UnionFind(int n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i; 
            rank[i] = 1;    
        }
    }

    int UnionFind::find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); 
        }
        return parent[x];
    }

    void UnionFind::Union(int u1, int u2) {
        int root_u1 = find(u1);
        int root_u2 = find(u2);
    
        if (root_u1 != root_u2) {
            if (rank[root_u1] > rank[root_u2]) {
                parent[root_u2] = root_u1; 
            } else if (rank[root_u1] < rank[root_u2]) {
                parent[root_u1] = root_u2; 
            } else {
                parent[root_u2] = root_u1;
                rank[root_u1]++; 
            }
        }
    }

    bool UnionFind::connected(int u, int v){
        return find(u)==find(v);
    }

    void UnionFind::print(int n) {
        std::cout << "Parent array: ";
        for (int i = 0; i < n; i++) {
            std::cout << parent[i] << " ";
        }
        std::cout << "\nRank array: ";
        for (int i = 0; i < n; i++) {
            std::cout << rank[i] << " ";
        }
        std::cout << std::endl;
    }



    void UnionFind::printTree(int n) {
    std::cout << "Union-Find Tree Structure:" << std::endl;
    for (int i = 0; i < n; i++) {
        int root = find(i);
        std::cout << "Node " << i << " -> Root " << root << std::endl;
    }

    
    std::cout << "\nTree Structure:" << std::endl;
    for (int i = 0; i < n; i++) {
        if (parent[i] == i) {  
            std::cout << "Root " << i << ": ";
            for (int j = 0; j < n; j++) {
                if (i != j && find(j) == i) {
                    std::cout << j << " ";
                }
            }
            std::cout << std::endl;
        }
    }
}

    UnionFind::~UnionFind (){}
}