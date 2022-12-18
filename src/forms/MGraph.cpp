//
// Created by loki on 18.12.22.
//

#include "MGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
MGraph<DATA, NAME, WEIGHT>::MGraph(unsigned _size) {
    size = _size;
    matrix.resize(size);
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = nullptr;
        }
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
bool MGraph<DATA, NAME, WEIGHT>::hasEdge(int i, int j) {
    return matrix[i][j];
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *MGraph<DATA, NAME, WEIGHT>::getEdge(VertexT *v1, VertexT *v2) {
    return matrix[v1->getInd()][v2->getInd()];
}

template<typename DATA, typename NAME, typename WEIGHT>
bool MGraph<DATA, NAME, WEIGHT>::deleteE(EdgeT *e) {
    int i1 = e->getV1()->getInd();
    int i2 = e->getV2()->getInd();
    if (matrix[i1][i2]) {
        delete matrix[i1][i2];
        matrix[i1][i2] = nullptr;
        return true;
    }
    return false;
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *MGraph<DATA, NAME, WEIGHT>::insertE(VertexT *v1, VertexT *v2) {
    matrix[v1->getInd()][v2->getInd()] = new Edge<DATA, NAME, WEIGHT>(v1, v2);
    return matrix[v2->getInd()][v1->getInd()] = new Edge<DATA, NAME, WEIGHT>(v2, v1);
}

template<typename DATA, typename NAME, typename WEIGHT>
void MGraph<DATA, NAME, WEIGHT>::print() {
    cout << "MATRIX" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << (matrix[i][j] ? "1" : "0") << " ";
        }
        cout << endl;
    }
}
template<typename DATA, typename NAME, typename WEIGHT>
vector<Vertex<DATA, NAME> *>& MGraph<DATA, NAME, WEIGHT>::getVertexVector() {
    return vertexVector;
}
template
class MGraph<int, std::string, int>;