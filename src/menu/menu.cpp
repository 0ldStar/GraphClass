//
// Created by loki on 22.10.22.
//
#include "menu.h"

extern SimpleGraph<int, string, int> *graph;

void printFillMenu() {
    int command = -1;
    int vCount, eCount;
    bool dir, den;
    Vertex<int, string> v1, v2;
    Edge<int, string, int> *e;
    int v1Ind, v2Ind;
    while (command != 6) {
        printf("What you want to do?\n"
               "1) Fill random value.\n"
               "2) Insert vertex.\n"
               "3) Delete vertex.\n"
               "4) Insert edge.\n"
               "5) Delete edge.\n"
               "6) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                if (graph) {
                    cout << "Graph already initialized\n";
                } else {
                    cout << "Enter vertex count: ";
                    cin >> vCount;
                    cout << "Enter edge count: ";
                    cin >> eCount;
                    cout << "Enter direction type (D - 1 / N - 0): ";
                    cin >> dir;
                    cout << "Enter dense type (M - 1 / L -0): ";
                    cin >> den;
                    graph = new SimpleGraph<int, string, int>(vCount, eCount, dir, den);
                }
                return;
            case 2:
                if (graph)
                    graph->insertV();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 3:
                if (graph) {
                    cout << "Enter vertex index: ";
                    cin >> v1Ind;
                    v1.setInd(v1Ind);
                    graph->deleteV(&v1);
                } else {
                    cout << "Graph is not initialize\n";
                }
                break;
            case 4:
                if (graph) {
                    cout << "Enter first vertex index: ";
                    cin >> v1Ind;
                    cout << "Enter second vertex index: ";
                    cin >> v2Ind;
                    v1.setInd(v1Ind);
                    v2.setInd(v2Ind);
                    graph->insertE(&v1, &v2);
                } else {
                    cout << "Graph is not initialize\n";
                }
                break;
            case 5:
                if (graph) {
                    cout << "Enter first vertex index: ";
                    cin >> v1Ind;
                    cout << "Enter second vertex index: ";
                    cin >> v2Ind;
                    v1.setInd(v1Ind);
                    v2.setInd(v2Ind);
                    e = new Edge<int, string, int>(&v1, &v2);
                    graph->deleteE(e);
                } else {
                    cout << "Graph is not initialize\n";
                }
                break;
            default:
                break;
        }
    }
}

void iteratorsMenu() {
    int command = -1;
    while (command != 4) {
        printf("What you want to do?\n"
               "1) Vertex iterator.\n"
               "2) Edge iterator.\n"
               "3) Input edge iterator.\n"
               "4) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                vertexIteratorMenu();
                return;
            case 2:
                edgeIteratorMenu();
                break;
            case 3:
                int v;
                cout << "Enter vertex index: ";
                cin >> v;
                if (!(v < 0 || v >= graph->getV()))
                    inputEdgeIteratorMenu(v);
                break;
            default:
                break;
        }
    }
}

