#ifndef CAR_H
#define CAR_H

#include "Path.h"

class Road final : public Path {
public:
    Road(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    bool find() override; // Implement pathfinding logic for a Ship
};

#endif //CAR_H
