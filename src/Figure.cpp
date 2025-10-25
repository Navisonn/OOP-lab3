#include "../include/Figure.h"

std::ostream& operator<<(std::ostream& os, const Coord& c) {
    os << "(" << c.x << ", " << c.y << ")";
    return os;
}
std::istream& operator>>(std::istream& is, Coord& c) {
    is >> c.x >> c.y;
    return is;
}
Coord Figure::geometricCenter() const {
    if (_vertices.empty()) return {0.0, 0.0};
    double sx = 0.0, sy = 0.0;
    for (const auto& v : _vertices) {
        sx += v.x;
        sy += v.y;
    }
    return {sx / _vertices.size(), sy / _vertices.size()};
}
double Figure::area() const {
    if (_vertices.size() < 3) return 0.0;
    double sum1 = 0.0, sum2 = 0.0;
    for (size_t i = 0; i < _vertices.size(); ++i) {
        size_t j = (i + 1) % _vertices.size();
        sum1 += _vertices[i].x * _vertices[j].y;
        sum2 += _vertices[i].y * _vertices[j].x;
    }
    return std::abs(sum1 - sum2) / 2.0;
}

void Figure::print(std::ostream& os) const {
    for (const auto& v : _vertices) {
        os << v << " ";
    }
}

bool Figure::equals(const Figure& other) const {
    return typeid(*this) == typeid(other) && _vertices == other._vertices;
}

Figure::operator double() const {
    return area();
}
bool Figure::operator==(const Figure& other) const {
    return equals(other);
}
const std::vector<Coord>& Figure::getVertices() const {
    return _vertices;
}
std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.read(is);
    return is;
}
