#include "../include/Hexagon.h"

Hexagon::Hexagon() {
    _vertices.resize(6);
}
void Hexagon::read(std::istream& is) {
    for (auto& v : _vertices) {
        is >> v;
    }
}
