#include <iostream>
#include <stack>

using namespace std;
 
// Based on Lecture
void DFS(int u, int A[][8], int n){
    static int visited[8] {0};
 
    if (visited[u] == 0){
        cout << u << ", " << flush;
        visited[u] = 1;
        for (int v=1; v<n; v++){
            if (A[u][v] == 1 && visited[v] == 0){
                DFS(v, A, n);
            }
        }
    }
}
  
int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    int u = 5;
    cout << "DFS Vertex: " << u << " -> " << flush;
    DFS(u, A, 8);
    cout << endl;

 
    return 0;
}