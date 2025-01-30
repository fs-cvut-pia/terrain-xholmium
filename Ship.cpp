#include <queue>
#include <algorithm>
#include <map>
#include "Ship.h"

// *** SHIP ***

Ship::Ship(TerrainMap &m, std::string name_in, Point start_in, Point finish_in): Path(m, name_in, start_in, finish_in) {}

bool Ship::find() {
    // find the shortest path only in fields where the altitude < 0 (except for the starting and destination points).
    using Node = std::pair<double, Point>; // Alias for readability

    auto compare = [](const Node& a, const Node& b) {
        return a.first > b.first; // Min-heap based on cost
    };

    std::priority_queue<Node, std::vector<Node>, decltype(compare)> pq(compare);
    std::map<Point, double> cost;
    std::map<Point, Point> came_from;

    pq.emplace(0.0, start);
    cost[start] = 0.0;

    std::vector<Point> directions = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1},
        {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };

    while (!pq.empty()) {
        auto [current_cost, current] = pq.top();
        pq.pop();

        if (current == finish) break;

        for (const auto& dir : directions) {
            Point neighbor = current + dir;

            if (!map.validCoords(neighbor)) continue;
            if (map.alt(neighbor) >= 0 && neighbor != finish) continue;

            double new_cost = current_cost + dir.length();

            if (!cost.count(neighbor) || new_cost < cost[neighbor]) {
                cost[neighbor] = new_cost;
                came_from[neighbor] = current;
                pq.emplace(new_cost, neighbor);
            }
        }
    }

    if (!came_from.count(finish)) return false; // No valid path found

    Point current = finish;
    while (current != start) {
        path.push_back(current);
        current = came_from[current];
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end());

    return true;
}
