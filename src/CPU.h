#ifndef CPU_H
#define CPU_H

#include <vector>

#include "Memory.h"
#include "SO.h"

using namespace std;

class CPU{
    private:
        vector<int > refs; // Lista de referencias de paginas.
        Memory* memory; 
        SO* so; 

    public:
        CPU(vector<int> refs, Memory* memory, SO* so);
        ~CPU();

        // Executa cpu.
        void run();
};

#endif