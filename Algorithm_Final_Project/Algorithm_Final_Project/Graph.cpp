#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

#include <string>


using namespace std;

template <typename TType, typename TWeight>
class Graph
{
private:
#pragma region PRIVATE_DATA_MEMBER
	
#pragma endregion


#pragma region PRIVATE_MEMBER

#pragma endregion
public:
#pragma region PUBLIC_DATA_MEMBER
	unordered_map<TType, vector<pair<TType, TWeight>>> adjacencyList;
	const unordered_map<TType, vector<pair<TType, TWeight>>>& GetAdjacencyList() const { return adjacencyList; } // Getter
#pragma endregion


#pragma region PUBLIC_FUNCTION
	Graph() : adjacencyList() {} // Default constructor to safe state

	void AddEdge(const TType& start, const TType& destination, const TWeight& edgeWeight)
	{
		adjacencyList[start].push_back(make_pair(destination, edgeWeight));
		adjacencyList[destination].push_back(make_pair(start, edgeWeight));
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