//itamarbabai98@gmail.com
#include <iostream>
#include <stdexcept>
#include "Queue.hpp"

namespace graphs
{
    Queue::Queue(int num){
        arr=new int[num];
        start=0;
        end=0;
        V=num+1;
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
    bool Queue::is_empty(){
        return start==end;
    }

    Queue::~Queue(){
        delete[] arr;
    }

}