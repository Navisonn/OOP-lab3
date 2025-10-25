#pragma once
#define HEXAGON_H

#include "Figure.h"

class Hexagon : public Figure {
public:
    Hexagon();
    void read(std::istream& is) override;
};
