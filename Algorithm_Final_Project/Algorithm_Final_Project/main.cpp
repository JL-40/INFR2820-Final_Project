// Algorithm_Final_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>

#include "Graph.cpp"
#include "FileHandler.h"

int main()
{
	FileReader readFile;
	readFile.readGraphData("GraphData.txt");
	readFile.nodeStorage.OutputGraphData();
}

void NodeStorage::OutputGraphData()
{
	Graph graph;

	for (NodeData point : nodes)
	{
		graph.AddEdge(point.origin, point.neighbour, point.distance);
	}

	graph.Display();

	char start;
	std::cout << "Choose a starting point: ";

	std::cin >> start;

	graph.Dijkstra(start); // A -> B -> C -> H. Total Distance: 16
}