//itamarbabai98@gmail.com

#include <iostream>
#include "Edge.hpp"

namespace graphs
{
Edge::Edge(){
    neighbor=-1;
    weight=-1;
}

Edge::Edge(int n, int w =1)
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

void Edge::print() {
    std::cout << "(" << neighbor << ", " << weight << ") ";
}
Edge::~Edge(){}

}