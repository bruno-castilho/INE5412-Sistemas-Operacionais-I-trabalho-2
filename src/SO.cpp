#include "SO.h"

SO::SO(int n_frames, Memory* memory, int type) {
    this->memory = memory;
    this->type = type;
    this->fifo = new FIFO(n_frames);
    this->lru = new LRU(n_frames);
    this->opt = new OPT(n_frames);
}

SO::~SO() {
    delete fifo;
    delete lru;
    delete opt;
}

void SO::page_fault(vector<int> refs, int index) {
    int frame;
    switch (this->type) {
        case 1:
            frame = this->lru->insertPage(refs[index]);
            break;
        case 2: {
            // Calcula predict da página.
            int predict = index;
            int refs_size = refs.size();

            for (int i = index + 1; i <= refs_size; i++) {
                predict++;

                if (i == refs_size || refs[i] == refs[index])
                    break;
            }

            frame = this->opt->insertPage(refs[index], predict);
            break;
        }
        default:
            frame = this->fifo->insertPage(refs[index]);
            break;
    }

    // Aloca página na memória.
    this->memory->setPage(refs[index], frame);
    // Acrescenta uma falta de página no contador.
    this->page_faults++;
}

void SO::page_hit(vector<int> refs, int index, int frame) {
        switch (this->type) {
        case 1: {
            // Atualiza as posições da lista no caso de usar o algoritmo LRU.
            this->lru->updateList(refs[index]);
            break;
        } 
        case 2: {
            // Calcula predict da página.
            int predict = index;
            int refs_size = refs.size();

            for (int i = index + 1; i <= refs_size; i++) {
                predict++;

                if (i == refs_size || refs[i] == refs[index])
                    break;
            }
            // Atualiza predict da página no caso de usar o algoritmo OPT.
            this->opt->setNewPredict(frame, predict);
            break;
        }
            
        default:
            break;
    }

}

int SO::getPageFaults() {
    return this->page_faults;
}