#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "Path.h"

class Airplane final : public Path {
public:
    Airplane(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    bool find() override; // Implement pathfinding logic for an Airplane
};

#endif //AIRPLANE_H
