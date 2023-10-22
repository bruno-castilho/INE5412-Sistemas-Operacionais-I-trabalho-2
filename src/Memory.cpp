#include "Memory.h"

Memory::Memory(int n_frames){
    this->n_frames = n_frames;
    this->frames = new Frame[n_frames];

}

Memory::~Memory(){
    delete[] frames;
}

int Memory::request(int page){
    for (int i = 0; i < this->n_frames; i++)
        if (this->frames[i].bit == 1 && this->frames[i].page == page) 
            return i;

    return -1; 
}

void Memory::setPage(int page, int frame){
    this->frames[frame].page = page;
    this->frames[frame].bit = 1;
}