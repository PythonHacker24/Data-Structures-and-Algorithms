#include <iostream>
#include <unordered_map>				// Similar to hash table, there are two rows where key-value pair structures are stored.
#include <unordered_set>				// It's like a array. Here, if same data is pushed into the array, only one instance is created. (Close enough to Hash Table concept)

using namespace std;

class Graph{
	private:
		unordered_map<string, unordered_set<string> > adjList;				// unordered_map< data_type, data_type > map_name; 
																			// Here, in this case, key is s string and the value is a unordered_set with string values and this whole map is named adjList

	public:
		void printGraph(){
			for (auto [vertex, edges] : adjList){				// As per the plan, the structuring is arranged. In this case, vertex will contain the key of the adjList and edges will be the value, in this case it is a unordered set
				cout << vertex << ": [";
				for (auto edge: edges){				// Here, we are getting the value of each element in the set as a variable edge from the unordered_set called edges which was the value of the key in the unordered map
					cout << edge << " ";
				}
				cout << "]" << endl;
			}
		}

		bool addVertex (string vertex){
			if (adjList.count(vertex) == 0){				// Check is the given vertex exists in the adjList unordered_map
				adjList[vertex];
				return true;
			}
			return false;
		}

		bool addEdge(string vertex1, string vertex2){				// Get the name as a string of the two vertex that are to be connected
			if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0){				// Check for if the given vertex exist in the adjList unordered_map
				adjList.at(vertex1).insert(vertex2);				// Insert (associate) the value of the vertex to the other vertex in it's corresponding unordered_list (edge) 
				adjList.at(vertex2).insert(vertex1);				// Do the vice-versa of the previous instruction
				return true;
			}
			return false;
		}

		bool removeEdge(string vertex1, string vertex2){				// Get the name as a string of the two vertex that are to be disconnected
			if (adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0){				// Check for if the given vertex exist in the adjList unordered_map
				adjList.at(vertex1).erase(vertex2);				// erase (remove) the value of the vertex to the other vertex in it's corresponding unordered_list (edge) 
				adjList.at(vertex2).erase(vertex1);				// Do the vice-versa of the previous instruction
				return true;
			}
			return false;
		}

		bool removeVertex(string vertex){
			if (adjList.count(vertex) == 0) return false;				// If the vertex does not exist in the Graph, return false
			for (auto otherVertex: adjList.at(vertex)){				// For every vertex given in the unordered_list which contains the edges of the associated Vertex, apply the following operation on it (that is to go to that vertex and delete the given vertex that is to be deleted) 
				adjList.at(otherVertex).erase(vertex);				// Erase the linkage of the given vertex with that vertex in the unordered_map
			}
			adjList.erase(vertex);				// Finally, erase the given vertex as whole (the key that is the name of the vertex as well as the unordered_list associated with that vertex)
			return true;
		}
};

int main(){
	Graph* myGraph = new Graph();
	myGraph->addVertex("A");
	myGraph->addVertex("B");
	myGraph->addVertex("C");
	
	myGraph->addEdge("A", "B");
	myGraph->addEdge("B", "C");
	myGraph->addEdge("C", "A");
    
    myGraph->removeVertex("A");
	
	myGraph->printGraph();
}