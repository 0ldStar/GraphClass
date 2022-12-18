//
// Created by loki on 18.12.22.
//

#ifndef ASD_RGR_SIMPLEGRAPH_H
#define ASD_RGR_SIMPLEGRAPH_H

#define LGraphType false
#define MGraphType true
#define DGraphType true
#define NonDGraphTyped false

#include <iostream>
#include "elements/Edge.h"
#include "elements/Vertex.h"
#include "forms/GraphForm.h"
#include "forms/LGraph.h"
#include "forms/MGraph.h"

//using namespace std;

template<typename DATA, typename NAME, typename WEIGHT>
class SimpleGraph {
public:
    using VertexT = Vertex<DATA, NAME>;
    using EdgeT = Edge<DATA, NAME, WEIGHT>;

    SimpleGraph();

    SimpleGraph(int _VCount, bool _D, bool _F);

    SimpleGraph(int _VCount, int ECount, bool _D, bool _F);

    SimpleGraph(SimpleGraph &G);

    ~SimpleGraph();

    int getV();

    int getE();

    bool Directed();

    bool Dense();

    int getK();

    void toListGraph();

    void toMatrixGraph();

    VertexT *InsertV();

    bool DeleteV(VertexT *v);

    void printGraph();

private:

    int VCount;
    int ECount;
    bool D;
    bool dense;
    int K;
    GraphForm<DATA, NAME, WEIGHT> *graphForm;
};


#endif //ASD_RGR_SIMPLEGRAPH_H
