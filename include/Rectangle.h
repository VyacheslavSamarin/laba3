#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
private:
    double x, y, width, height;

public:
    Rectangle();
    Rectangle(double x, double y, double width, double height);

    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double area() const override;

    Rectangle* clone() const override;
    Rectangle* move() override;

    bool operator==(const Figure& other) const override;
};

#endif