#include<iostream>
#include<ctime>
#include "UnitTests.h"


int main()
{
    // test UnitTests
    UnitTests test;
    test.test();


    Graph graph(8);
    graph.addEdge(1, 2, 7);
    graph.addEdge(1, 6, 14);
    graph.addEdge(1, 3, 9);
    graph.addEdge(2, 3, 10);
    graph.addEdge(2, 4, 15);
    graph.addEdge(3, 6, 2);
    graph.addEdge(4, 3, 11);
    graph.addEdge(4, 5, 6);
    graph.addEdge(5, 6, 9);
    graph.print();

    vector<int> way;
    Dijkstra algorithm(graph);
    cout << endl << algorithm.findWay(1, 6, way) << endl;
    for (auto it = way.rbegin(); it != way.rend(); it++) cout << *it << "  ";
    system("pause");
    return 0;
}
