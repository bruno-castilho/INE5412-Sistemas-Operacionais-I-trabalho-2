#include "LRU.h"

LRU::LRU(int n_frames) {
    this->n_frames = n_frames;
}

LRU::~LRU() {
    
}

int LRU::insertPage(int newPage) {
    // Se o tamanho da fila for menor que a quantidade de frames da memória.
    if (this->list.list_size < this->n_frames) {
        // Cria um novo nó.
        Node* node = new Node;
        node->page = newPage;
        node->frame = this->list.list_size;
    
        // Se a lista estiver vazia.
        if (this->list.list_size == 0) {
            // Identifica o nó como início e fim da lista.
            this->list.first_node = node;
            this->list.last_node = node;
        } else {
            // Insere o nó no início da lista.
            node->next_node = this->list.first_node;
            this->list.first_node->back_node = node;
            this->list.first_node = node;
        }
        
        // Acrescenta o tamanho da lista.
        this->list.list_size += 1;

        // Retorna o frame.
        return node->frame;
    } else {
        // Insere a nova página no último nó da fila.
        this->list.last_node->page = newPage;

        // Realoca o nó para o início da fila.
        this->list.last_node->next_node = this->list.first_node;
        this->list.first_node->back_node = this->list.last_node;
        
        this->list.first_node = this->list.last_node;
        this->list.last_node = this->list.last_node->back_node;

        this->list.first_node->back_node = nullptr;
        this->list.last_node->next_node = nullptr;
        
        // Retorna o frame.
        return list.first_node->frame;
    }
}

void LRU::updateList(int page) {
    
    // Se a página mencionada está no início da fila.
    if (this->list.first_node->page == page) {
        // Retorna.
        return;
    }
    // Se a página mencionada está no fim da fila.
    else if (this->list.last_node->page == page) {
        
        // Realoca o último nó da fila para o início da fila.
        this->list.last_node->next_node = this->list.first_node;
        this->list.first_node->back_node = this->list.last_node;

        this->list.first_node = this->list.last_node;
        this->list.last_node = this->list.last_node->back_node;

        this->list.first_node->back_node = nullptr;
        this->list.last_node->next_node = nullptr;
    } 
    else {
        
        // Procura o nó com a página referenciada.
        Node* found_node = this->list.first_node->next_node;

        // Enquanto found_node não for o penultimo nó da lista.
        while (found_node->next_node->next_node) {
            if (found_node->page == page) {
                break;
            }
            
            found_node = found_node->next_node;
        }

        
        // Realoca o nó para o início da fila.
        found_node->back_node->next_node = found_node->next_node;
        found_node->next_node->back_node = found_node->back_node;

        found_node->next_node = this->list.first_node;
        found_node->back_node = nullptr;

        this->list.first_node->back_node = found_node;
        this->list.first_node = found_node;
    }
}