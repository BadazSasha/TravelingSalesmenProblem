#include "TSP.h"
#include <chrono>   
void bfs(TSP& tsp);
void ucs(TSP& tsp);
void a_star(TSP& tsp);

int main() {
    TSP tsp(7);
    tsp.cities = {
        {0, "D"},
        {1, "C"},
        {2, "L"},
        {3, "G"},
        {4, "W"},
        {5, "S"},
        {6, "T"},
    };

    tsp.addDistance(0, 1, 260);
    tsp.addDistance(0, 2, 202);
    tsp.addDistance(0, 3, 207);
    tsp.addDistance(0, 4, 170);
    tsp.addDistance(0, 5, 208);
    tsp.addDistance(0, 6, 300);

    tsp.addDistance(1, 2, 99);
    tsp.addDistance(1, 3, 204);
    tsp.addDistance(1, 4, 121);
    tsp.addDistance(1, 5, 320);
    tsp.addDistance(1, 6, 120);

    tsp.addDistance(2, 3, 107);
    tsp.addDistance(2, 4, 126);
    tsp.addDistance(2, 5, 223);
    tsp.addDistance(2, 6, 100);

    tsp.addDistance(3, 4, 230);
    tsp.addDistance(3, 5, 138);
    tsp.addDistance(3, 6, 206);

    tsp.addDistance(4, 5, 330);
    tsp.addDistance(4, 6, 203);

    tsp.addDistance(5, 6, 320);

    auto start = chrono::high_resolution_clock::now();
    a_star(tsp);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "A* Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    ucs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "UCS Execution time: " << duration << " seconds" << endl;

    start = chrono::high_resolution_clock::now();
    bfs(tsp);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::seconds>(end - start).count();
    cout << "BFS Execution time: " << duration << " seconds" << endl;
    return 0;
}
