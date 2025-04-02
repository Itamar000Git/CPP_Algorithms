
#ifndef UNION_HEADER
#define UNION_HEADER
#include <iostream>
namespace graphs{
#define MAXN 100
    class UnionFind 
    {
    private:
        int parent[MAXN];
        int rank[MAXN];
    public:
        UnionFind (int num);
        void Union(int u1, int u2);
        int find(int v);
        bool connected(int u, int v);
        void print(int n);
        void printTree(int n);
        ~UnionFind ();
    };
    

    
}

#endif