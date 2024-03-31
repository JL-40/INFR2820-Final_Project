#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
#include <limits>


using namespace std;

class Graph
{
private:
#pragma region PRIVATE_DATA_MEMBER
	unordered_map<char, vector<pair<char, int>>> adjacencyList;
#pragma endregion

public:
#pragma region PUBLIC_FUNCTION
	Graph() : adjacencyList() {} // Default constructor to safe state

	const unordered_map<char, vector<pair<char, int>>>& GetAdjacencyList() const { return adjacencyList; } // Getter

	vector<pair<char, int>> at(const char index)
	{
		return adjacencyList.at(index);
	}

	
	// Add connections between two nodes, If the node does not exists, it will create it then add its neighbor.
	void AddEdge(const char& start, const char& destination, const int& edgeWeight)
	{
		// Inserts or updates node's neighbor list
		adjacencyList[start].push_back(make_pair(destination, edgeWeight));
		adjacencyList[destination].push_back(make_pair(start, edgeWeight));
	}

	void Display() const
	{
		for (const pair<char, vector<pair<char, int>>>& vertex : adjacencyList)
		{
			cout << "Vertex '" << (char)toupper(vertex.first) << "' connects to: [";

			string neighbors = "";
			for (const pair<char, int>& neighbor : vertex.second)
			{
				neighbors += (char)toupper(neighbor.first);

				neighbors += "(" + to_string(neighbor.second) + ")";

				neighbors += ", ";
			}

			neighbors.erase(neighbors.size() - 2);

			cout << neighbors << "]" << endl;
		}
	}

	// Used Dijkstra's Algorithm to find the shortest path to every node in the graph
	void Dijkstra (const char& start) const
	{
		unordered_map<char, int> shortestPaths;
		unordered_map<char, char> route;
		priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> visited;
		
		// Set all paths to each node
		for (const pair<char, vector<pair<char, int>>>& vertexPair : adjacencyList) 
		{
			shortestPaths[vertexPair.first] = numeric_limits<int>::max();
			route[vertexPair.first] = '\0'; // Empty route
		}

		// Sets the start distance to 0 
		shortestPaths[start] = 0;
		visited.push(make_pair(0, start)); // Adds the start to the visited list 

		while (visited.empty() == false) 
		{
			// Cache information for later use, while preventing infinite loops
			char currentNode = visited.top().second;
			int currentDistance = visited.top().first;

			visited.pop(); // A way to exit the loop

			// Searches each neighborz
			for (const pair<char, int>& neighborPair : adjacencyList.at(currentNode))
			{
				int newDistance = currentDistance + neighborPair.second;

				// Check if the new distance is shorter than the current distance
				if (newDistance < shortestPaths[neighborPair.first])
				{
					shortestPaths[neighborPair.first] = newDistance;
					route[neighborPair.first] = currentNode;
					visited.push(make_pair(newDistance, neighborPair.first));
				}
			}
		}

		// Display result
		cout << "Shortest Path to a charging station from '" << start << "' is: " << endl;

		for (const pair<char, int>& path : shortestPaths)
		{
			if (islower(path.first))
			{
				printShortestPath(start, path.first, route);
				cout << ". Total Distance: " << to_string(path.second) << endl;
			}
		}
	}

	// Function to print the shortest path 
	void printShortestPath(char start, char chargingStation, unordered_map<char, char>& route) const
	{
		if (start == chargingStation)
		{
			cout << (char)toupper(start);
		}
		else if (route[chargingStation] == '\0')
		{
			cout << "No path from " << start << " to a Charging Station";
		}
		else
		{
			printShortestPath(start, route[chargingStation], route);
			cout << " -> " << (char)toupper(chargingStation);
		}
	}
#pragma endregion

};