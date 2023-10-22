#ifndef OPT_H
#define OPT_H

#include <vector>
using namespace std;

class OPT {
private:
    // Nó de uma lista.
    struct Node {
        int page; // Número da página.
        int frame; // Número do frame da memória onde a página se encontra.
        int predict; // Quantas páginas serão requisitadas antes desta página ser utilizada novamente.
    };

    // Lista.
    vector<Node*> list;
    int n_frames; // Número de frames da memória.

public:
    OPT(int n_frames);
    ~OPT();

    // Insere uma nova página na lista, retornando o frame onde essa página deverá ser alocada.
    int insertPage(int newPage, int predict);

    // Insere o novo predict da página mencionada.
    void setNewPredict(int index, int predict);
};

#endif
