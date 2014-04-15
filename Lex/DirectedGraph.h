/* 
 * File:   DirectedGraph.h
 * Author: robert
 *
 * Created on April 14, 2014, 8:42 PM
 */

#ifndef DIRECTEDGRAPH_H
#define	DIRECTEDGRAPH_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include "ConnectedComponent.h"

using namespace std;

class DirectedGraph {
public:
    
    struct Vertex{
        
        mutable string id;
        
        bool operator<(const Vertex& rhs) const{
          if(id.compare(rhs.id) < 0)
              return true;
          else
              return false;
        }

        bool operator==(const Vertex& rhs) const{
          return id == rhs.id;
        }
    };
    
    struct Edge{
        
        mutable string sourceVertex;
        mutable string destinationVertex;
        
        bool operator<(const Edge& rhs) const{
          if(sourceVertex.compare(rhs.sourceVertex) < 0)
              return true;
          else
              return false;
        }

        bool operator==(const Edge& rhs) const{
          return sourceVertex == rhs.sourceVertex && destinationVertex == rhs.destinationVertex;
        }

    };
    
    DirectedGraph();
    DirectedGraph(const DirectedGraph& orig);
    virtual ~DirectedGraph();
    
    //set<DirectedGraph::Vertex> verticies;
    set<string> verticies;
    set<DirectedGraph::Edge> edges;
    vector<ConnectedComponent> sccs;
    map<string, int> depths;
    
    void reverse();
    void addVertex(string id);
    void addEdge(string source, string destination);
    string toString();
    void generateSCCs();
    void getNextUnvisitedChild(string vertex, set<string>& visitedVerticies, int depth);
private:

};

#endif	/* DIRECTEDGRAPH_H */

