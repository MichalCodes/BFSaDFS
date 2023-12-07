#include "./DSFIterator.h"

/**
* @file DFSIterator.cpp -metods
*/

DFSIterator::DFSIterator(Graph* graph) {
	this->discovered = new bool[graph->GetCount()] { false };
	this->currentStack = new stack<int>;
	this->graph = graph;
	this->discovered[graph->GetMin()] = true;
	this->Reset();
}

void DFSIterator::Reset() {
	this->currentStack->push(this->graph->GetMin());
}

int DFSIterator::CurrentKey() {
	if (!this->currentStack->empty()) {
		return this->currentStack->top();
	}
	return -1;
}

bool DFSIterator::IsEnd() {
	if (this->currentStack->size() == 0) {
		for (int i = 0; i < this->graph->GetCount(); i++) {
			if (!this->discovered[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void DFSIterator::Next() {
	if (this->currentStack->empty()) {
		for (int i = 0; i < this->graph->GetCount(); i++) {
			if (!this->discovered[i]) {
				this->currentStack->push(i);
				break;
			}
		}
	}
	else {
		this->discovered[this->currentStack->top()] = true;
		vector<int>* current_vertex = this->graph->GetData()->at(this->currentStack->top()); //vezme hrany spojujujici vrchol se sousedy
		for (int i = 0; i < current_vertex->size(); i++) {									// Najdi souseda vrcholu a hoï ho do zásobníku
			int new_item = current_vertex->at(i);
			if (!this->discovered[new_item]) {
				this->currentStack->push(new_item);
				break;
			}
			if (i == current_vertex->size() - 1){	// Kdyz nebyl nalezen žádný nový soused vrcholu jdi na pøedchozí vrchol
				this->currentStack->pop();
				if (this->currentStack->empty() || this->discovered[this->currentStack->top()]) { // Když je zásobník prázdný nebo vrchol už je oznaèený zavolej funkci znovu
					this->Next();
				}
			}
		}
	}
}