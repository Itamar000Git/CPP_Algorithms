//itamarbabai98@gmail.com

#include <iostream>
#include <limits> 
#include "Edge.hpp"

namespace graphs
{
Edge::Edge(){
    neighbor=-1;
    weight=std::numeric_limits<int>::max();
}

Edge::Edge(int n, int w )
{
    neighbor=n;
    weight=w;   
}
int Edge::get_neighbor(){
    return neighbor;
}

int Edge::get_weigt(){
    return weight;
}
void Edge::set_weigt(int val){
    weight=val;
}

void Edge::print() {
    std::cout << "(" << neighbor << ", " << weight << ") ";
}
Edge::~Edge(){}

}