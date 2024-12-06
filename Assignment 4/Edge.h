#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <sstream>
#include <string>

class Edge {
public:
    int start, end, weight;
    Edge(int s, int e, int w) : start(s), end(e), weight(w) {}
};
