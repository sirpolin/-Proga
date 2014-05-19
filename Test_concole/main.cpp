#include <QCoreApplication>
#include <QApplication>
#include <QPixmap>
#include <QFile>
#include <QPicture>
#include <QPainter>
#include <QPen>
#include <QSize>
#include <vector>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

const int IN_POINT = -102;
const int IN_ORB = -102;
const int IN_SPHERE = -102;

double converter (double & old_value, double & min_value, double & max_value) {
    return (old_value  - min_value)/ (max_value - min_value);
}

int getSqrDistance(const int x1, const int y1, const int x2, const int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}


double getDistance(const int x1, const int y1, const int x2, const int y2) {
    return sqrt(getSqrDistance(x1, y1, x2, y2));
}

class Primitiv {
public:
    virtual double getField(const int, const int) const = 0;
    virtual void read() = 0;
    virtual bool isInside(const int, const int) const = 0;
};

class Point : Primitiv {
public:
    virtual double getField(const int x_, const int y_) const {
        return q / getDistance(x, y, x_, y_);
    }

    virtual void read() {
        cin >> q >> x >> y;
    }

    virtual bool isInside(const int x_, const int y_) const {
        return (x == x_) && (y == y_);
    }
private:
    int x, y;
    double q;
};

class Sphere : Primitiv {
public:
    virtual double getField(const int x_, const int y_) const {
        return q / getDistance(x, y, x_, y_);
    }

    virtual void read() {
        cin >> q >> r >> x >> y;
    }

    virtual bool isInside(const int x_, const int y_) const {
        return r * r >= getSqrDistance(x, y, x_, y_);
    }
private:
    int x, y, r;
    double q;
};


class Orb : Primitiv {
public:
    virtual double getField(const int x_, const int y_) const {
        return q / getDistance(x, y, x_, y_);
    }

    virtual void read() {
        cin >> q >> r >> x >> y;
    }

    virtual bool isInside(const int x_, const int y_) const {
        return r * r >= getSqrDistance(x, y, x_, y_);

    }
private:
    int x, y, r;
    double q;
};

int main(int argc, char *argv[]) {
    //Kulibaba A. V.

    vector<Point> points;
    vector<Sphere> spheres;
    vector<Orb> orbs;
    size_t pointsNumber, spheresNumber, orbsNumber;
    cout << "Input number and properties of point charges (q, x, y)" << endl;
    cin >> pointsNumber;
    points.resize(pointsNumber);
    for (unsigned int i = 0; i < pointsNumber; ++i) {
        points[i].read();
    }
    cout << "Input number and properties of circles (q, r, x, y)" << endl;
    cin >> orbsNumber;
    orbs.resize(orbsNumber);
    for (unsigned int i = 0; i < orbsNumber; ++i) {
        orbs[i].read();
    }
    cout << "Input number and properties of spheres (q, r, x, y)" << endl;
    cin >> spheresNumber;
    spheres.resize(spheresNumber);
    for (unsigned int i = 0; i < spheresNumber; ++i) {
        spheres[i].read();
    }

    int xSize, ySize;
    cout << "Input size of field (x, y)" << endl;
    cin >> xSize >> ySize;

    double ** result = new double * [xSize];
    for (int i = 0; i < xSize; ++i)
        result[i] = new double[ySize];

    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {
            result[x][y] = 0;

            for (unsigned int k = 0; k < points.size(); ++k) {
                result[x][y] += points[k].getField(x, y);
            }

            for (unsigned int k = 0; k < orbs.size(); ++k) {

                result[x][y] += orbs[k].getField(x, y);
            }

            for (unsigned int k = 0; k < spheres.size(); ++k) {
                result[x][y] += spheres[k].getField(x, y);
            }
        }
    }

    int c;
    cout << "Input multiplicity of charge" << endl;
    cin >> c;


    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {
            result[x][y] = (int)result[x][y] / c;
        }
    }

    for (int x = 0; x < xSize; ++x) {
        for (int y = 0; y < ySize; ++y) {

            for (unsigned int k = 0; k < points.size(); ++k) {
                if (points[k].isInside(x, y)) {
                    result[x][y] = IN_POINT;
                }
            }

            for (unsigned int k = 0; k < orbs.size(); ++k) {
                if (orbs[k].isInside(x, y)) {
                    result[x][y] = IN_ORB;
                }
            }

            for (unsigned int k = 0; k < spheres.size(); ++k) {
                if (spheres[k].isInside(x, y)) {
                    result[x][y] = IN_SPHERE;
                }
            }
        }
    }
    ofstream cout ("output.txt");
    for (int y = 0; y < ySize; ++y) {
        for (int x = 0; x < xSize; ++x) {
            cout << setw(4) << result[x][y];
        }
        cout << endl;
    }

    // Polin O. A.

    double min = result[0][0], max = result[0][0];
    for (int i = 0; i < xSize; ++i)
        for (int j = 0; j < ySize; ++j) {
            if (result[i][j] < min)
                min = result[i][j];
            if (result[i][j] > max)
                max = result[i][j];
        }
    //QCoreApplication a(argc, argv);
    QApplication a(argc, argv);
    QPixmap pic (xSize, ySize);
    QPainter painter;
    painter.begin(&pic);
    QPen pen (Qt::red,1,Qt::SolidLine);
    QColor my_color;

    for (int i = 0; i < xSize; ++i)
        for (int j = 0; j < ySize; ++j) {
            my_color.setHslF(converter(result[i][j], min, max), 1, 0.75);
            pen.setColor(my_color);
            painter.setPen(pen);
            painter.drawPoint(i, j);
        }

    painter.end();
    QFile file("picture.png");
    file.open(QIODevice::WriteOnly);
    pic.save(&file, "PNG");
    return 0;
}
