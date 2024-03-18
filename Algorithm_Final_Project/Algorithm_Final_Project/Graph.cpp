#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

template <typename TType>
class Graph
{
private:
#pragma region PRIVATE_DATA_MEMBER
	
#pragma endregion


#pragma region PRIVATE_MEMBER

#pragma endregion
public:
#pragma region PUBLIC_DATA_MEMBER
	unordered_map<TType, vector<pair<TType, int>>> adjacencyList;
	const unordered_map<TType, vector<pair<TType, int>>>& GetAdjacencyList() const { return adjacencyList; } // Getter
#pragma endregion


#pragma region PUBLIC_FUNCTION
	Graph() : adjacencyList() {} // Default constructor to safe state

	/// <summmary>
	/// Adds connections between nodes to create the graph
	/// </summary>
	/// <param name="start">Starting node</param>
	/// <param name="destination">Node that connects to the starting node</param>
	/// <param name="edgeWeight">The weight of the connection. Usually it represents distance.</param>
	void AddEdge(const TType& start, const TType& destination, const int& edgeWeight)
	{
		// Inserts or updates node's neighbor list. NOTE: if the node does not exist, it will add it before adding the neighbor.
		adjacencyList[start].push_back(make_pair(destination, edgeWeight));
		adjacencyList[destination].push_back(make_pair(start, edgeWeight));
	}

	/// <summary>
	/// Used Dijkstra's Algorithm to find the shortest path to every node in the graph.
	/// </summary>
	/// <param name="start">Starting node</param>
	/// <returns>An unordered map of nodes and the distance from the starting node's position.</returns>
	unordered_map<TType, int> Dijkstra (const TType& start) const
	{
		unordered_map<TType, int> shortestPaths;
		priority_queue< pair<int, TType>, vector<pair<int, TType>>, greater<>> visited;
		
		// Set all paths to each node as infinity
		for (const pair<TType, vector<pair<TType, int>>>& vertexPair adjacencyList) 
		{
			shortestPaths[vertexPair.first] = -1; // In place of infinity
		}

		// Set the start as a distance of 0;
		shortestPaths[start] = 0;
		visited.push(make_pair(0, start)); // Add the start to the visited list

		while (visited.empty() == false) 
		{
			// Cache information for later use, while preventing infinite loops
			TType currentNode = visited.top().second;
			int currentDistance = visited.top().first;

			visited.pop(); // A way to exit the loop

			// Searches each neighbor
			for (const pair<TType, int>& neighborPair : adjacencyList[currentNode])
			{
				int newDistance = currentDistance + neighborPair.second;

				// Check if the new distance is shorter than the current distance (make sure that the placeholder infinite [-1] gets replaced)
				if (newDistance < shortestPath[neighborPair.first] || newDistance > -1)
				{
					shortestPaths[neighborPair.first] = newDistance;
					visited.push(make_pair(newDistance, neighborPair.first));
				}
			}
		}

		return shortestPaths;
	}
#pragma endregion

};


struct Node
{
private:
	string name = "";
	bool isChargingStation = false;
public:
	Node(string n, bool chargingStation = false) : name(n), isChargingStation(chargingStation) {} // OVerloaded Constructor
	const string& Name() const { return name; } // Getter
	const bool& IsChargingStation() const { return isChargingStation; } // Getter
};