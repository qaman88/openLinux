#ifndef NGOBENI_GRAPH_H
#define NGOBENI_GRAPH_H
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

namespace ngobeni {
using namespace std;

class Graph {
	protected:
		// current number of vertices
		int capacity;
		// adjacency lists 
		vector<int> * graph;
		
	public:
		// default constructor
		Graph() {
			capacity = 0;
		}
		
		// override constructor
		Graph(string filename) {
			// create graph from file
			Create(filename);
		}
		
		// graph destructor
		~Graph() {
			
		}
		
		// function determine if graph is empty
		bool IsEmpty() const {
			return capacity == 0;			
		}
		
		// function return size of graph
		int Size() {
			return capacity;
		}
		
		// function create graph
		void Create(string filename) {
			// init control variables
			int vertex;
			int adjacent;
			
			// clear graph
			if (capacity != 0) Clear();
			
			// init and open file
			ifstream file(filename);
			
			// perform operators on valid file
			if (file.is_open()) {
				// get the number of vertices
				file >> capacity;
				
				// init graph
				graph = new vector<int>[capacity];
				
				// iterates vertices while creating adjacency list
				for (int i = 0; i < capacity; i++) {
					// read vertex
					file >> vertex;
					
					// read adjecent
					file >> adjacent;
					
					// read all adjacency of current vertex
					while (adjacent != -999) {						
						
						// store adjacent of current vertex
						graph[vertex].push_back(adjacent);
						
						// move to next adjacent of current vertex
						file >> adjacent;
					} // end while
					
				} // end for			
					
			} // end if is open			
		} // end create
		
		// function clear graph
		void Clear() {
			for (int i = 0; i < capacity; i++) {
				graph[i].clear();
			}
			capacity = 0;
		}
		
		// function print graph
		void Print() {
			for (int i = 0; i < capacity; i++) {
				printf("%i: ", i);
				PrintVector(graph[i]);
			}
		}
		
		// function to print adjacency list
		void PrintVector(vector<int>  & V) {
			for (int i = 0; i < V.size(); i++) {
				printf("%i, ", V[i]);
			}
			printf("\n");
		}
		
		// function to perform depth first transverse on entire graph
		void GraphDFT() {
			// vector to track visited vertces
			vector<bool> visited(capacity, false);
			
			// visit verteces
			for (int i = 0; i < capacity; i++) {
				// perform DFT on non visted verteces
				if (not visited[i]) {
					DFT(i, visited);
				}
			}
			printf("\n");
			// clear visited vector
			visited.clear();
		} // end GraphDFT
		
		// function to perform depth first transverse on vertex of graph
		void VertexDFT(int vertex) {
			// vector to track visited vertces
			vector<bool> visited(capacity, false);
			
			// visit verteces
			DFT(vertex, visited);
			
			// clear visited vector
			visited.clear();
		}
		
		// function to perform breath first transverse on entire graph
		
		void GraphBFT() {
			// vector store vector to visit next
			vector<int> nextvisit;
			// vector to track visited vertces
			vector<bool> visited(capacity, false);
			// init with first node
			nextvisit.push_back(0);
			
			string line = "";
			
			int node;
			while ( not nextvisit.empty() ) {
				node = nextvisit.front();
				nextvisit.erase(nextvisit.begin(), nextvisit.begin() + 1);
				
				// skip iteration if node is visited
				if (visited[node]) continue;
				
				// store node
				line +=  std::to_string(node) + ", ";
				
				// mark node visited
				visited[node] = true;
				
				// add adjacents to nextvisit
				for (int a: graph[node])
					nextvisit.push_back(a);
			}	
			
			// node without down link
			for(int i = 0; i < capacity; i++) {
				// add unvisted node
				if (not visited[i]) 
					nextvisit.push_back(i);
			}
			
			while ( not nextvisit.empty() ) {
				node = nextvisit.front();
				nextvisit.erase(nextvisit.begin(), nextvisit.begin() + 1);
				
				// skip iteration if node is visited
				if (visited[node]) continue;
				
				// store node
				line +=  std::to_string(node) + ", ";
				
				// mark node visited
				visited[node] = true;
				
				// add adjacents to nextvisit
				for (int a: graph[node])
					nextvisit.push_back(a);
			}	
			
			// clear visited vector
			visited.clear();
			
			// print line
			printf("%s \n", line.c_str());		
		}
		void GraphBFT2() {			
			// quaue for verteces to be visted
			vector<int> queue;			
			// vector to track visited vertces
			vector<bool> visited(capacity, false);
			
			string line = "";
			
			// visit verteces
			for (int vertex = 0; vertex < capacity; vertex++) {
				// perform BFT on non visted verteces
				if (not visited[vertex]) {
					// save vertex to queue
					queue.push_back(vertex);					
					// mark it visted
					visited[vertex] = true;					
					// visit the vertex
					line += std::to_string(vertex) + ", ";
					
					while (not queue.empty()) {
						// front element from queue
						int u = queue.front();						
						// clear queue
						//PrintVector(queue);
						queue.erase(queue.begin(), queue.end());
						// init adjacent
						int adjacent;
						// loop on adjacents of current vertex
						for (int i = 0; i < graph[vertex].size(); i++) {
							// get current vertex adjacent[i]
							adjacent = graph[vertex][i];
							
							if (not visited[adjacent]) {
								// save vertex to queue
								queue.push_back(adjacent);								
								// mark it visted
								visited[adjacent] = true;								
								// visit the vertex
								line += std::to_string(adjacent) + ", ";
							} // end not visited adjacent if
							
						} // end adjacent loop
						
					} // end queue loop
					
				} // end not visited vertex if
				
			} // end vertex loop
			
			// clear visited vector
			visited.clear();
			
			// print line
			printf("%s \n", line.c_str());
			
		} // end GraphBFT
		
	private:
		// function to perform the depth first traversal on a given node
		void DFT(int vertex, vector<bool> & visited) {
			// print vertex
			printf("%i, ", vertex);
			
			// mark vertex visited
			visited[vertex] = true;
			
			// visit adjecent vertex
			int adjacent;
			for (int i = 0; i < graph[vertex].size(); i++) {
				adjacent = graph[vertex][i];
				// visit non visited vector
				if (not visited[adjacent]) {
					DFT(adjacent, visited);
				}
			}
		}
};
	
}
 #endif
