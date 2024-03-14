#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>


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
	unordered_map<TType, vector<TType, TWeight>> adjacencyList;
#pragma endregion

#pragma region PUBLIC_FUNCTION

#pragma endregion

};