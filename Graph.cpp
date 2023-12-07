#include "Graph.h"
#include <algorithm>

/**
* @file Graph.cpp -metods
*/

Graph::Graph(string filename) {
    this->count = 0;
    this->min = -1;
    this->data = nullptr;
    this->loadFromFile(filename);
}

int pocCount(string& nazev_souboru) {
    ifstream soubor(nazev_souboru);
    if (!soubor) {
        cerr << "Nepodaøilo se otevøít soubor." << endl;
        return 0;
    }
    int nejvetsi_cislo = INT_MIN;           //nejvetsi vrchol hledam od int min
    string radek;
    while (getline(soubor, radek)) {
        stringstream ss(radek);             //Umozni mi lepší práci se stringy
        int cislo;
        while (ss >> cislo) {               //beru cislo sokud je co brat
            if (cislo > nejvetsi_cislo) {   //vyhodnocuju nejvìtší
                nejvetsi_cislo = cislo;
            }
        }
    }
    soubor.close();
    return nejvetsi_cislo + 1;
}

void Graph::loadFromFile(string filename) {
    string line;
    ifstream file;

    file.open(filename);
    if (file.is_open()) {
        this->count = pocCount(filename);
        this->data = new map<int, vector<int>*>[count];
        while (getline(file, line)) {
            string first = line.substr(0, line.find(" "));
            string second = line.substr(line.find(" "));
            this->AddEdge(stoi(first), stoi(second));
        }
    }
    else {
        throw new exception("ERROR: Soubor nelze naèíst.");
    }
    file.close();
}

bool Graph::AddVertex(int x) {
    if (data->find(x) == data->end()) {                     //pokud už neexistuje
        this->min = (this->min == -1) ? x : this->min;
        this->min = (x < this->min) ? x : this->min;
        data->insert(pair<int, vector<int>*>(x, new vector<int>));
        return true;
    }
    return false;
}

void Graph::AddEdge(int x, int y){
    this->AddVertex(x);
    this->AddVertex(y);
    auto index_x = upper_bound(this->data->at(y)->cbegin(), this->data->at(y)->cend(), x); // Najde vrchol a iterátor na místo ve vector v poli kontejnerù
    auto index_y = upper_bound(this->data->at(x)->cbegin(), this->data->at(x)->cend(), y); 
    this->data->at(x)->insert(index_y, y);
    this->data->at(y)->insert(index_x, x);  // vytvoøí v tom kontejneru pro bod x a y hrany mezi x a y
}

int Graph::GetCount() {
    return this->count;
}

int Graph::GetMin() {
    return this->min;
}

map<int, vector<int>*>* Graph::GetData() {
    return this->data;
}

void Graph::Print() {
    cout << "Vizualizace grafu: \n";
    for (map<int, vector<int>*>::iterator i = this->data->begin(); i != this->data->end(); i++){
        cout << "\t[" << i->first << "]";
        for (int j = 0; j < i->second->size(); j++){
            cout << " -> " << i->second->at(j);
        }
        cout << "\n";
    }
}