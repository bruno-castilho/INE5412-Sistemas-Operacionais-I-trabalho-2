#include "FIFO.h"

FIFO::FIFO(int n_frames) {
    this->n_frames = n_frames;
}

FIFO::~FIFO() {
    
}

int FIFO::insertPage(int newPage) {
    // Tamanho atual da fila.
    int queueSize = this->fifo.size();

    // Se o tamanho da fila for menor que a quantidade de frames da memória.
    if (queueSize < this->n_frames) {
        // Cria um novo nó na fila.
        Node node = {newPage, queueSize};
        this->fifo.push(node);
        
        // Retorna o frame.
        return node.frame;
    } else {
        // Pega o primeiro nó da fila.
        Node node = this->fifo.front();
        this->fifo.pop();

        // Adiciona a nova página ao nó e insere no final da fila.
        node.page = newPage;
        this->fifo.push(node);
        
        // Retorna o frame.
        return node.frame;
    }
}
