#ifndef SO_H
#define SO_H

#include "Memory.h"
#include "FIFO.h"
#include "LRU.h"
#include "OPT.h"

using namespace std;

class SO {
private:
    Memory* memory; // Memória
    FIFO* fifo; // Algoritmo de substituição de páginas FIFO.
    LRU* lru; // Algoritmo de substituição de páginas LRU.
    OPT* opt; // Algoritmo de substituição de páginas OPT (Ótimo).
    int page_faults = 0; // Número de faltas de páginas.
    int type; // Tipo de algoritmo que será utilizado {0: FIFO, 1: LRU, 2: OPT}
public:
    SO(int n_frames, Memory* memory, int type);
    ~SO();
    // Insere a página não encontrada na memória, no frame apontado pelo algoritmo utilizado.
    void page_fault(vector<int> refs, int index);

    // Informa um page hit para o algoritmo utilizado, caso necessário.
    void page_hit(vector<int> refs, int index, int frame);

    
    int getPageFaults();

};

#endif
