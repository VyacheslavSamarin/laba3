#include "Square.h"
#include <cmath>

Square::Square() : x(0), y(0), side(0) {}

Square::Square(double _x, double _y, double _side) : x(_x), y(_y), side(_side) {}

std::pair<double, double> Square::center() const {
    return {x + side / 2.0, y + side / 2.0};
}

void Square::print(std::ostream& os) const {
    os << "Square: (" << x << ", " << y << "), side = " << side;
}

void Square::read(std::istream& is) {
    is >> x >> y >> side;
}

double Square::area() const {
    return side * side;
}

Square* Square::clone() const {
    return new Square(*this);
}

Square* Square::move() {
    return new Square(std::move(*this));
}

bool Square::operator==(const Figure& other) const {
    const Square* otherSquare = dynamic_cast<const Square*>(&other);
    if (!otherSquare) return false;
    return std::abs(x - otherSquare->x) < 1e-9 && std::abs(y - otherSquare->y) < 1e-9 && std::abs(side - otherSquare->side) < 1e-9;
}