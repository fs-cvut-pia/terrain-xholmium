#include "Airplane.h"

// *** AIRPLANE ***

Airplane::Airplane(TerrainMap& m, std::string name_in, Point start_in, Point finish_in)
    : Path(m, name_in, start_in, finish_in) {}

bool Airplane::find() {
    // direct straight-line path
    path.clear();
    path.push_back(start);
    path.push_back(finish);
    return true;
}
