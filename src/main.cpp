#include <iostream>
#include <cstdlib>
#include <vector>

#include "CPU.h"
#include "Memory.h"
#include "FIFO.h"
#include "SO.h"

using namespace std;

int main(int argc, char *argv[])
{    
    // Verifica se o número correto de argumentos foi fornecido.
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <número_de_frames> < <endereço_do_arquivo>" << endl;
        return 1;
    }

    // Converte o argumento para o número de quadros (frames).
    int frames = atoi(argv[1]);

    // Verifica se o número de quadros é válido (maior que zero).
    if (frames <= 0) {
        cerr << "O número de frames deve ser maior que zero." << endl;
        return 1;
    }

    // Vetor para armazenar as referências às páginas.
    vector<int> refs;

    // Lé as referencias do arquivo.
    int numero;
    while(cin >> numero) {
        refs.push_back(int(numero));
    }


    cout << frames << " quadros" << endl;
    cout << refs.size() << " refs" << endl;


    // Execução com algoritimo FIFO.
    Memory* memory1 = new Memory(frames);
    SO* so1 = new SO(frames, memory1, 0);
    CPU* cpu1 = new CPU(refs, memory1, so1);
    cpu1->run();
    cout << "FIFO: " << so1->getPageFaults() << " PFs" << endl; 
    delete cpu1;
    delete so1;
    delete memory1;
    
    // EXECUÇAO COM O ALGORITMO LRU.
    Memory* memory2 = new Memory(frames);
    SO* so2 = new SO(frames, memory2, 1);
    CPU* cpu2 = new CPU(refs, memory2, so2);
    cpu2->run();
    cout << "LRU: " << so2->getPageFaults() << " PFs" << endl; 
    delete cpu2;
    delete so2;
    delete memory2;

    // EXECUÇÃO COM O ALGORITMO OPT.
    Memory* memory3 = new Memory(frames);
    SO* so3 = new SO(frames, memory3, 2);
    CPU* cpu3 = new CPU(refs, memory3, so3);
    cpu3->run();
    cout << "OPT: " << so3->getPageFaults() << " PFs" << endl; 
    delete cpu3;
    delete so3;
    delete memory3;

    refs.clear();

    return 0;
}