#ifndef MEMORY_H
#define MEMORY_H

class Memory {
private:
    // Frame.
    struct Frame {
        int page;
        bool bit = 0;
    };

    int n_frames; // Quantidade de frames.
    Frame* frames; // Lista de frames.

public:
    // Construtor.
    Memory(int n_frames);

    // Destrutor.
    ~Memory();

    // Busca uma página na memória; se a página não está alocada, retorna -1.
    int request(int page);

    // Coloca uma página em um frame na memória.
    void setPage(int page, int frame);
};

#endif
