/*
 * graphlib.h
 *
 *  Created on: Apr 1, 2012
 *      Author: dst
 */

#ifndef GRAPHLIB_H_
#define GRAPHLIB_H_

#include <algorithm>
#include <functional>
#include <vector>

typedef std::vector<std::vector<int> > Vertexes;

class Graph {
public:
    
    Graph(const Vertexes vertexes): vertexes(vertexes) {}
    
    inline int size() {
        return vertexes.size();
    }
    
    bool isConnected() { 
        visited = std::vector<bool>(size(), false);
        dfs(0); 
        return (std::find(visited.begin(), visited.end(), false) == visited.end()); 
    }
    
private:
    Vertexes vertexes;
    vector<bool> visited;
 
    void dfs(int i) { 
        if(!visited[i]) { 
            visited[i] = true; 
            std::for_each(vertexes[i].begin(), vertexes[i].end(),
                    bind1st(mem_fun(&Graph::dfs), this)); 
        } 
    } 
};

// tests
inline void graph() {
    Vertexes v(2);
    assert(!Graph(v).isConnected());
    v[0].push_back(1);
    assert(Graph(v).isConnected());
    
}

#endif /* GRAPHLIB_H_ */
