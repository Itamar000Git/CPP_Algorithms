//itamarbabai98@gmail.com
#ifndef QUEUE_HEADER
#define QUEUE_HEADER
namespace graphs
{
    class Queue
    {
    private:
        int *arr;
        int start, end, V;
    public:
        Queue(int num);
        bool push(int u);
        int pop();
        bool is_empty();
        ~Queue();
    };

}



#endif