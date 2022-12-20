//
// Created by loki on 20.12.22.
//

#include "Task2.h"

template<typename DATA, typename NAME, typename WEIGHT>
Task2<DATA, NAME, WEIGHT>::Task2(SimpleGraph<DATA, NAME, WEIGHT> *g) {
    G = g;
    restart();
}

template<typename DATA, typename NAME, typename WEIGHT>
Task2<DATA, NAME, WEIGHT>::Task2(Task2 &o) {
    G = o.G;
    restart();
}

template<typename DATA, typename NAME, typename WEIGHT>
Task2<DATA, NAME, WEIGHT>::~Task2() {
}

template<typename DATA, typename NAME, typename WEIGHT>
vector<int> &Task2<DATA, NAME, WEIGHT>::result() {
    return vc;
}

template<typename DATA, typename NAME, typename WEIGHT>
void Task2<DATA, NAME, WEIGHT>::restart() {
    OK = true;
    vc = vector<int>(G->getV(), -1);
    for (int v = 0; v < G->getV(); v++)
        if (vc[v] == -1)
            if (!dfsR(v, 0)) {
                OK = false;
                return;
            }
}

template<typename DATA, typename NAME, typename WEIGHT>
void Task2<DATA, NAME, WEIGHT>::set(SimpleGraph<DATA, NAME, WEIGHT> *g) {
    G = g;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool Task2<DATA, NAME, WEIGHT>::dfsR(int v, int c) {
    vc[v] = (c + 1) % 2;
    for (auto t = G->adjEBegin(v); t != G->adjEEnd(v); t++) {
        if (vc[(*t)->getV2()->getInd()] == -1) {
            if (!dfsR((*t)->getV2()->getInd(), vc[v]))
                return false;
        } else if (vc[(*t)->getV2()->getInd()] != c)
            return false;
    }
    return true;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool Task2<DATA, NAME, WEIGHT>::bipartite() const { return OK; }

