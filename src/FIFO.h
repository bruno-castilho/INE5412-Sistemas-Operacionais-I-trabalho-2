#ifndef FIFO_H
#define FIFO_H

#include <queue>
using namespace std;

class FIFO {
private:
    // Nó de uma fila.
    struct Node {
        int page; // Número da página.
        int frame; // Número do frame da memória onde a página se encontra.
    };

    queue<Node> fifo; // Fila.
    int n_frames; // Número de frames da memória.

public:
    FIFO(int n_frames);
    ~FIFO();

    // Insere uma nova página na fila, retornando o frame onde essa página deverá ser alocada.
    int insertPage(int newPage);
};

#endif
