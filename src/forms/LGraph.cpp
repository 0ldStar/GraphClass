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
}

template<typename DATA, typename NAME, typename WEIGHT>
LGraph<DATA, NAME, WEIGHT>::LGraph(LGraph &G) {

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
    VNode *vtmp = list;
    ENode *etmp;
    Edge<DATA, NAME, WEIGHT> *e;
    while (vtmp) {
        etmp = vtmp->eNode;
        while (etmp && etmp->next) {
            e = etmp->next->e;
            if (e->getV1()->getInd() == v1->getInd() && e->getV2()->getInd() == v2->getInd()) {
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
    ENode *etmp;
    while (vtmp) {
        etmp = vtmp->eNode;
        while (etmp && etmp->next) {
            if (etmp->next->e == e) {
                delete etmp->next->e;
                delete etmp->next;
                etmp->next = nullptr;
                return true;
            }
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
void LGraph<DATA, NAME, WEIGHT>::print() {
    int i, j;
    VertexT *v;
    cout << "LIST" << endl;
    for (i = 0; i < size; i++) {
        v = vertexVector[i];
        cout << "*" << v->getName() << "->";
        for (j = 0; j < size; j++) {
            v = vertexVector[j];
            if (hasEdge(i, j))
                cout << v->getName() << "->";
        }
        cout << endl;
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
    while (vtmp) {
        if (vtmp->v_ind == v1->getInd()) {
            etmp = vtmp->eNode;
            res = new Edge<DATA, NAME, WEIGHT>(v1, v2);
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
//template<typename DATA, typename NAME, typename WEIGHT>
//LGraph<DATA, NAME, WEIGHT>::VNode *LGraph<DATA, NAME, WEIGHT>::findVertex() {
//    VNode *vtmp = list;
//    ENode *etmp = nullptr;
//    VNode *res = nullptr;
//    while (vtmp) {
//        etmp = vtmp->eNode;
//        while (etmp) {
//            if ()
//            etmp = etmp->next;
//        }
//        vtmp = vtmp->next;
//    }
//    return res;
//}

template
class LGraph<int, std::string, int>;