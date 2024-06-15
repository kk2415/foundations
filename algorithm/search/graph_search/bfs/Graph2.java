package test.example.graph.bfs;

import java.util.*;

public class Graph2 {

    private TreeMap<Integer, Set<Vertex>> graph = new TreeMap<>();

    public void traversing(Vertex start) {
        TreeMap<Integer, Boolean> visitInfo = new TreeMap<>();
        graph.keySet().forEach(id -> visitInfo.put(id, false));

        Queue<Vertex> adjacentVertex = new LinkedList<>();
        adjacentVertex.add(start);

        while (!adjacentVertex.isEmpty()) {
            Vertex v = adjacentVertex.poll();
            System.out.println(v.id + " 방문 완료");
            visitInfo.put(v.id, true);

            graph.get(v.id).stream()
                    .filter(n -> !visitInfo.get(n.id))
                    .forEach(adjacentVertex::add);
        }
    }

    public void addEdge(Vertex from, Vertex to) {
        graph.computeIfAbsent(from.id, key -> new LinkedHashSet<>()).add(to);
        graph.computeIfAbsent(to.id, key -> new LinkedHashSet<>()).add(from);
    }

    public static class Vertex {
        Integer id;

        public Vertex(Integer id) {
            this.id = id;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vertex vertex = (Vertex) o;
            return Objects.equals(id, vertex.id);
        }

        @Override
        public int hashCode() {
            return Objects.hash(id);
        }
    }
}
