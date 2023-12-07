#include "./BSFIterator.h"

/**
* @file BFSIterator.cpp -metods
*/

BFSIterator::BFSIterator(Graph* graph) {
	this->discovered = new bool[graph->GetCount()] { false };
	this->currentQueue = new queue<int>;
	this->graph = graph;
	this->Reset();
	this->discovered[graph->GetMin()] = true;
}

void BFSIterator::Reset() {
	this->currentQueue->push(this->graph->GetMin());
}

int BFSIterator::CurrentKey() {
	if (!this->currentQueue->empty()) {
		return this->currentQueue->front();
	}
	return -1;
}

bool BFSIterator::IsEnd() {
	if (this->currentQueue->size() == 0) {
		for (int i = 0; i < this->graph->GetCount(); i++) {
			if (!this->discovered[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void BFSIterator::Next() {
	if (this->currentQueue->empty()) {
		for (int i = 0; i < this->graph->GetCount(); i++) {
			if (!this->discovered[i]) {
				this->currentQueue->push(i);
				break;
			}
		}
	}
	else {
		this->discovered[this->currentQueue->front()] = true;
		vector<int>* currentVertex = this->graph->GetData()->at(this->currentQueue->front()); //vezme si hrany gafu který spojují aktuální vektor se sousedy
		this->currentQueue->pop();															  //Odstraní aktuální vrchol z fronty
		for (int i = 0; i < currentVertex->size(); i++) {
			int neighborVertex = currentVertex->at(i);										  //Projde všechny vrcholy a ty neprozkoumaný pushne do fronty
			if (!this->discovered[neighborVertex]) {
				this->currentQueue->push(neighborVertex);
			}
		}
		if (this->currentQueue->empty() || this->discovered[this->currentQueue->front()]) {	 //Když projde komponentu pustí funkci znovu
			this->Next();
		}
	}
}