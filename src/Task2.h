//
// Created by loki on 20.12.22.
//

#ifndef ASD_RGR_TASK2_H
#define ASD_RGR_TASK2_H

#include <vector>
#include "SimpleGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
class Task2 {

public:
    Task2(SimpleGraph<DATA, NAME, WEIGHT> *g);

    Task2(Task2 &o);

    ~Task2();

    void set(SimpleGraph<DATA, NAME, WEIGHT> *g);

    void restart();

    vector<int> &result();

    bool bipartite() const;

private:
    SimpleGraph<DATA, NAME, WEIGHT> *G;
    bool OK;
    vector<int> vc;

    bool dfsR(int v, int c);

};

template
class Task2<int, string, int>;


#endif //ASD_RGR_TASK2_H
