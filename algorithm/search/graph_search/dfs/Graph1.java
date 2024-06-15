import java.util.LinkedHashSet;
import java.util.Objects;
import java.util.Set;
import java.util.Stack;
import java.util.stream.Collectors;

public class Graph1 {

    private final Set<Vertex>[] adjList;

    public Graph1(Integer numberVertex) {
        this.adjList = new Set[numberVertex];

        for (int i = 0; i < numberVertex; i++) {
            adjList[i] = new LinkedHashSet<>();
        }
    }

    public void traversing(Integer start) {
        boolean[] visitInfo = new boolean[adjList.length];
        Stack<Vertex> adjacentVertex = new Stack<>();
        adjacentVertex.push(new Vertex(start));

        while (!adjacentVertex.isEmpty()) {
            Vertex v = adjacentVertex.pop();
            if (!visitInfo[v.name()]) {
                visitInfo[v.name()] = true;
                System.out.println(v.name() + " 방문 완료");

                adjacentVertices(v).stream()
                        .filter(neighbor -> !visitInfo[neighbor.name()])
                        .forEach(adjacentVertex::push);
            }
        }
    }

    public void recur_traversing(Integer v, boolean[] visitInfo) {
        System.out.println(v + " 방문 완료");
        visitInfo[v] = true;

        adjacentVertices(new Vertex(v)).stream()
                .filter(neighbor -> !visitInfo[neighbor.name()])
                .forEach(neighbor -> recur_traversing(neighbor.name(), visitInfo));
    }

    public void addEdge(Integer from, Integer to) {
        adjList[from].add(new Vertex(to));
        adjList[to].add(new Vertex(from));
    }

    public Set<Vertex> adjacentVertices(Vertex vertex) {
        return adjList[vertex.name()].stream()
                .map(v -> new Vertex(v.name()))
                .collect(Collectors.toSet());
    }

    private class Vertex {
        private Integer name;

        public  Vertex(Integer name) {
            this.name = name;
        }

        public Integer name() {
            return name;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Vertex edge = (Vertex) o;
            return Objects.equals(name, edge.name);
        }

        @Override
        public int hashCode() {
            return Objects.hash(name);
        }
    }
}