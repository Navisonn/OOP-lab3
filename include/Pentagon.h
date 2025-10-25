#pragma once
#define PENTAGON_H
#include "Figure.h"

class Pentagon : public Figure {
public:
    Pentagon();
    void read(std::istream& is) override;
};
