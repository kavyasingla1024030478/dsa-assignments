#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class solution{

public:

int n;
int m;
  int adjMatrix[101][101];        // int matrix (fixed size)
  vector<int> adjList[101];       // adjacency list


solution(int x,int y)
{
    n=x;
    m=y;


  for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                adjMatrix[i][j] = 0;
}



void representusing_adjmatrix()
{ for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjMatrix[u][v] = 1;
            adjMatrix[v][u] = 1;   // remove for directed graph
        }



}

void representusing_adjlist()
{ for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }



}

  void printAdjMatrix()
  {
 cout << "\nAdjacency Matrix:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }



  }

 void printAdjlist()
  {
     cout << "\nAdjacency List:\n";
        for (int i = 1; i <= n; i++) {
            cout << i << " -> ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }

  }

    

    // degree of vertex (undirected)
    int degree(int v) {
        int deg = 0;
        for (int j = 1; j <= n; j++)
            if (adjMatrix[v][j] == 1)
                deg++;

        return deg;
    }

    // count edges
    int countEdges() {
        int edges = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (adjMatrix[i][j] == 1)
                    edges++;

        return edges;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    solution s(n, m);

    cout << "Enter edges for matrix:\n";
    s.representusing_adjmatrix();

    cout << "Enter edges for list:\n";
    s.representusing_adjlist();

    s.printAdjMatrix();
    s.printAdjlist();

    int v;
    cout << "\nEnter a vertex to find degree: ";
    cin >> v;
    cout << "Degree = " << s.degree(v) << endl;

    cout << "Total edges = " << s.countEdges() << endl;

    return 0;
}