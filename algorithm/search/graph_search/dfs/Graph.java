import java.util.LinkedHashSet;
import java.util.Objects;
import java.util.Set;
import java.util.Stack;
import java.util.stream.Collectors;

public class Graph {

    private final Integer numberVertex;
    private Integer numberEdge;
    private final Set<Vertex>[] adjList;
    private boolean[] visitInfo;

    public Graph(Integer numberVertex) {
        this.numberVertex = numberVertex;
        this.numberEdge = 0;

        this.adjList = new Set[numberVertex];
        this.visitInfo = new boolean[numberVertex];
        for (int i = 0; i < numberVertex; i++) {
            adjList[i] = new LinkedHashSet<>();
            this.visitInfo[i] = false;
        }
    }

    public void traversing(Integer start) {
        Stack<Vertex> adjacentVertex = new Stack<>();
        adjacentVertex.push(new Vertex(start));

        while (!adjacentVertex.isEmpty()) {
            Vertex v = adjacentVertex.pop();
            if (!visitInfo[v.name()]) {
                visitInfo[v.name()] = true;
                System.out.println(v.name() + "방문 완료");

                adjacentVertices(v).stream()
                        .filter(neighbor -> !visitInfo[neighbor.name()])
                        .forEach(adjacentVertex::push);
            }
        }
    }

    public void addEdge(Integer from, Integer to) {
        adjList[from].add(new Vertex(to));
        adjList[to].add(new Vertex(from));

        numberEdge++;
    }

    public Set<Vertex> adjacentVertices(Vertex vertex) {
        return adjList[vertex.name()].stream()
                .map(v -> new Vertex(v.name()))
                .collect(Collectors.toSet());
    }

    public void showEdgeInfo() {
        for (int i = 0; i < numberVertex; i++) {
            System.out.print(i + "과(와) 연결된 정점: ");
            adjList[i].forEach(v -> System.out.print(v.name + " "));
            System.out.println();
        }
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