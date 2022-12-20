
#include "menu/menu.h"

SimpleGraph<int, string, int> *graph = nullptr;
using namespace std;

int main() {
    system("clear");
    int command = -1;
    while (command != 13) {
        printf("\tThis is interactive menu for Graph structure.\n"
               "What you want to do?\n"
               "1) Fill the graph.\n"
               "2) Get vertex count.\n"
               "3) Get edge count.\n"
               "4) Get graph direction type.\n"
               "5) Get graph form type.\n"
               "6) Get saturation factor.\n"
               "7) Transform graph to Matrix graph.\n"
               "8) Transform graph to List graph.\n"
               "9) Print the graph\n"
               "10) Iterators menu\n"
               "11) Check bipartite\n"
               "12) Get diameter\n"
               "13) Exit.\n"
               ":");
        if (scanf("%d", &command) != 1) {
            while (getchar() != '\n') {}
        }
        system("clear");
        switch (command) {
            case 1:
                printFillMenu();
                break;
            case 2:
                if (graph)
                    cout << "Vertex count = " << graph->getV() << endl;
                else
                    cout << "Graph is not initialize\n";
                break;
            case 3:
                if (graph)
                    cout << "Edge count = " << graph->getE() << endl;
                else
                    cout << "Graph is not initialize\n";
                break;
            case 4:
                if (graph)
                    cout << (graph->isDirected() ? "Directed" : "Non directed") << " graph." << endl;
                else
                    cout << "Graph is not initialize\n";
                break;
            case 5:
                if (graph)
                    cout << (graph->isDense() ? "Matrix" : "List") << " graph." << endl;
                else
                    cout << "Graph is not initialize\n";
                break;
            case 6:
                if (graph)
                    cout << "Saturation factor = " << graph->getK() << endl;
                else
                    cout << "Graph is not initialize\n";
                break;
            case 7:
                if (graph)
                    graph->toMatrixGraph();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 8:
                if (graph)
                    graph->toListGraph();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 9:
                if (graph)
                    graph->printGraph();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 10:
                if (graph)
                    iteratorsMenu();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 11:
                if (graph)
                    task2Menu();
                else
                    cout << "Graph is not initialize\n";
                break;
            case 12:
                if (graph)
                    task3Menu();
                else
                    cout << "Graph is not initialize\n";
                break;
            default:
                break;
        }
    }
    return 0;
}
