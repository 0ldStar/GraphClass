//
// Created by loki on 18.12.22.
//

#include "MGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
MGraph<DATA, NAME, WEIGHT>::MGraph(unsigned _size, bool _directed) {
    size = _size;
    matrix.resize(size);
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = nullptr;
        }
    }
    directed = _directed;
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
}

template<typename DATA, typename NAME, typename WEIGHT>
MGraph<DATA, NAME, WEIGHT>::MGraph(MGraph &G) {
    size = G.size;
    matrix.resize(size);
    for (int i = 0; i < size; ++i) {
        matrix[i].resize(size);
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = G.matrix[i][j];
        }
    }
    directed = G.directed;
    for (int i = 0; i < size; ++i) {
        vertexVector[i] = G.vertexVector[i];
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
MGraph<DATA, NAME, WEIGHT>::~MGraph() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            delete matrix[i][j];
        }
    }
    delete edgeVector;
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
bool MGraph<DATA, NAME, WEIGHT>::deleteV(int v) {
    for (int i = 0; i < size; ++i) {
        if (i == v) {
            for (int j = 0; j < size; ++j) { // clear row
                delete matrix[i][j];
                matrix[i][j] = nullptr;
            }
            for (int j = 0; j < size; ++j) {  // clear and move column
                if (j != i) {
                    delete matrix[j][i];
                    matrix[j][i] = nullptr;

//                    for (int k = i; k < size - 1; ++k) {
//                        matrix[j][k] = matrix[j][k + 1];
//                    }
//                    matrix[j][size-1] = nullptr;
//                    matrix[j].resize(size - 1);
                }
            }
//            for (int j = i; j < size - 1; ++j) { // move row
//                matrix[j] = matrix[j + 1];
//            }
//            size--;
//            matrix.resize(size);
            return true;
        }
    }
    return false;
}

template<typename DATA, typename NAME, typename WEIGHT>
void MGraph<DATA, NAME, WEIGHT>::insertV(int v) {
    if (v >= size) {
        matrix.resize(v + 1);
        for (int i = 0; i < v + 1; ++i) {
            matrix[i].resize(v + 1);
            for (int j = size; j < v + 1; ++j) {
                matrix[i][j] = nullptr;
            }
        }
        size++;
    }
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *MGraph<DATA, NAME, WEIGHT>::insertE(VertexT *v1, VertexT *v2) {
    int w = ((rand() % 9) + 1);
    if (!directed)
        matrix[v2->getInd()][v1->getInd()] = new Edge<DATA, NAME, WEIGHT>(v2, v1, w);
    return matrix[v1->getInd()][v2->getInd()] = new Edge<DATA, NAME, WEIGHT>(v1, v2, w);
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
vector<Vertex<DATA, NAME> *> &MGraph<DATA, NAME, WEIGHT>::getVertexVector() {
    return vertexVector;
}

template<typename DATA, typename NAME, typename WEIGHT>
vector<Edge<DATA, NAME, WEIGHT> *> *MGraph<DATA, NAME, WEIGHT>::getEdgeVector() {
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j])
                edgeVector->push_back(matrix[i][j]);
        }
    }
    return edgeVector;
}

template<typename DATA, typename NAME, typename WEIGHT>
vector<Edge<DATA, NAME, WEIGHT> *> *MGraph<DATA, NAME, WEIGHT>::getEdgeVector(int v) {
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
    if (v < size)
        for (int i = 0; i < size; ++i) {
            if (matrix[v][i])
                edgeVector->push_back(matrix[v][i]);
        }
    return edgeVector;
}

template
class MGraph<int, std::string, int>;