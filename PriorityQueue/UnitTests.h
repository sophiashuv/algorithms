//
// Created by Sophia Shuvar on 08.04.20.
//

#ifndef PRIORITYQUEUE_UNITTESTS_H
#define PRIORITYQUEUE_UNITTESTS_H

#endif //PRIORITYQUEUE_UNITTESTS_H
#include "PriorityQueue.h"
#include <cassert>
#include <assert.h>


class UnitTests {
public:
    void testQueueInsert() {
        PriorityQueue<int> pq;
        pq.insert(1, 1);
        pq.insert(2, 3);
        pq.insert(3, 1);
        assert(pq.toString() == "1 3 2 \n");
    }

    void testQueuePop() {
        PriorityQueue<int> pq;
        pq.insert(1, 1);
        pq.insert(2, 3);
        pq.insert(3, 1);
        pq.pop();
        assert(pq.toString() == "3 2 \n");
    }

    void testQueueTop() {
        PriorityQueue<char> pq;
        pq.insert('a', 1);
        pq.insert('b', 3);
        pq.insert('c', 1);
        assert(pq.top() == 'a');
    }

    void testQueueEmpty1() {
        PriorityQueue<char> pq;
        assert(pq.isEmpty());
    }

    void testQueueEmpty2() {
        PriorityQueue<char> pq;
        pq.insert('a', 1);
        pq.insert('b', 3);
        pq.insert('c', 1);
        assert(!pq.isEmpty());
    }

    void testQueueClear() {
        PriorityQueue<char> pq;
        pq.insert('a', 1);
        pq.insert('b', 3);
        pq.insert('c', 1);
        pq.clear();
        assert(pq.isEmpty());
    }

    void testQueueSize() {
        PriorityQueue<char> pq;
        pq.insert('a', 1);
        pq.insert('b', 3);
        pq.insert('c', 1);
        assert(pq.Size() == 3);
    }
};
