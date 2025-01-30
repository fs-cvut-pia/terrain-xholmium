#ifndef SHIP_H
#define SHIP_H

#include "Path.h"

class Ship final : public Path {
public:
    Ship(TerrainMap& m, std::string name_in, Point start_in, Point finish_in);
    bool find() override;
};

#endif //SHIP_H
