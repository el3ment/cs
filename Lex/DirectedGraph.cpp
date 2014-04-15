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

void DirectedGraph::generateSCCs(){
    sccs = vector<ConnectedComponent>();
    
    reverse();
    
    set<string> tempVerticies = set<string>(verticies);
    set<string>::iterator it;
    for(it = tempVerticies.end(); it != tempVerticies.begin(); it--){
        string first = string(*it);
        tempVerticies.erase(first);
        //getNextUnvisitedChild(first, tempVerticies, 0);
        
    }
    
    map<string, int>::iterator mapit;
    for(mapit = depths.begin(); mapit != depths.end(); mapit++){
        cout << "   " << mapit->first << " = " << mapit->second << endl;
    }
    
}

void DirectedGraph::getNextUnvisitedChild(string vertex, set<string>& unVisitedVerticies, int depth){
    
    depths[vertex] = depth;
    
    set<Edge>::iterator it;
    for(it = edges.begin(); it != edges.end(); it++){
        if((*it).sourceVertex == vertex){
            
            set<string>::iterator unvisited;
            for(unvisited = unVisitedVerticies.end(); unvisited != unVisitedVerticies.begin(); it--){
                if(*unvisited == (*it).destinationVertex){
                    
                    // Mark it as visited
                    //unVisitedVerticies.erase((*it).destinationVertex);
                    
                    // Find the next child
                    //getNextUnvisitedChild((*it).destinationVertex, unVisitedVerticies, depth + 1);
                }
            }
            
        }
    }
}