void vertexIteratorMenu() {
    int command = -1;
    vector<Vertex<int, string> *> vertexVector;
    VertexIterator<int, string, int> iter = VertexIterator<int, string, int>(vertexVector, -1);
    VertexIterator<int, string, int> end = VertexIterator<int, string, int>(vertexVector, -1);

    while (command != 7) {
        printf("What you want to do?\n"
               "1) Set iterator to the start of the bTree.\n"
               "2) Set iterator to step by value.\n"
               "3) Increment iterator.\n"
               "4) Decrement iterator.\n"
               "5) Get element from iterator.\n"
               "6) Print keys.\n"
               "7) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                iter = graph->vBegin();
                break;
            case 2:
                unsigned step;
                std::cout << "Enter step: ";
                std::cin >> step;
                if (step > 0 && step < graph->getV()) {
                    iter = graph->vBegin();
                    for (unsigned i = 0; i < step; ++i) iter++;
                } else {
                    std::cout << "[Error] Invalid step" << std::endl;
                }
                break;
            case 3:
                if (iter != end) {
                    iter++;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 4:
                if (iter != end) {
                    iter--;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 5:
                if (iter != end) {
                    std::cout << "Value: " << *iter << std::endl;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 6:
                for (auto it = graph->vBegin(); it != graph->vEnd(); it++) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                break;
            default:
                break;
        }
    }
}

void edgeIteratorMenu() {
    int command = -1;
    EdgeIterator<int, string, int> iter = EdgeIterator<int, string, int>(nullptr, -1);
    EdgeIterator<int, string, int> end = EdgeIterator<int, string, int>(nullptr, -1);

    while (command != 7) {
        printf("What you want to do?\n"
               "1) Set iterator to the start of the graph.\n"
               "2) Set iterator to step by value.\n"
               "3) Increment iterator.\n"
               "4) Decrement iterator.\n"
               "5) Get element from iterator.\n"
               "6) Print keys.\n"
               "7) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                iter = graph->eBegin();
                break;
            case 2:
                unsigned step;
                std::cout << "Enter step: ";
                std::cin >> step;
                if (step > 0 && step < graph->getV()) {
                    iter = graph->eBegin();
                    for (unsigned i = 0; i < step; ++i) iter++;
                } else {
                    std::cout << "[Error] Invalid step" << std::endl;
                }
                break;
            case 3:
                if (iter != end) {
                    iter++;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 4:
                if (iter != end) {
                    iter--;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 5:
                if (iter != end) {
                    std::cout << "Value: " << *iter << std::endl;
                    std::cout << "Ind: " << iter.getInd() << std::endl;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 6:
                for (auto it = graph->eBegin(); it != graph->eEnd(); it++) {
                    std::cout << *it << " ";
                }
                std::cout << std::endl;
                break;
            default:
                break;
        }
    }
}

void inputEdgeIteratorMenu(int v) {
    int command = -1;
    EdgeIterator<int, string, int> iter = EdgeIterator<int, string, int>(nullptr, -1);
    EdgeIterator<int, string, int> end = EdgeIterator<int, string, int>(nullptr, -1);

    while (command != 7) {
        printf("What you want to do?\n"
               "1) Set iterator to the start of the graph.\n"
               "2) Set iterator to step by value.\n"
               "3) Increment iterator.\n"
               "4) Decrement iterator.\n"
               "5) Get element from iterator.\n"
               "6) Print keys.\n"
               "7) Back to main menu.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                iter = graph->adjEBegin(v);
                break;
            case 2:
                unsigned step;
                std::cout << "Enter step: ";
                std::cin >> step;
                if (step > 0 && step < graph->getV()) {
                    iter = graph->adjEBegin(v);
                    for (unsigned i = 0; i < step; ++i) iter++;
                } else {
                    std::cout << "[Error] Invalid step" << std::endl;
                }
                break;
            case 3:
                if (iter != end) {
                    iter++;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 4:
                if (iter != end) {
                    iter--;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 5:
                if (iter != end) {
                    std::cout << "Value: " << (*iter)->getData() << std::endl;
                } else {
                    std::cout << "[Error] Bad iterator" << std::endl;
                }
                break;
            case 6:
                for (auto it = graph->adjEBegin(v); it != graph->adjEEnd(v); it++) {
                    std::cout << (*it)->getData() << " ";
                }
                std::cout << std::endl;
                break;
            default:
                break;
        }
    }
}

void task2Menu() {
    Task2<int, string, int> task2(graph);
    cout << "Task 2. Check is graph bipartite and color them" << endl;
    cout << "Graph is bipartite ? " << (task2.bipartite() ? "True" : "False") << endl;
    if (task2.bipartite()) {
        auto vc = task2.result();
        for (int i = 0; i < graph->getV(); ++i) {
            cout << vc[i] << " ";
        }
        cout << endl;
    }
}

void task3Menu() {
    Task3<int, string, int> task3(graph);
    cout << "Task 3. Get diameter of the graph and print path" << endl;
    cout << "Result " << task3.result() << endl;
    cout << "Path: " << task3.getPath();
}
