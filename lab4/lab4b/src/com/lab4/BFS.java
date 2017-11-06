package com.lab4;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

class BFS {
    private ArrayList<List<Integer>> adjList;
    private List<Integer> visited;
    int N, M;

    BFS(int N, int M) {
        // initialize
        this.N = N;
        this.M = M;
        adjList = new ArrayList<List<Integer>>(N + 5);
        for (int i = 0; i < N + 5; i++) {
            adjList.add(new ArrayList<Integer>());
        }
        visited = new ArrayList<Integer>(N + 5);
        for (int i = 0; i < N + 5; i++) {
            visited.add(-1);
        }
    }

    void addEdge(int a, int b) {
        adjList.get(a).add(b);
        adjList.get(b).add(a);
    }

    void run(int start, int end, boolean printOutput) {
        for (int i = 0; i < N; i++) visited.set(i, -1);

        LinkedList<Integer> qu = new LinkedList<Integer>();
        qu.add(start);
        visited.set(start, 0);

        int idxNow = 0;
        int idxBack = 1;
        int nodeNow = 0;

        while (idxNow < idxBack) {
            nodeNow = qu.get(idxNow);
            if (nodeNow == end) break;
            for (int i = 0; i < adjList.get(nodeNow).size(); i++) {
                if (visited.get(adjList.get(nodeNow).get(i)) == -1) {
                    visited.set(adjList.get(nodeNow).get(i), nodeNow);
                    qu.add(adjList.get(nodeNow).get(i));
                    idxBack++;
                }
            }
            idxNow++;
        }
        if (printOutput) {
            ArrayList<Integer> answer = new ArrayList<Integer>();
            answer.add(nodeNow);
            while (visited.get(nodeNow) != 0) {
                nodeNow = visited.get(nodeNow);
                answer.add(nodeNow);
            }
            Collections.reverse(answer);
            for (int i = 0; i < answer.size(); i++) {
                if (i > 0) System.out.printf(" ");
                System.out.printf("%d", answer.get(i));
            }
            System.out.println();
        }
    }
}
