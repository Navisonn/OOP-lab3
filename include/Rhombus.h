#pragma once
#define RHOMBUS_H
#include "Figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    void read(std::istream& is) override;
};
