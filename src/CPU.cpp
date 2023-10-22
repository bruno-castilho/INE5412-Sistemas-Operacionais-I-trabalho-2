#include "CPU.h"
#include <iostream>
using namespace std;
CPU::CPU(vector<int> refs, Memory* memory, SO* so){
    this->memory = memory;
    this->so = so;
    this->refs = refs;
}

CPU::~CPU(){
    
}

void CPU::run(){
    int refs_size = this->refs.size();
    for (int i = 0; i < refs_size; i++){
        int frame = this->memory->request(this->refs[i]);

        if(frame == -1){
            this->so->page_fault(this->refs, i); 
               
        }else{
            this->so->page_hit(this->refs, i, frame);  
        }        
    }
}