
 
#include <bits/stdc++.h> 

using namespace std; 

const static int MAXNUMVERTICES = 100;  
int disjointSet[10];
  
// locate set of vertex i 
int locate(int i) 
{ 
    while (disjointSet[i] != i) 
        i = disjointSet[i];
    //std::cout << "eh";
    return i; 
} 
  
// Does union of i and j. It returns 
// false if i and j are already in same 
// set. 
void unionGraph(int i, int j) 
{ 
    int a = locate(i); 
    int b = locate(j); 
    disjointSet[a] = b; 
} 
  
// locates MST using Kruskal's algorithm 
int kruskal(int theGraph[][MAXNUMVERTICES], int V) 
{ 
    int minSpan = 0; // theGraph of min MST. 
  
    // Initialize sets of disjoint sets. 
    for (int i = 0; i < V; i++) 
        disjointSet[i] = i; 
  
    // Include minimum weight edges one by one 
    int edgecount = 0; 
    while (edgecount < V - 1) { 
        int min = INT_MAX, a = -1, b = -1; 
        for (int i = 0; i < V; i++) { 
            for (int j = 0; j < V; j++) { 
                if (locate(i) != locate(j) && theGraph[i][j] < min) { 
                    min = theGraph[i][j]; 
                    a = i; 
                    b = j; 
                } 
                //std::cout << "eh";
            } 
        } 
  
        unionGraph(a, b); 
         
        edgecount++; 
        minSpan += min; 
    } 
    return minSpan; 
} 

void printGraph(int numVertices, int theGraph[][MAXNUMVERTICES]){
        for (int i = 0; i < numVertices; i++){
                for (int j = 0; j < numVertices; j++){
                    std::cout << theGraph[i][j] << ", ";
                }
            std::cout << std::endl;
        }
    }
  
// driver program to test above function 
int main() 
{ 

  int theGraph[MAXNUMVERTICES][MAXNUMVERTICES];
  for (int i = 0; i < MAXNUMVERTICES; i++){
    for (int j = 0; j < MAXNUMVERTICES; j++){
      theGraph[i][j] = INT_MAX;
    }
  }
  int numEdges, inVert, outVert, wt;
    std::cin >> numEdges;
    int numVertices = -1;
    for (int i=0; i<numEdges; i++)
    {
        std::cin >> inVert;
        std::cin >> outVert;
        std::cin >> wt;
        if( inVert > numVertices)
            numVertices = inVert;
        if( outVert > numVertices)
            numVertices = outVert;
        theGraph[inVert-1][outVert-1] = wt;
    }
    // Print the solution 
    //int disjointSet[numVertices]; 
    //printGraph(numVertices, theGraph);
    std::cout << kruskal(theGraph, numVertices); 
    //std::cout << "eh";
    return 0; 
} 




/*    My_Graph *theGraph = new My_Graph();
    theGraph->initializeGraph();
    int numEdges, inVert, outVert, wt;
    std::cin >> numEdges;
    int numVertices = -1;
    for (int i=0; i<numEdges; i++)
    {
        std::cin >> inVert;
        std::cin >> outVert;
        std::cin >> wt;
        if( inVert > numVertices)
            numVertices = inVert;
        if( outVert > numVertices)
            numVertices = outVert;
        theGraph->insertEdge(inVert, outVert, wt);
    }
    theGraph->setVertices(numVertices);
    //std::cout << std::endl;
    //theGraph->printGraph();
    std::cout << std::endl;
    std::cout<<theGraph->sumOfMST();
    */