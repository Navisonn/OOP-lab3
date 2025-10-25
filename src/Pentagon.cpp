#include "../include/Pentagon.h"

Pentagon::Pentagon() {
    _vertices.resize(5);
}

void Pentagon::read(std::istream& is) {
    for (auto& v : _vertices) {
        is >> v;
    }
}
