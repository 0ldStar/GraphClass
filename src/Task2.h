//
// Created by loki on 20.12.22.
//

#ifndef ASD_RGR_TASK2_H
#define ASD_RGR_TASK2_H

#include <vector>
#include "SimpleGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
class Task2 {
    SimpleGraph<DATA, NAME, WEIGHT> *G;
    bool OK;
    vector<int> vc;

    bool dfsR(int v, int c) {
        vc[v] = (c + 1) % 2;

        for (auto t = G->adjEBegin(v); t != G->adjEEnd(v); t++) {
            if (vc[t.getInd()] == -1) {
                if (!dfsR(t.getInd(), vc[v]))
                    return false;
            } else if (vc[t.getInd()] != c)
            return false;
        }
        return true;
    }

public:
    Task2(SimpleGraph<DATA, NAME, WEIGHT> *_G) {
        G = _G;
        OK = true;
        vc = vector<int>(G->getV(), -1);
        for (int v = 0; v < G->getV(); v++)
            if (vc[v] == -1)
                if (!dfsR(v, 0)) {
                    OK = false;
                    return;
                }
    }

    bool bipartite() const { return OK; }

    int color(int v) const { return vc[v]; }
};


#endif //ASD_RGR_TASK2_H
