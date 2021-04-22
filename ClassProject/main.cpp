#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool checkReflexivity (vector <int> nodes[], int numNodes);
bool checkSymmetry (vector <int> nodes [], int numNodes);
bool checkTransitivity (vector <int> nodes [], int numNodes);

int main() {

    ifstream nodeFile;
    nodeFile.open("../TestNodes");

    if (!nodeFile.is_open()){
        cout << "Error opening" << endl;
        return 1;
    }

    int numNodes;
    nodeFile >> numNodes;

    vector <int> nodes[numNodes];


    int numOfCon;
    int connectTo;

    for (int i = 0; i < numNodes; i++){
        nodeFile >> numOfCon;
        for (int j = 0; j < numOfCon; j++){
            nodeFile >> connectTo;
           nodes[i].push_back(connectTo);
        }
    }

    nodeFile.close();

    bool reflexive = checkReflexivity(nodes, numNodes);
    bool symmetric = checkSymmetry(nodes, numNodes);
    bool transitive = checkTransitivity(nodes, numNodes);

    if (reflexive && symmetric && transitive){
        cout << "The graph is reflexive, symmetric, and transitive." << endl;
    } else if (!(reflexive) && symmetric && transitive){
        cout << "The graph is symmetric and transitive." << endl;
    } else if (reflexive && !(symmetric) && transitive){
        cout << "The graph is reflexive and transitive." << endl;
    }else if (reflexive && symmetric && !(transitive)){
        cout << "The graph is reflexive and symmetric." << endl;
    } else if (reflexive && !(symmetric) && !(transitive)){
        cout << "The graph is reflexive." << endl;
    } else if (!(reflexive) && symmetric && !(transitive)){
        cout << "The graph is symmetric" << endl;
    } else if (!(reflexive) && !(symmetric) && transitive){
        cout << "The graph is transitive" << endl;
    } else if (!(reflexive) && !(symmetric) && !(transitive)){
        cout << "The graph is not reflexive, symmetric, and transitive." << endl;
    }


    return 0;
}

bool checkReflexivity (vector <int> nodes[], int numNodes){
    bool match = false;
    int j;
    for (int i = 0; i < numNodes; i++){
        for (j = 0; j < nodes[i].size() ; j++){
            if (i == nodes[i].at(j)){
                match = true;
                break;
            }
        }
        if(j == nodes[i].size()){
            match = false;
            return match;
        }
    }
    return match;
}

bool checkSymmetry (vector <int> nodes [], int numNodes){

    bool match = false;
    for (int i= 0; i < numNodes; i++){
        for (int j = 0; j < nodes[i].size(); j++){
            int x = nodes[i].at(j);
            int k;
            for (k = 0; k < nodes[x].size(); k++){
                if (nodes[x].at(k) == i){
                    match = true;
                    break;
                }
            }

            if(k == nodes[x].size()){
                match = false;
                return match;
            }
        }
    }

    return match;
}

bool checkTransitivity (vector <int> nodes [], int numNodes){
    bool match = false;
    for (int i= 0; i < numNodes; i++){
        for (int j = 0; j < nodes[i].size(); j++){
            int x = nodes[i].at(j);
            int k;
            int z;
            for (k = 0; k < nodes[x].size(); k++){
                int q = nodes[x].at(k);
                for (z = 0; z < nodes[i].size(); z++){
                    if (nodes[i].at(z) == q){
                        match = true;
                        break;
                    }
                }
                if(z == nodes[i].size()){
                    match = false;
                    return match;
                }
            }
        }
    }

    return match;
}