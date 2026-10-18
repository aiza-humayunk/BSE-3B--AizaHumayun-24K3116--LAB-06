#include <iostream>
#include <string>
using namespace std;

const int V = 4;
const char names[V] = {'A', 'B', 'C', 'D'};
const string colorNames[3] = {"Red", "Green", "Blue"};
int roads[V][V] = {
    {0, 1, 1, 0},
    {1, 0, 1, 1},
    {1, 1, 0, 1},
    {0, 1, 1, 0}
};
int paint[V];

bool colorIsSafe(int vertex, int color) {
    for (int other = 0; other < V; other++) {
        if (roads[vertex][other] && paint[other] == color) return false;
    }
    return true;
}

bool colorGraph(int vertex) {
    if (vertex == V) return true;
    for (int color = 0; color < 3; color++) {
        if (colorIsSafe(vertex, color)) {
            paint[vertex] = color;
            if (colorGraph(vertex + 1)) return true;
            paint[vertex] = -1;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < V; i++) paint[i] = -1;
    if (colorGraph(0)) {
        for (int i = 0; i < V; i++) {
            cout << "Department " << names[i] << " -> " << colorNames[paint[i]] << endl;
        }
    } else {
        cout << "No valid coloring exists." << endl;
    }
    return 0;
}
