#include <iostream>
#include "SimpleGraph.h"

int main() {
    SimpleGraph<int, string, int> simpleGraph(5, 0, NonDGraphTyped, MGraphType);
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
    simpleGraph.printGraph();
    return 0;
}
