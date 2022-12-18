#include <iostream>
#include "SimpleGraph.h"

int main() {
    SimpleGraph<int, string, int> simpleGraph(5, 4, NonDGraphTyped, MGraphType);
    simpleGraph.printGraph();
    return 0;
}
