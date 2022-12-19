//
// Created by loki on 18.12.22.
//

#include "VertexIterator.h"

template<typename DATA, typename NAME, typename WEIGHT>
VertexIterator<DATA, NAME, WEIGHT>::VertexIterator(vector<VertexT *> &_vertexVector, int ind) {
    vertexVector = _vertexVector;
    index = ind;
}

template
class VertexIterator<int, string, int>;