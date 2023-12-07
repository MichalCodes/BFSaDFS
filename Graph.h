#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

/**
* @file Graph.h
* @class Graph
*/
class Graph{
private:
	/**
	* @brief count store number how many vertexes in mam container we must allocate
	*/
	int count;
	/**
	* @brief min - store the smallest vertex
	*/
	int min;
	/**
	* @brief this is map container for edges of graph we save there int anr vector
	*/
	map<int, vector<int>*>* data;
	/**
	* This function load graph from file - it using function int pocVektoru() which returns how much edge space in map container we must allocate
	* @param string - name of file
	*/
	void loadFromFile(string filename);
	/**
	* This function added new vertexes
	* @param int x - number of vertex
	*/
	bool AddVertex(int x);
public:
	/**
	* Konstruktor
	*/
	Graph(string filename);
	/**
	* It added new edge which are saved in map container
	* @params int x, int y - vertices between which there is an edge 
	*/
	void AddEdge(int x, int y);
	/**
	* Edges getter
	* @return map container
	*/
	map<int, vector<int>*>* GetData();
	/**
	* Getter for int count
	*/
	int GetCount();
	/**
	* Getter for int min
	*/
	int GetMin();
	/**
	* It printed graph visualization - [vertex] -> conected vertexes to vertex in [] (it's not a path)
	*/
	void Print();
};