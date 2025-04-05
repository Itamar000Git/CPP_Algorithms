//itamarbabai98@gmail.com
#ifndef QUEUE_HEADER
#define QUEUE_HEADER
namespace graphs
{
    class Queue
    {
    private:
        int *arr;
        int start, end, V ,q_size;
    public:
        Queue(int num);
        bool push(int u);
        int pop();
        int min_pop(int * d);
        bool is_empty();
        ~Queue();
    };

}



#endif