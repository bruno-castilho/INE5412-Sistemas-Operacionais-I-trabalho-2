#ifndef LRU_H
#define LRU_H

class LRU {
private:
    // Nó de uma lista ligada.
    struct Node {
        int page; // Número da página.
        int frame; // Número do frame da memória onde a página se encontra.
        Node* next_node; // Proximo nó da lista.
        Node* back_node; // Nó anterior da lista.
    };

    // Atributos da lista.
    struct List {
        Node* first_node;
        Node* last_node;
        int list_size = 0;
    };

    // Lista.
    List list;
    
    // Número de frames.
    int n_frames;

public:
    LRU(int n_frames);
    ~LRU();

    // Insere uma nova página na lista, retornando o frame onde essa página deverá ser alocada.
    int insertPage(int newPage);
    
    // Coloca a página mencionada no início da fila.
    void updateList(int page);
};

#endif
