//
// Created by loki on 18.12.22.
//

#include "LGraph.h"

template<typename DATA, typename NAME, typename WEIGHT>
LGraph<DATA, NAME, WEIGHT>::LGraph(unsigned _size, bool _directed) {
    size = _size;
    directed = _directed;
    list = new VNode(0, nullptr, nullptr);
    for (int i = 1; i < size; ++i) {
        list = new VNode(i, nullptr, list);
    }
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
}

template<typename DATA, typename NAME, typename WEIGHT>
LGraph<DATA, NAME, WEIGHT>::LGraph(LGraph &G) {
    size = G.size;
    directed = G.directed;
    edgeVector = G.edgeVector;
    list = G.list;
}

template<typename DATA, typename NAME, typename WEIGHT>
void LGraph<DATA, NAME, WEIGHT>::insertV(int v) {
    VNode *vtmp, *prev;
    vtmp = prev = list;
    ENode *etmp, *edel;
    if (!vtmp) {
        list = new VNode(v, nullptr, nullptr);
        return;
    }
    if (vtmp->v_ind == v) {
        return;
    }
    vtmp = vtmp->next;
    while (vtmp) {
        if (vtmp->v_ind == v) return;
        vtmp = vtmp->next;
        prev = prev->next;
    }
    prev->next = new VNode(v, nullptr, nullptr);
}

