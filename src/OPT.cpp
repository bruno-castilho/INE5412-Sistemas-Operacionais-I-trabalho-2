#include "OPT.h"

OPT::OPT(int n_frames) {
    this->n_frames = n_frames;
}

OPT::~OPT() {
    for (Node* node : this->list) {
        delete node;
    }
}

int OPT::insertPage(int newPage, int predict) {
    int list_size = list.size();

    // Se o tamanho da lista for menor que a quantidade de frames da memória.
    if (list_size < n_frames) {
        // Cria um novo nó.
        Node* node = new Node;
        node->page = newPage;
        node->frame = list_size;
        node->predict = predict;

        // Insere no final da lista.
        list.push_back(node);
        return node->frame;
    } else {
        // Busca a posição na lista onde tem a página com maior predict.
        int index = 0;
        for (int i = 0; i < list_size; i++) {
            if (list[index]->predict < list[i]->predict) {
                index = i;
            }
        }

        // Adiciona a nova página na posição.
        list[index]->page = newPage;
        list[index]->predict = predict;

        return list[index]->frame;
    }
}

void OPT::setNewPredict(int index, int predict) {
    // Insere o novo predict de uma página.
    list[index]->predict = predict;
}