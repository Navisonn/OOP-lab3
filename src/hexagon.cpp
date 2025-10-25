#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon(double s) : side(s) {
    vertices.clear();
    for (int i = 0; i < 6; ++i) {
        double angle = 2.0 * M_PI * i / 6.0;
        vertices.emplace_back(side * cos(angle), side * sin(angle));
    }
}

Point Hexagon::center() const {
    return Point(0, 0);
}
double Hexagon::area() const {
    return (3.0 * sqrt(3.0) * side * side) / 2.0;
}
void Hexagon::print(std::ostream& os) const {
    os << "Hexagon vertices: ";
    for (size_t i = 0; i < vertices.size(); ++i) {
        os << "(" << vertices[i].x << ", " << vertices[i].y << ")";
        if (i != vertices.size() - 1) os << " ";
    }
}

void Hexagon::read(std::istream& is) {
    is >> side;
    *this = Hexagon(side);
}
bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* rhs = dynamic_cast<const Hexagon*>(&other);
    if (!rhs) return false;
    return std::abs(side - rhs->side) < 1e-9;
}


Hexagon& Hexagon::operator=(const Hexagon& other) {
    if (this != &other) {
        side = other.side;
        vertices = other.vertices;
    }
    return *this;
}
Hexagon& Hexagon::operator=(Hexagon&& other) noexcept {
    if (this != &other) {
        side = std::move(other.side);
        vertices = std::move(other.vertices);
    }
    return *this;
}
