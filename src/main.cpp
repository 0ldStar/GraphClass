#include <iostream>
#include "SimpleGraph.h"

int main() {
    SimpleGraph<int, string, int> simpleGraph(5, 0, NonDGraphType, LGraphType);
    Vertex<int, string> v1("1", 1);
    Vertex<int, string> v2("2", 2);
    Vertex<int, string> v3("3", 3);
    Vertex<int, string> v4("4", 4);
    v1.setInd(0);
    v2.setInd(1);
    simpleGraph.insertE(&v1, &v2);
    v3.setInd(3);
    v4.setInd(4);
    simpleGraph.insertE(&v3, &v4);
    simpleGraph.insertE(&v1, &v4);
    simpleGraph.printGraph();
//    Edge<int, string ,int> e1(&v1, &v2);
//    Edge<int, string ,int> e2(&v3, &v4);
//    simpleGraph.deleteE(&e1);
//    simpleGraph.deleteE(&e2);
    simpleGraph.printGraph();
    for (auto it = simpleGraph.vBegin(); it != simpleGraph.vEnd(); it++){
        cout << *it;
    }
    cout << endl;
    for (auto it = simpleGraph.eBegin(); it != simpleGraph.eEnd(); it++){
        cout << (*it)->getW() << " ";
    }
    cout << endl;
    for (auto it = simpleGraph.adjEBegin(&v3); it != simpleGraph.adjEEnd(&v3); it++){
        cout << (*it)->getW() << " ";
    }
    return 0;
}
