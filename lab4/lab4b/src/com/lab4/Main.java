package com.lab4;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
        double time, duration, totalTime = 0, maxTime = 0, minTime = 2000000000;
        int N = 100000; // number of cities
        int M = 100000; // number of flights
        Random rand = new Random();
        BFS bfs = new BFS(N, M);


        // generate minimum spanning tree
        for (int i = 1; i < N; i++) {
            // connect node i with random node from [0, i)
            int node = rand.nextInt(i);
            bfs.addEdge(i, node);
        }

        // generate M - (N - 1) more edges
        // allow multiple edge between 2 cities
        for (int i = 0; i < M - N + 1; i++) {
            int nodeA = 0;
            int nodeB = 0;
            while (nodeA == nodeB) {
                nodeA = rand.nextInt(N);
                nodeB = rand.nextInt(N);
            }
            bfs.addEdge(nodeA, nodeB);
        }

        // Run bfs for Q random queries and get the average
        int Q = 30;
        for (int i = 0; i < Q; i++) {
            // while loop to ensure the start and end is different
            int nodeA = 0;
            int nodeB = 0;
            while (nodeA == nodeB) {
                nodeA = rand.nextInt(N);
                nodeB = rand.nextInt(N);
            }
            // measure running time
            time = System.nanoTime();
            bfs.run(nodeA, nodeB, false);
            duration = System.nanoTime() - time;
            totalTime += duration;
            maxTime = Math.max(maxTime, duration);
            minTime = Math.min(minTime, duration);
            System.out.println("Iteration: " + i + ". duration: " + duration / 1000000);
        }
        System.out.println("total CPU time: " + totalTime/1000000 + " milliseconds");
        System.out.println("average CPU time: " + ((double)totalTime / 1000000 / Q) + " milliseconds\n");
        System.out.println("max CPU time: " + maxTime / 1000000 + " milliseconds");
        System.out.println("min CPU time: " + minTime / 1000000 + " milliseconds");
    }
}
