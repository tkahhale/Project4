//
// Project by Jack Fenton, Jonathan Hsin, and Tamara Kahhale
// Northeastern University Department of Computer and Electrical Engineering
// EECE2560 Introduction to Engineering Algorithms
// Project begun on 2020-06-12.
//

#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <fstream>
#include <queue>
#include <iterator>
#include <algorithm>

#include "maze.h"

#include <boost/graph/adjacency_list.hpp>

#include "boostGraph.h"

using namespace boost;
using namespace std;


#define LargeValue 99999999

void clearVisited(Graph &g);
// Mark all nodes in g as not visited.

void setNodeWeights(Graph &g, int w);
// Set all node weights to w.

void clearMarked(Graph &g);


void relax(Graph &g, Graph::vertex_descriptor u, Graph::vertex_descriptor v)
{
	// get edge between u and v
	pair<Graph::edge_descriptor, bool> checkEdge = edge(u, v, g);
	
	// make sure the edge exists
	if (checkEdge.second != true) {
		cout << "The edge does not exist!" << endl;
	}
	
	// relax
	if (g[v].weight > g[u].weight + g[checkEdge.first].weight)
	{
		g[v].weight = g[u].weight + g[checkEdge.first].weight;
		g[v].pred = u;
	}
}

bool dijkstra(Graph &g, Graph::vertex_descriptor s)
{
	return true;
} // end of dijikstra


bool bellmanFord(Graph &g, Graph::vertex_descriptor s)
{
	return true;
} // end bellmanFord


int main()
{
	try
	{
		ifstream fin;
		
		// Read the maze from the file.
		string fileName = "yourpath/maze1.txt";
		
		fin.open(fileName.c_str());
		if (!fin)
		{
			cerr << "Cannot open " << fileName << endl;
			exit(1);
		}
		
		maze m(fin);
		fin.close();
		
		m.print(m.numRows()-1,m.numCols()-1,0,0);
		
		Graph g;
		m.mapMazeToGraph(g);
		
		cout << g << endl;
	}
}