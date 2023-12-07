#pragma once
#include <stack>
#include <queue>
#include "./Graph.h";

/**
* @file BFSIterator.h
* @class BFSIterator
*/

class BFSIterator{
private:
	/**
	* @brief mark done vertexes
	*/
	bool* discovered;
	/**
	* @brief It using queue
	*/
	queue<int>* currentQueue;
	/**
	* @brief My graph from file
	*/
	Graph* graph;
public:
	/**
	* Konstruktor
	*/
	BFSIterator(Graph* graph);
	/**
	* Reset - The iterator will start from beginning
	*/
	void Reset();
	/**
	* Next - it send us to next vertex in queue, or to another component in graph
	*/
	void Next();
	/**
	* Checks if we are at the end (if we have gone trough all vertexes in graph)
	* @return bool
	*/
	bool IsEnd();
	/**
	* CurrentKey - It returns actual element in the queue
	* @return int
	*/
	int CurrentKey();
};

