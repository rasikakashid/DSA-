#include <stdio.h> #include <stdlib.h>

#define MAX_VERTICES 50


void addEdge(int graph[MAX_VERTICES][MAX_VERTICES], int start, int end) { graph[start][end] = 1;
graph[end][start] = 1; // Undirected graph
}


void BFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
int visited[MAX_VERTICES] = {0}; int queue[MAX_VERTICES];
int front = 0, rear = 0;


visited[startVertex] = 1; queue[rear++] = startVertex;

printf("BFS Traversal: ");


while (front < rear) {
int currentVertex = queue[front++]; printf("%d ", currentVertex);

for (int i = 0; i < vertices; i++) {
if (graph[currentVertex][i] == 1 && !visited[i]) { queue[rear++] = i;
 
visited[i] = 1;
}
}
}
printf("\n");
}


void DFS(int graph[MAX_VERTICES][MAX_VERTICES], int vertices, int visited[], int currentVertex) {
visited[currentVertex] = 1; printf("%d ", currentVertex);

for (int i = 0; i < vertices; i++) {
if (graph[currentVertex][i] == 1 && !visited[i]) { DFS(graph, vertices, visited, i);
}
}
}


int main() {
int vertices, edges;
printf("Enter number of vertices: "); scanf("%d", &vertices);

if (vertices <= 0 || vertices > MAX_VERTICES) { printf("Invalid number of vertices!\n");
return 1;
}


int graph[MAX_VERTICES][MAX_VERTICES] = {0};
printf("Enter number of edges: ");
 
scanf("%d", &edges);


if (edges < 0 || edges > vertices * (vertices - 1) / 2) { printf("Invalid number of edges!\n");
return 1;
}


printf("Enter edges (source destination):\n"); for (int i = 0; i < edges; i++) {
int src, dest;
scanf("%d %d", &src, &dest);


if (src < 0 || src >= vertices || dest < 0 || dest >= vertices) { printf("Invalid vertex entered\n");
i--;
continue;
}


addEdge(graph, src, dest);
}


printf("\nAdjacency Matrix:\n"); for (int i = 0; i < vertices; i++) {
for (int j = 0; j < vertices; j++) { printf("%d ", graph[i][j]);
}
printf("\n");
}


int startVertex;
printf("\nEnter starting vertex for traversal: ");
 
scanf("%d", &startVertex);


if (startVertex < 0 || startVertex >= vertices) { printf("Invalid Starting Vertex\n");
return 1;
}


BFS(graph, vertices, startVertex);


int visitedDFS[MAX_VERTICES] = {0}; printf("DFS Traversal: ");
DFS(graph, vertices, visitedDFS, startVertex); printf("\n");

return 0;
}
