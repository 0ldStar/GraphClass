//
// Created by loki on 18.12.22.
//

#include "SimpleGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph() {
    VCount = 0;
    ECount = 0;
    D = false;
    dense = false;
    graphForm = new LGraph<DATA, NAME, WEIGHT>(VCount, D);
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(int _VCount, bool _D, bool _F) {
    VCount = _VCount;
    ECount = 0;
    D = _D;
    dense = _F;

    if (dense == LGraphType)
        graphForm = new LGraph<DATA, NAME, WEIGHT>(VCount, D);
    else
        graphForm = new MGraph<DATA, NAME, WEIGHT>(VCount, D);

    for (int i = 0; i < VCount; ++i) {
        graphForm->getVertexVector().push_back(new VertexT());
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(int _VCount, int _ECount, bool _D, bool _F) {
    VCount = _VCount;
    ECount = _ECount;
    D = _D;
    dense = _F;

    if (dense == LGraphType)
        graphForm = new LGraph<DATA, NAME, WEIGHT>(VCount, D);
    else
        graphForm = new MGraph<DATA, NAME, WEIGHT>(VCount, D);

    for (int i = 0; i < VCount; ++i) {
        graphForm->getVertexVector().push_back(new VertexT());
        graphForm->getVertexVector()[i]->setName(to_string(i));
        graphForm->getVertexVector()[i]->setInd(i);
    }
    for (int i = 0; i < ECount; ++i) {
        graphForm->insertE(graphForm->getVertexVector()[i], graphForm->getVertexVector()[VCount - i - 1]);
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(SimpleGraph &G) {
    VCount = G.VCount;
    ECount = G.ECount;
    D = G.D;
    dense = G.dense;
    if (dense == LGraphType)
        graphForm = new LGraph<DATA, NAME, WEIGHT>(
                reinterpret_cast<LGraph<int, basic_string<char>, int> &>(G.graphForm));
    else
        graphForm = new MGraph<DATA, NAME, WEIGHT>(
                reinterpret_cast<MGraph<int, basic_string<char>, int> &>(G.graphForm));
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::~SimpleGraph() {
    delete graphForm;
}


template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::deleteV(VertexT *v) {
    return false;//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
Vertex<DATA, NAME> *SimpleGraph<DATA, NAME, WEIGHT>::insertV() {
    return nullptr;//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
void SimpleGraph<DATA, NAME, WEIGHT>::toMatrixGraph() {
    //todo
}

template<typename DATA, typename NAME, typename WEIGHT>
void SimpleGraph<DATA, NAME, WEIGHT>::toListGraph() {
//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
int SimpleGraph<DATA, NAME, WEIGHT>::getK() {
    int K;
    if (D)
        K = ECount / (VCount * (VCount - 1));
    else
        K = VCount * (VCount - 1) / 2;
    return K;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::isDense() {
    return dense;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::isDirected() {
    return D;
}

template<typename DATA, typename NAME, typename WEIGHT>
int SimpleGraph<DATA, NAME, WEIGHT>::getE() {
    return ECount;
}

template<typename DATA, typename NAME, typename WEIGHT>
int SimpleGraph<DATA, NAME, WEIGHT>::getV() {
    return VCount;
}


template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *SimpleGraph<DATA, NAME, WEIGHT>::getEdge(VertexT *v1, VertexT *v2) {
    return graphForm->getEdge(v1, v2);
}

template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::deleteE(EdgeT *e) {
    return graphForm->deleteE(e);
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *SimpleGraph<DATA, NAME, WEIGHT>::insertE(VertexT *i, VertexT *j) {
    return graphForm->insertE(i, j);
}

template<typename DATA, typename NAME, typename WEIGHT>
void SimpleGraph<DATA, NAME, WEIGHT>::printGraph() {
    graphForm->print();
}

template
class SimpleGraph<int, string, int>;
