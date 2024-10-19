#include "Triangle.h"
#include <cmath>

Triangle::Triangle() : x1(0), y1(0), x2(0), y2(0), x3(0), y3(0) {}

Triangle::Triangle(double _x1, double _y1, double _x2, double _y2, double _x3, double _y3)
    : x1(_x1), y1(_y1), x2(_x2), y2(_y2), x3(_x3), y3(_y3) {}

std::pair<double, double> Triangle::center() const {
    double cx = (x1 + x2 + x3) / 3.0;
    double cy = (y1 + y2 + y3) / 3.0;
    return {cx, cy};
}

void Triangle::print(std::ostream& os) const {
    os << "Triangle: (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << "), (" << x3 << ", " << y3 << ")";
}

void Triangle::read(std::istream& is) {
    is >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
}

double Triangle::area() const {
    return 0.5 * std::abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
}

Triangle* Triangle::clone() const {
    return new Triangle(*this);
}

Triangle* Triangle::move() {
    return new Triangle(std::move(*this));
}

bool Triangle::operator==(const Figure& other) const {
    const Triangle* otherTriangle = dynamic_cast<const Triangle*>(&other);
    if (!otherTriangle) return false;
    return std::abs(x1 - otherTriangle->x1) < 1e-9 && std::abs(y1 - otherTriangle->y1) < 1e-9 &&
           std::abs(x2 - otherTriangle->x2) < 1e-9 && std::abs(y2 - otherTriangle->y2) < 1e-9 &&
           std::abs(x3 - otherTriangle->x3) < 1e-9 && std::abs(y3 - otherTriangle->y3) < 1e-9;
}