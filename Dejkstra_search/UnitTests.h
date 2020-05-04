//
// Created by Sophia Shuvar on 04.05.20.
//

#ifndef DEJKSTRA_SEARCH_UNITTESTS_H
#define DEJKSTRA_SEARCH_UNITTESTS_H

#endif //DEJKSTRA_SEARCH_UNITTESTS_H
#include <cassert>
#include <assert.h>
#include <string>
#include "Dejkstra.h"

using namespace std;

class UnitTests{
public:

    void test(){
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
        vector<int> way;
        vector<int> way_chack = {6, 3, 1};
        Dejkstra algorithm(graph);
        int k = algorithm.findWay(1, 6, way);
        assert(k == 11);
        assert(way == way_chack);
    }
};