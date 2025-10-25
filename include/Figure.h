#pragma once
#define FIGURE_H
#include <vector>
#include <iostream>
#include <typeinfo>
#include <cmath> 
struct Coord {
    double x, y;
    friend std::ostream& operator<<(std::ostream& os, const Coord& c);
    friend std::istream& operator>>(std::istream& is, Coord& c);
};
class Figure {
protected:
    std::vector<Coord> _vertices;
public:
    virtual ~Figure() = default;
    virtual Coord geometricCenter() const;
    virtual double area() const;
    virtual void print(std::ostream& os) const;
    virtual void read(std::istream& is) = 0; 
    virtual bool equals(const Figure& other) const;
    operator double() const;
    Figure(const Figure&) = default;
    Figure& operator=(const Figure&) = default;
    Figure(Figure&&) = default;
    Figure& operator=(Figure&&) = default;
    bool operator==(const Figure& other) const;
    const std::vector<Coord>& getVertices() const;
    friend std::ostream& operator<<(std::ostream& os, const Figure& f);
    friend std::istream& operator>>(std::istream& is, Figure& f);
};

