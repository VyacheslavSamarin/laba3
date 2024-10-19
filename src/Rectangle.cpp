#include "Rectangle.h"
#include <cmath>

Rectangle::Rectangle() : x(0), y(0), width(0), height(0) {}

Rectangle::Rectangle(double _x, double _y, double _width, double _height) : x(_x), y(_y), width(_width), height(_height) {}

std::pair<double, double> Rectangle::center() const {
    return {x + width / 2.0, y + height / 2.0};
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle: (" << x << ", " << y << "), width = " << width << ", height = " << height;
}

void Rectangle::read(std::istream& is) {
    is >> x >> y >> width >> height;
}

double Rectangle::area() const {
    return width * height;
}

Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);
}

Rectangle* Rectangle::move() {
    return new Rectangle(std::move(*this));
}

bool Rectangle::operator==(const Figure& other) const {
    const Rectangle* otherRectangle = dynamic_cast<const Rectangle*>(&other);
    if (!otherRectangle) return false;
    return std::abs(x - otherRectangle->x) < 1e-9 && std::abs(y - otherRectangle->y) < 1e-9 &&
           std::abs(width - otherRectangle->width) < 1e-9 && std::abs(height - otherRectangle->height) < 1e-9;
}