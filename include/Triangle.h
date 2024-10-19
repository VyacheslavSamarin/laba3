#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
private:
    double x1, y1, x2, y2, x3, y3;

public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    std::pair<double, double> center() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
    double area() const override;

    Triangle* clone() const override;
    Triangle* move() override;

    bool operator==(const Figure& other) const override;
};

#endif