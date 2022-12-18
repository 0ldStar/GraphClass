//
// Created by loki on 18.12.22.
//

#ifndef ASD_RGR_LGRAPH_H
#define ASD_RGR_LGRAPH_H

#include "../SimpleGraph.h"
#include "GraphForm.h"

template<typename DATA, typename NAME, typename WEIGHT>
class LGraph : public GraphForm<DATA, NAME, WEIGHT> {
public:
    using VertexT = Vertex<DATA, NAME>;
    using EdgeT = Edge<DATA, NAME, WEIGHT>;

    LGraph();

    bool hasEdge(int i, int j);

    EdgeT *InsertE();

    bool DeleteE(EdgeT *e);

    EdgeT *getEdge(VertexT *v1, VertexT *v2);

private:

    class ENode {
        Edge<DATA, NAME, WEIGHT> *e;
        ENode *next;
    };

    class VNode {
        Vertex<DATA, NAME> *v;
        ENode *eNode;
        VNode *next;
    };

    VNode *list;


};



#endif //ASD_RGR_LGRAPH_H
