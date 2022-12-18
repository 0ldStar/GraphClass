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
    K = 0;
    graphForm = new LGraph<DATA, NAME, WEIGHT>();
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(int _VCount, bool _D, bool _F) {
    VCount = _VCount;
    ECount = 0;
    D = _D;
    dense = _F;
    K = 0;

    if (dense)
        graphForm = new LGraph<DATA, NAME, WEIGHT>();
    else
        graphForm = new MGraph<DATA, NAME, WEIGHT>();

    for (int i = 0; i < VCount; ++i) {
        graphForm->vertexVector.push_back(new VertexT());
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(int _VCount, int _ECount, bool _D, bool _F) {
    VCount = _VCount;
    ECount = _ECount;
    D = _D;
    dense = _F;
    K = 0;

    if (dense)
        graphForm = new LGraph<DATA, NAME, WEIGHT>();
    else
        graphForm = new MGraph<DATA, NAME, WEIGHT>();
    for (int i = 0; i < VCount; ++i) {
        graphForm->vertexVector.push_back(new VertexT());
        graphForm->vertexVector[i]->setName(to_string(i));
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::SimpleGraph(SimpleGraph &G) {
    //todo
}

template<typename DATA, typename NAME, typename WEIGHT>
SimpleGraph<DATA, NAME, WEIGHT>::~SimpleGraph() {
//todo
}


template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::DeleteV(VertexT *v) {
    return false;//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
Vertex<DATA, NAME> *SimpleGraph<DATA, NAME, WEIGHT>::InsertV() {
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
    if (D)
        K = ECount / (VCount * (VCount - 1));
    else
        K = VCount * (VCount - 1) / 2;
    return K;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::Dense() {
    return dense;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool SimpleGraph<DATA, NAME, WEIGHT>::Directed() {
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
void SimpleGraph<DATA, NAME, WEIGHT>::printGraph() {
    int i, j;
    VertexT *v;
    EdgeT *e;
    if (dense) {
        cout << "  ";
        for (i = 0; i < getV(); i++) {
            v = graphForm->vertexVector[i];
            cout /*<< setw(4)*/ << v->getName();
        }
        cout << endl;
        for (i = 0; i < 5 * getV(); i++)
            cout << "_";
        cout << endl;
        for (i = 0; i < getV(); i++) {
            v = graphForm->vertexVector[i];
            cout << v->getName() << "|";
            for (j = 0; j < getV(); j++)
                if (graphForm->hasEdge(i, j)) {
                    e = graphForm->getEdge(graphForm->vertexVector[i], graphForm->vertexVector[j]);
                    if (e)
                        cout /*<< setw(4)*/ << e->getW();
                } else
                    cout /*<< setw(4)*/ << "0";
            cout << endl;
        }
    } else {
        for (i = 0; i < getV(); i++) {
            v = graphForm->vertexVector[i];
            cout << "*" << v->getName() << "->";
            for (j = 0; j < getV(); j++) {
                v = graphForm->vertexVector[j];
                if (graphForm->hasEdge(i, j))
                    cout << v->getName() << "->";
            }
            cout << endl;
        }
    }
};

template
class SimpleGraph<int, string, int>;
