//itamarbabai98@gmail.com
#include <iostream>
#include <stdexcept>
#include <limits> 
#include "praiority_Q.hpp"


namespace graphs
{
    praiority_Q:: praiority_Q(int s):head(nullptr), size(0)
    {  
        pra_push(s,-1,0);
    }
    praiority_Q:: praiority_Q():head(nullptr), size(0)
    {  
    }

    void praiority_Q::pra_push(int u , int v , int w)
    {
        Node * new_node = new Node();
        new_node->data = u;
        new_node->weight = w;
        new_node->neigbor = v;

        if (!head || w < head->weight) {
            new_node->next = head;
            head = new_node;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->weight <= w) {
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
        }

        size++;
        
    }

    int praiority_Q::pra_pop()
    {
        if (Q_is_empty()) {
            throw std::runtime_error("PriorityQueue is empty!");
        }

        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        size--;

        return value;
    }

    void praiority_Q::print() const {
        Node* curr = head;
        while (curr) {
            std::cout << "(" << curr->data << ", " << curr->weight << ") -> ";
            curr = curr->next;
        }
        std::cout << "NULL\n";
    }

    bool praiority_Q::Q_is_empty()
    {
        return size==0;
    }
    void praiority_Q::set_key(int u, int v, int new_key){
        Node* curr = head;
        while (curr) {
            if (curr->data == u && curr->neigbor == v) {
                curr->key = new_key;
                update_queue();// Update the weight to maintain the priority queue order
                return;
            }
            curr = curr->next;
        }
        throw std::runtime_error("Node not found in the priority queue!");

    }
    int praiority_Q::get_key(int u,int v){
        Node* curr = head;
        while (curr) {
            if (curr->data == u && curr->neigbor == v) {
                return curr->key;
            }
            curr = curr->next;
        }
        throw std::runtime_error("Node not found in the priority queue!");
    }

    void praiority_Q::update_queue(){
        Node* curr = head;
        Node* next = curr->next;
        if (curr == nullptr) {
            return; // Queue is empty
        }
        if(next == nullptr) {
            return; // Only one element in the queue
        }
        if (curr->key > next->key) {
            // Swap the nodes
            curr->next = next->next;
            next->next = curr;
            head = next;
        }
        while (curr->next) {
            if (curr->key > curr->next->key) {
                // Swap the nodes
                Node* temp = curr->next;
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = curr->next;
        }
    }
    

    void praiority_Q::pra_push_key(int u, int v, int w, int key) {
        Node* new_node = new Node();
        new_node->data = u;
        new_node->weight = w;
        new_node->neigbor = v;
        new_node->key = key;
        new_node->next = nullptr;
    
        if (!head || key < head->key) { // שים לב לשינוי - key ולא weight
            new_node->next = head;
            head = new_node;
        } else {
            Node* curr = head;
            while (curr->next && curr->next->key <= key) { // משתמשים ב-key
                curr = curr->next;
            }
            new_node->next = curr->next;
            curr->next = new_node;
        }
        size++;
    }
    
    int praiority_Q::pra_pop_key()
    {
        if (Q_is_empty()) {
            throw std::runtime_error("PriorityQueue is empty!");
        }

        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        size--;

        return value;
    }

    bool praiority_Q::is_in(int u , int v)
    {
        Node* curr = head;
        while (curr) {
            if (curr->data == u && curr->neigbor == v) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    

    praiority_Q::~praiority_Q()
    {
        while (!Q_is_empty()) {
            pra_pop();
        }
    }
}