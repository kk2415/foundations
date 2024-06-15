import java.util.LinkedHashSet;
import java.util.Set;
import java.util.stream.IntStream;

public class Graph3 {

    public static void traversing(Set<Integer>[] graph, Integer v, boolean[] visitInfo) {
        System.out.println(v + " 방문 완료");
        visitInfo[v] = true;

        graph[v].stream()
                .filter(neighbor -> !visitInfo[neighbor])
                .forEach(neighbor -> traversing(graph, neighbor, visitInfo));
    }

    public static void addEdge(Set<Integer>[] graph, Integer from, Integer to) {
        graph[from].add(to);
        graph[to].add(from);
    }

    public static void main(String[] args) {
        Integer numVertex = 100;
        Set<Integer>[] graph = new Set[numVertex];
        IntStream.range(0, numVertex)
                .forEach(i -> graph[i] = new LinkedHashSet());

        addEdge(graph, 1, 2);
        addEdge(graph, 1, 5);
        addEdge(graph, 1, 8);
        addEdge(graph, 2, 3);
        addEdge(graph, 3, 4);
        addEdge(graph, 5, 6);
        addEdge(graph, 6, 7);
        addEdge(graph, 7, 11);
        addEdge(graph, 8, 9);
        addEdge(graph, 9, 10);
        addEdge(graph, 10, 12);

        boolean[] visitInfo = new boolean[numVertex];
        traversing(graph, 1, visitInfo);
    }
}
