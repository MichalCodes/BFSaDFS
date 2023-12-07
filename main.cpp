
#include <iostream>
#include "./Graph.h"
#include "./DSFIterator.h"
#include "./BSFIterator.h"

using namespace std;

/**
* @file main.cpp
*/

int main()
{
    string confFile;
    cout << "Soubor s grafem (Default Graf2.txt): ";
    getline(cin, confFile);
    confFile = (confFile.empty()) ? "Graf2.txt" : confFile;
    try {
        Graph* graph = new Graph(confFile);
        graph->Print();

        cout << "\nIterator do hloubky DFS: ";
        DFSIterator* iteratorDFS = new DFSIterator(graph);
        iteratorDFS->Reset();
        while (!iteratorDFS->IsEnd()) {
            cout << iteratorDFS->CurrentKey() << " "; // Vypisuju aktualni prvek
            iteratorDFS->Next();                      // Další krok Iteratoru
        }

        cout << "\nIterator do sirky BFS:   ";
        BFSIterator* iteratorBFS = new BFSIterator(graph);
        iteratorBFS->Reset();
        while (!iteratorBFS->IsEnd()) {
            cout << iteratorBFS->CurrentKey() << " ";
            iteratorBFS->Next();
        }
    }
    catch (...) {
        cout << "ERROR: Soubor nelze nacist.";
    }
    cin.get();
    return 0;
}