template<typename DATA, typename NAME, typename WEIGHT>
LGraph<DATA, NAME, WEIGHT>::~LGraph() {
    VNode *vtmp;
    ENode *elist, *etmp;
    while (list) {
        elist = list->eNode;
        while (elist) {
            etmp = elist->next;
            delete elist;
            elist = etmp;
        }
        vtmp = list->next;
        delete list;
        list = vtmp;
    }
    delete edgeVector;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool LGraph<DATA, NAME, WEIGHT>::hasEdge(int i, int j) {
    VNode *vtmp = list;
    ENode *etmp;
    Edge<DATA, NAME, WEIGHT> *e;
    while (vtmp) {
        etmp = vtmp->eNode;
        while (etmp) {
            e = etmp->e;
            if (e->getV1()->getInd() == i && e->getV2()->getInd() == j) {
                return true;
            }
            etmp = etmp->next;
        }
        vtmp = vtmp->next;
    }
    return false;
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::getEdge(VertexT *v1, VertexT *v2) {
    return getEdge(v1->getInd(), v2->getInd());
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::getEdge(int v1, int v2) {
    VNode *vtmp = list;
    ENode *etmp;
    Edge<DATA, NAME, WEIGHT> *e;
    while (vtmp) {
        etmp = vtmp->eNode;
        while (etmp && etmp->next) {
            e = etmp->next->e;
            if (e->getV1()->getInd() == v1 && e->getV2()->getInd() == v2) {
                return e;
            }
            etmp = etmp->next;
        }
        vtmp = vtmp->next;
    }
    return nullptr;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool LGraph<DATA, NAME, WEIGHT>::deleteE(EdgeT *e) {
    VNode *vtmp = list;
    ENode *etmp, *prev;
    while (vtmp) {
        prev = vtmp->eNode;
        etmp = vtmp->eNode;
        if (etmp && (etmp->e->getV1() == e->getV1() && etmp->e->getV2() == e->getV2())) {
            vtmp->eNode = etmp->next;
            delete etmp->e;
            delete etmp;
            return true;
        }
        if (etmp) etmp = etmp->next;
        while (etmp) {
            if (etmp && (etmp->e->getV1() == e->getV1() && etmp->e->getV2() == e->getV2())) {
                prev->next = etmp->next;
                delete etmp->e;
                delete etmp;
                return true;
            }
            prev = etmp;
            etmp = etmp->next;
        }
        vtmp = vtmp->next;
    }
    return false;
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::insertE(VertexT *v1, VertexT *v2) {
    if (!directed)
        insert(v2, v1);
    Edge<DATA, NAME, WEIGHT> *res = insert(v1, v2);
    return res;
}

template<typename DATA, typename NAME, typename WEIGHT>
void LGraph<DATA, NAME, WEIGHT>::setDirected(bool d) {
    directed = d;
}

template<typename DATA, typename NAME, typename WEIGHT>
bool LGraph<DATA, NAME, WEIGHT>::deleteV(int v) {
    VNode *vtmp, *prev;
    vtmp = prev = list;
    ENode *etmp, *edel;
    if (vtmp && vtmp->v_ind == v) {
        etmp = vtmp->eNode;
        while (etmp) {
            edel = etmp;
            etmp = etmp->next;
            delete edel;
        }
        list = vtmp->next;
        delete vtmp;
        size--;
        return true;
    }
    if (vtmp) vtmp = vtmp->next;
    while (vtmp) {
        if (vtmp->v_ind == v) {
            etmp = vtmp->eNode;
            while (etmp) {
                edel = etmp;
                etmp = etmp->next;
                delete edel->e;
                delete edel;
            }
            prev->next = vtmp->next;
            delete vtmp;
            size--;
            return true;
        }
        prev = prev->next;
        vtmp = vtmp->next;
    }
    return false;
}

template<typename DATA, typename NAME, typename WEIGHT>
void LGraph<DATA, NAME, WEIGHT>::print() {
    int i, j;
    VertexT *v;
    VNode *vtmp, *prev;
    vtmp = prev = list;
    ENode *etmp, *edel;
    cout << "LIST" << endl;
    while (vtmp) {
        cout << "*" << vtmp->v_ind << "->";
        etmp = vtmp->eNode;
        while (etmp) {
            cout << etmp->e->getV2()->getInd() << "->";
            etmp = etmp->next;
        }
        cout << endl;
        vtmp = vtmp->next;
    }

}

template<typename DATA, typename NAME, typename WEIGHT>
vector<Vertex<DATA, NAME> *> &LGraph<DATA, NAME, WEIGHT>::getVertexVector() {
    return vertexVector;
}

template<typename DATA, typename NAME, typename WEIGHT>
Edge<DATA, NAME, WEIGHT> *LGraph<DATA, NAME, WEIGHT>::insert(VertexT *v1, VertexT *v2) {
    VNode *vtmp = list;
    ENode *etmp;
    Edge<DATA, NAME, WEIGHT> *res;
    int w = ((rand() % 9) + 1);
    while (vtmp) {
        if (vtmp->v_ind == v1->getInd()) {
            etmp = vtmp->eNode;
            res = new Edge<DATA, NAME, WEIGHT>(v1, v2, w);
            if (!etmp) {
                vtmp->eNode = new ENode(res, nullptr);
            } else {
                while (etmp->next) {
                    etmp = etmp->next;
                }
                etmp->next = new ENode(res, nullptr);
            }
            return res;
        }
        vtmp = vtmp->next;
    }
    return nullptr;
}

template<typename DATA, typename NAME, typename WEIGHT>
vector<Edge<DATA, NAME, WEIGHT> *> *LGraph<DATA, NAME, WEIGHT>::getEdgeVector() {
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
    VNode *vtmp = list;
    ENode *etmp;

    while (vtmp) {
        etmp = vtmp->eNode;
        while (etmp) {
            edgeVector->push_back(etmp->e);
            etmp = etmp->next;
        }
        vtmp = vtmp->next;
    }
    return edgeVector;
}

template<typename DATA, typename NAME, typename WEIGHT>
vector<Edge<DATA, NAME, WEIGHT> *> *LGraph<DATA, NAME, WEIGHT>::getEdgeVector(int v) {
    edgeVector = new vector<Edge<DATA, NAME, WEIGHT> *>();
    VNode *vtmp = list;
    ENode *etmp;

    while (vtmp) {
        if (vtmp->v_ind == v) {
            etmp = vtmp->eNode;
            while (etmp) {
                edgeVector->push_back(etmp->e);
                etmp = etmp->next;
            }
            break;
        }
        vtmp = vtmp->next;
    }
    return edgeVector;
}


template
class LGraph<int, std::string, int>;