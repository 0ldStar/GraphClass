#include <iostream>
#include "SimpleGraph.h"
#include "Task2.h"

int main() {
    SimpleGraph<int, string, int> simpleGraph(4, 10, NonDGraphType, MGraphType);
    Vertex<int, string> v1("1", 1);
    Vertex<int, string> v2("2", 2);
    Vertex<int, string> v3("3", 3);
    Vertex<int, string> v4("4", 4);
    v1.setInd(0);
    v2.setInd(1);
//    simpleGraph.insertE(&v1, &v2);
    v3.setInd(2);
    v4.setInd(3);
//    simpleGraph.insertE(&v3, &v4);
//    simpleGraph.insertE(&v1, &v4);
//    simpleGraph.printGraph();

//    Edge<int, string ,int> e1(&v1, &v2);
//    Edge<int, string ,int> e2(&v3, &v4);
//    simpleGraph.deleteE(&e1);
//    simpleGraph.deleteE(&e2);
    simpleGraph.printGraph();
    simpleGraph.deleteV(&v1);
    simpleGraph.deleteV(&v2);
    simpleGraph.deleteV(&v3);
    simpleGraph.deleteV(&v4);
    simpleGraph.insertV();
    simpleGraph.insertV();
    simpleGraph.insertV();
    simpleGraph.insertV();
    simpleGraph.insertV();
    simpleGraph.insertV();
    simpleGraph.printGraph();
    cout << endl;
    for (auto it = simpleGraph.vBegin(); it != simpleGraph.vEnd(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    for (auto it = simpleGraph.eBegin(); it != simpleGraph.eEnd(); it++) {
        cout << (*it)->getData() << " ";
    }
    cout << endl;
    auto it = simpleGraph.adjEBegin(3);
    if (it.getSize() > 0)
        for (; it != simpleGraph.adjEEnd(3); it++) {
            cout << (*it)->getData() << " ";
        }
    cout << endl;

//    SimpleGraph<int, string, int> bipartile(8, 5, NonDGraphType, MGraphType);
//    bipartile.printGraph();
//    Task2<int, string ,int> task2(&bipartile);
//    cout << task2.bipartite() << endl;
//    for (int i = 0; i < bipartile.getV(); ++i) {
//        cout << task2.color(i) << " ";
//    }
//    cout << endl;
    return 0;
}
