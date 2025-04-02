//itamarbabai98@gmail.com

#ifndef EDGE_HEADER
#define EDGE_HEADER

namespace graphs
{
    
    class Edge
    {
    private:
        int neighbor, weight;
    public:
        Edge();
        Edge(int neighbor, int weight);
        int get_neighbor();
        int get_weigt();
        void set_weigt(int val);
        void print();
        ~Edge();
    };
};
#endif


