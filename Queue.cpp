// //itamarbabai98@gmail.com
// #include <iostream>
// #include <stdexcept>
// #include <limits> 
// #include "Queue.hpp"

// namespace graphs
// {
//     Queue::Queue(int num){
//         arr=new int[num];
//         start=0;
//         end=0;
//         V=num+1;
//         q_size=0;
//     }

//     bool Queue::push(int v){
//         if ((end+1)%V == start){
//             throw std::runtime_error("The Queue is full!");
//         }
//             arr[end]=v;
//             end=(end+1)%V;
//             q_size++;
//             std::cout<<v<<std::endl;
//             return true;
        
//     }

//     int Queue::pop(){

//         if (start==end){
//             throw std::runtime_error("The Queue is empty!");
//         }
//         int value = arr[start];
//         start = (start + 1) % V;
//         q_size--;

//         return value;
//     }

    
//     int Queue::min_pop(int *d){ //enabls pra by wights

      
//         int inf = std::numeric_limits<int>::max();
//         int min = inf , index=-1;

//         if (start==end){
//             throw std::runtime_error("The Queue is empty!");
//         }
//         for (int i = start; i != end; i = (i + 1) % V) {
//             if (d[i] < min) {
//                 min = d[i];
//                 index = i;
//             }
//         }
//         if (index == -1) {
//             throw std::runtime_error("Unexpected error: No minimum found.");
//         }
//         int value = arr[index];
//         q_size--;
//         // for (int j = index; j != start; j = (j - 1 + V) % V) {
//         //     arr[j] = arr[(j - 1 + V) % V];
//         // }
//         arr[index] = inf;
//         while (q_size > 0 && arr[start] == inf) {
//             start = (start + 1) % V;
//         }
    
//        // start = (start + 1) % V;

//         return value;
//     }

//     bool Queue::is_empty(){
//         return q_size==0;
//     }

//     Queue::~Queue(){
//         delete[] arr;
//     }

// }



//itamarbabai98@gmail.com
#include <iostream>
#include <stdexcept>
#include <limits> 
#include "Queue.hpp"

namespace graphs
{
    Queue::Queue(int num){
        arr=new int[num];
        start=0;
        end=0;
        V=num+1;
       // q_size=0;
    }

    bool Queue::push(int v){
        if ((end+1)%V == start){
            throw std::runtime_error("The Queue is full!");
        }
            arr[end]=v;
            end=(end+1)%V;
            std::cout<<v<<std::endl;
            return true;
        
    }

    int Queue::pop(){

        if (start==end){
            throw std::runtime_error("The Queue is empty!");
        }
        int value = arr[start];
        start = (start + 1) % V;

        return value;
    }
    // int Queue::min_pop(int *d){ //enabls pra by wights
      
    //     int inf = std::numeric_limits<int>::max();
    //     int min = inf , index=-1;

    //     if (start==end){
    //         throw std::runtime_error("The Queue is empty!");
    //     }
    //     for (int i = start; i != end; i = (i + 1) % V) {
    //         if (d[i] < min) {
    //             min = d[i];
    //             index = i;
    //         }
    //     }
    //     if (index == -1) {
    //         throw std::runtime_error("Unexpected error: No minimum found.");
    //     }
    //     int value = arr[index];
    //     for (int j = index; j != start; j = (j - 1 + V) % V) {
    //         arr[j] = arr[(j - 1 + V) % V];
    //     }
    
    //     start = (start + 1) % V;

    //     return value;
    // }

    bool Queue::is_empty(){
        return start==end;
    }

    Queue::~Queue(){
        delete[] arr;
    }

}
