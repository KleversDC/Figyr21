#include <iostream>

using namespace std;

//class Equation {
//public:
//    virtual ~Equation() = default;
//    virtual void solve() const = 0;
//};
//
//class LinearEquation : public Equation {
//private:
//    double a, b;
//public:
//    LinearEquation(double a, double b) : a(a), b(b) {}
//    void solve() const override {
//        if (a != 0) {
//            cout << "Root: " << -b / a << endl;
//        }
//        else {
//            if (b == 0) {
//                cout << "Infinite solutions" << endl;
//            }
//            else {
//                cout << "No solution" << endl;
//            }
//        }
//    }
//};
//
//class QuadraticEquation : public Equation {
//private:
//    double a, b, c;
//public:
//    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}
//    void solve() const override {
//        double discriminant = b * b - 4 * a * c;
//        if (a == 0) {
//            LinearEquation(b, c).solve();
//        }
//        else if (discriminant > 0) {
//            double root1 = (-b + sqrt(discriminant)) / (2 * a);
//            double root2 = (-b - sqrt(discriminant)) / (2 * a);
//            cout << "Roots: " << root1 << ", " << root2 << endl;
//        }
//        else if (discriminant == 0) {
//            double root = -b / (2 * a);
//            cout << "Root: " << root << endl;
//        }
//        else {
//            cout << "No real roots" << endl;
//        }
//    }
//};
//
//int main() {
//    LinearEquation linear(2, -4);
//    linear.solve();
//
//    QuadraticEquation quadratic(1, -3, 2);
//    quadratic.solve();
//}


class Shape {
public:
    virtual ~Shape() = default;
    virtual void Show() const = 0;
    virtual void Save(ostream& os) const = 0;
    virtual void Load(istream& is) = 0;
};

class Square : public Shape {
private:
    double x, y, side;
public:
    Square(double x, double y, double side) : x(x), y(y), side(side) {}
    void Show() const override {
        cout << "Square: Top Left (" << x << ", " << y << "), Side Length: " << side << endl;
    }
    void Save(ostream& os) const override {
        os << "Square " << x << " " << y << " " << side << endl;
    }
    void Load(istream& is) override {
        is >> x >> y >> side;
    }
};

class Rectangle : public Shape {
private:
    double x, y, width, height;
public:
    Rectangle(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
    void Show() const override {
        cout << "Rectangle: Top Left (" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
    }
    void Save(ostream& os) const override {
        os << "Rectangle " << x << " " << y << " " << width << " " << height << endl;
    }
    void Load(istream& is) override {
        is >> x >> y >> width >> height;
    }
};

class Circle : public Shape {
private:
    double cx, cy, radius;
public:
    Circle(double cx, double cy, double radius) : cx(cx), cy(cy), radius(radius) {}
    void Show() const override {
        cout << "Circle: Center (" << cx << ", " << cy << "), Radius: " << radius << endl;
    }
    void Save(ostream& os) const override {
        os << "Circle " << cx << " " << cy << " " << radius << endl;
    }
    void Load(istream& is) override {
        is >> cx >> cy >> radius;
    }
};

class Ellipse : public Shape {
private:
    double x, y, width, height;
public:
    Ellipse(double x, double y, double width, double height) : x(x), y(y), width(width), height(height) {}
    void Show() const override {
        cout << "Ellipse: Top Left (" << x << ", " << y << "), Width: " << width << ", Height: " << height << endl;
    }
    void Save(ostream& os) const override {
        os << "Ellipse " << x << " " << y << " " << width << " " << height << endl;
    }
    void Load(istream& is) override {
        is >> x >> y >> width >> height;
    }
};

int main() {
    Shape* shapes[4];
    shapes[0] = new Square(0, 0, 5);
    shapes[1] = new Rectangle(1, 1, 4, 3);
    shapes[2] = new Circle(2, 2, 3);
    shapes[3] = new Ellipse(3, 3, 6, 4);

    for (int i = 0; i < 4; ++i) {
        shapes[i]->Show();
    }

    for (int i = 0; i < 4; ++i) {
        delete shapes[i];
    }
}

