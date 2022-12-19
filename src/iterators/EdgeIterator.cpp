//
// Created by loki on 18.12.22.
//

#include "EdgeIterator.h"

template<typename DATA, typename NAME, typename WEIGHT>
EdgeIterator<DATA, NAME, WEIGHT>::EdgeIterator(vector<EdgeT *> *_edgeVector, int ind) {
    index = ind;
    edgeVector = _edgeVector;
}

template
class EdgeIterator<int, string, int>;