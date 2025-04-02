//itamarbabai98@gmail.com
#ifndef PRIORITY_QUEUE_HEADER
#define PRIORITY_QUEUE_HEADER

namespace graphs
{           

    class praiority_Q
    {
    private:
         typedef struct Node{
            int weight;
            int data;
            int neigbor;
            int key;
            Node* next; //in Q
        }Node;

        Node *head;
        int size;

    public:
        praiority_Q(int s);
        praiority_Q();
        void pra_push(int u , int v , int w);//w = in dikjastra w and in prim key
        int pra_pop();
        void print() const;
        int min_pop(int * d);
        bool Q_is_empty();
        void set_key(int u, int v, int new_key);
        int get_key(int u,int v);
        void pra_push_key(int u , int v , int w ,int key);
        int pra_pop_key();
        void update_queue();
        bool is_in(int u , int v);
        ~praiority_Q();
    };



}
#endif