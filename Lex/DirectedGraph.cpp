/* 
 * File:   DirectedGraph.cpp
 * Author: robert
 * 
 * Created on April 14, 2014, 8:42 PM
 */

#include "DirectedGraph.h"
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#include "Utils.h"
#include "ConnectedComponent.h"

using namespace std;

DirectedGraph::DirectedGraph() {
}

DirectedGraph::DirectedGraph(const DirectedGraph& orig) {
}

DirectedGraph::~DirectedGraph() {
}


void DirectedGraph::addEdge(string source, string destination){
    Edge edge = Edge();
    edge.sourceVertex = source;
    edge.destinationVertex = destination;
    edges.insert(edge);
    
//    Vertex vertex = Vertex();
//    vertex.id = source;
    verticies.insert(source);
    verticies.insert(destination);
}

void DirectedGraph::reverse(){
    set<Edge>::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        string temp = (*it).sourceVertex;
        (*it).sourceVertex = (*it).destinationVertex;
        (*it).destinationVertex = temp;
    }
}

string DirectedGraph::toString(){
    stringstream ss;
    
    set<Edge>::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        ss << "(" << (*it).sourceVertex << ", " << (*it).destinationVertex << ")" << endl;
    }
    
    ss << endl << " SCCS : " << endl;
    
    for(int i = 0; i < sccs.size(); i++){
        ss << sccs[i].toString();
    }
    
    return ss.str();
}

void DirectedGraph::generateDepths(){
    unVisitedVerticies = set<string>(verticies);
    set<string>::reverse_iterator it;
    
    while(unVisitedVerticies.size() != 0){
        string last = *(unVisitedVerticies.rbegin());
        unVisitedVerticies.erase(last);
        tree = vector<string>();
        buildTree(last, 0);
    }
    
//    cout << endl << "Depths : " << endl;
//    map<int, vector<string> >::iterator mapit;
//    for(mapit = depths.begin(); mapit != depths.end(); mapit++){
//        cout << "   " << mapit->first << " = ";
//        for(int i = 0; i < mapit->second.size(); i++){
//            cout << mapit->second[i] << ",";
//        }
//        cout << endl;
//    }
}

void DirectedGraph::generateSCCs(){
    sccs = vector<ConnectedComponent>();
    
    reverse();
    generateDepths();
   
    
    reverse(); // Reverse it back to normal
    
    map<int, vector<string> >::iterator mapit;
    unVisitedVerticies = set<string>(verticies);
    map<int, vector<string> > tempDepths = depths;
    for(mapit = tempDepths.begin(); mapit != tempDepths.end(); mapit++){
        
        for(int i = 0; i < mapit->second.size(); i++){
            
            if(existsInSetStrings(unVisitedVerticies, mapit->second[i])){
               tree = vector<string>();
                unVisitedVerticies.erase(mapit->second[i]);

                buildTree(mapit->second[i], 0);
                
                // save the current tree as a connected component
                ConnectedComponent cc = ConnectedComponent(tree);
                sccs.push_back(cc);
            }
        }
        
    }
    
}

void DirectedGraph::buildTree(string vertex, int currentDepth){
    
    depths[currentDepth].push_back(vertex);
    tree.push_back(vertex);
    
    set<Edge>::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        if((*it).sourceVertex == vertex){
            set<string>::reverse_iterator unvisited;
            for(unvisited = unVisitedVerticies.rbegin(); unvisited != unVisitedVerticies.rend(); unvisited++){
                if((*unvisited) == (*it).destinationVertex){
                    
                    // Mark it as visited
                    unVisitedVerticies.erase((++unvisited).base());
                    
                    // Find the next child
                    buildTree((*it).destinationVertex, currentDepth + 1);
                    return;
                }
            }
            
        }
    }
}