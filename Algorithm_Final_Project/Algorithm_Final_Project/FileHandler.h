#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

class NodeData {
	public:
		char origin;
		char neighbour;
		int distance;
};

class NodeStorage {
	public:
		vector<NodeData> nodes;

		void OutputGraphData();
};

class FileReader {
	public:
		NodeStorage nodeStorage;

		void readGraphData(const string& graphFile)
		{
			ifstream inputFile(graphFile);
			if (!inputFile.is_open())
			{
				cerr << "Error: Unable to open file.";
				return;
			}

			string line;
			while (getline(inputFile, line)) {
				istringstream lineStream(line);
				string originPoint;
				string neighbourPoint;
				string distanceNum;
				char origin;
				char neighbour;
				int distanceAmount;

				getline(lineStream, originPoint, ',');
				getline(lineStream, neighbourPoint, ',');
				getline(lineStream, distanceNum);

				origin = originPoint[0];
				neighbour = neighbourPoint[0];
				distanceAmount = stoi(distanceNum);
				NodeData newGraph;
				newGraph.origin = origin;
				newGraph.neighbour = neighbour;
				newGraph.distance = distanceAmount;

				nodeStorage.nodes.push_back({ newGraph });
			}

			inputFile.close();
		}
};

