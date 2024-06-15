package test.example.graph.bfs;

import java.util.*;

public class Graph1 {

    private TreeMap<Integer, Set<Integer>> graph = new TreeMap<>();

    public void traversing(Integer start) {
        boolean[] visitInfo = new boolean[1000];
        Queue<Integer> adjacentVertex = new LinkedList<>();
        adjacentVertex.add(start);

        while (!adjacentVertex.isEmpty()) {
            Integer v = adjacentVertex.poll();
            System.out.println(v + " 방문 완료");
            visitInfo[v] = true; //labeling as discovered

            graph.get(v).stream()
                    .filter(n -> !visitInfo[n])
                    .forEach(adjacentVertex::add);
        }
    }

    public void addEdge(Integer from, Integer to) {
        graph.computeIfAbsent(from, key -> new LinkedHashSet<>()).add(to);
        graph.computeIfAbsent(to, key -> new LinkedHashSet<>()).add(from);
    }
}
