//
// Created by loki on 18.12.22.
//

#ifndef ASD_RGR_MGRAPH_H
#define ASD_RGR_MGRAPH_H

#include "../SimpleGraph.h"
#include "GraphForm.h"

template<typename DATA, typename NAME, typename WEIGHT>
class MGraph : public GraphForm<DATA, NAME, WEIGHT> {
public:
    using VertexT = Vertex<DATA, NAME>;
    using EdgeT = Edge<DATA, NAME, WEIGHT>;

    MGraph();

    bool hasEdge(int i, int j);

    EdgeT *InsertE();

    bool DeleteE(EdgeT *e);

    EdgeT *getEdge(VertexT *v1, VertexT *v2);

private:
    vector<vector<Vertex<DATA, NAME> *>> matrix;
};


#endif //ASD_RGR_MGRAPH_H
