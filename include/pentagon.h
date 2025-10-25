#pragma once
#include "figure.h"

class Pentagon : public Figure {
private:
    double side; 
public:
    Pentagon() = default;


    Pentagon(double s);
    Pentagon(const Pentagon& other) = default;
    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    bool operator==(const Figure& other) const override;
    Pentagon& operator=(const Pentagon& other);
    Pentagon& operator=(Pentagon&& other) noexcept;
};
