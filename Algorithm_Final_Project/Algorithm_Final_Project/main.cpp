// Algorithm_Final_Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>

#include "Graph.cpp"

int main()
{
	Graph graph;

	// A neighbors
	graph.AddEdge('A', 'B', 6);
	graph.AddEdge('A', 'F', 5);
	
	// B neighbors
	graph.AddEdge('B', 'C', 5);
	graph.AddEdge('B', 'G', 6);

	// C neighbors
	graph.AddEdge('C', 'D', 7);
	graph.AddEdge('C', 'h', 5); // Charging Station

	// D neighbors
	graph.AddEdge('D', 'E', 7);
	graph.AddEdge('D', 'I', 8);
	 
	// E neighbors
	graph.AddEdge('E', 'I', 6);
	graph.AddEdge('E', 'N', 15);
	 
	// F neighbors
	graph.AddEdge('F', 'G', 8);
	graph.AddEdge('F', 'J', 7);
	 
	// G neighbors
	graph.AddEdge('G', 'h', 9); // Charging Station
	graph.AddEdge('G', 'k', 8); // Charging Station
	 
	// H neighbors - Charging Station
	graph.AddEdge('h', 'I', 12);
	 
	// I neighbors
	graph.AddEdge('I', 'M', 10);
	 
	// J neighbors
	graph.AddEdge('J', 'k', 5); // Charging Station
	graph.AddEdge('J', 'O', 7);
	 
	// K neighbors - Charging Station
	graph.AddEdge('k', 'L', 7);
	 
	// L neighbors
	graph.AddEdge('L', 'M', 7);
	graph.AddEdge('L', 'P', 7);
	 
	// M neighbors
	graph.AddEdge('M', 'N', 9);
	 
	// N neighbors
	graph.AddEdge('N', 'R', 7);
	 
	// O neighbors
	graph.AddEdge('O', 'P', 13);
	graph.AddEdge('O', 'S', 9);
	 
	// P neighbors
	graph.AddEdge('P', 'q', 8); // Charging Station
	graph.AddEdge('P', 'U', 11);
	 
	// Q neighbors - Charging Station
	graph.AddEdge('q', 'R', 9);
	 
	// R neighbors
	graph.AddEdge('R', 'W', 10);
	 
	// S neighbors
	graph.AddEdge('S', 't', 9); // Charging Station
	 
	// T neighbors - Charging Station
	graph.AddEdge('t', 'U', 8);
	 
	// U neighbors
	graph.AddEdge('U', 'V', 8);
	 
	// V neighbors
	graph.AddEdge('V', 'W', 5);

	graph.Display();

	
	char start;
	std::cout << "Choose a starting point: ";

	std::cin >> start;

	graph.Dijkstra(start); // A -> B -> C -> H. Total Distance: 16
}
