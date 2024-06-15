import java.util.LinkedHashSet;
import java.util.Set;
import java.util.Stack;

public class Graph2 {

    private final Set<Integer>[] adjList;

    public Graph2(Integer numberVertex) {
        this.adjList = new Set[numberVertex];
        for (int i = 0; i < numberVertex; i++) {
            adjList[i] = new LinkedHashSet<>();
        }
    }

    public void traversing(Integer start) {
        boolean[] visitInfo = new boolean[adjList.length];
        Stack<Integer> adjacentVertex = new Stack<>();
        adjacentVertex.push(start);

        while (!adjacentVertex.isEmpty()) {
            Integer v = adjacentVertex.pop();
            if (!visitInfo[v]) {
                visitInfo[v] = true;
                System.out.println(v + "방문 완료");

                adjacentVertices(v).stream()
                        .filter(neighbor -> !visitInfo[neighbor])
                        .forEach(adjacentVertex::push);
            }
        }
    }

    public void traversing(Integer v, boolean[] visitInfo) {
        System.out.println(v + " 방문 완료");
        visitInfo[v] = true;

        adjacentVertices(v).stream()
                .filter(neighbor -> !visitInfo[neighbor])
                .forEach(neighbor -> traversing(neighbor, visitInfo));
    }

    public void addEdge(Integer from, Integer to) {
        adjList[from].add(to);
        adjList[to].add(from);
    }

    public Set<Integer> adjacentVertices(Integer vertex) {
        return adjList[vertex];
    }
}
