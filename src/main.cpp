#include <iostream>
#include "SimpleGraph.h"
#include "Task2.h"
#include "Task3.h"

int main() {
    SimpleGraph<int, string, int> simpleGraph(4, 10, NonDGraphType, MGraphType);
    Vertex<int, string> v1("1", 1);
    Vertex<int, string> v2("2", 2);
    Vertex<int, string> v3("3", 3);
    Vertex<int, string> v4("4", 4);
    v1.setInd(0);
    v2.setInd(1);
    v3.setInd(2);
    v4.setInd(3);

    simpleGraph.printGraph();
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
    simpleGraph.toListGraph();
    simpleGraph.printGraph();
    simpleGraph.toMatrixGraph();
    simpleGraph.printGraph();

    SimpleGraph<int, string, int> bipartite(8, 8, NonDGraphType, MGraphType);
    bipartite.printGraph();
    Task2<int, string, int> task2(&bipartite);
    cout << task2.bipartite() << endl;
    auto vc = task2.result();
    for (int i = 0; i < bipartite.getV(); ++i) {
        cout << vc[i] << " ";
    }
    cout << endl;
    Task3<int, string, int> task3(&bipartite);
    cout << "Result " << task3.result() << endl;
    cout << task3.getPath();
    return 0;
}
