#include "../include/Rhombus.h"

Rhombus::Rhombus() {
    _vertices.resize(4);
}

void Rhombus::read(std::istream& is) {
    for (auto& v : _vertices) {
        is >> v;
    }
}
