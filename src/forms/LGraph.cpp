//
// Created by loki on 18.12.22.
//

#include "LGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
LGraph<DATA, NAME, WEIGHT>::LGraph() {

}

template<typename DATA, typename NAME, typename WEIGHT>
bool LGraph<DATA, NAME, WEIGHT>::hasEdge(int i, int j) {
    return true;
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::getEdge(VertexT *v1, VertexT *v2) {
    return nullptr;//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
bool LGraph<DATA, NAME, WEIGHT>::DeleteE(EdgeT *e) {
    return false;//todo
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::InsertE() {
    return nullptr;//todo
}

template
class LGraph<int, std::string, int>;