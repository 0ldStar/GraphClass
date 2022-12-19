//
// Created by loki on 18.12.22.
//

#ifndef ASD_RGR_GRAPHFORM_H
#define ASD_RGR_GRAPHFORM_H

#include <string>
#include <vector>

#include "../elements/Vertex.h"
#include "../elements/Edge.h"

template<typename DATA, typename NAME, typename WEIGHT>
class GraphForm {
    using VertexT = Vertex<DATA, NAME>;
    using EdgeT = Edge<DATA, NAME, WEIGHT>;
public:
    virtual bool hasEdge(int i, int j) = 0;

    virtual EdgeT *insertE(VertexT *v1, VertexT *v2) = 0;

    virtual bool deleteE(EdgeT *e) = 0;

    virtual EdgeT *getEdge(VertexT *v1, VertexT *v2) = 0;

    virtual void print() = 0;

    virtual vector<VertexT *> &getVertexVector() = 0;
};


#endif //ASD_RGR_GRAPHFORM_H
