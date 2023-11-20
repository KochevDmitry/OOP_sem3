#include <iostream>
#include "figure.h"

        std::istream& operator>>(std::istream& is, Figure& figure) {
            for (int i = 0; i < figure.angles; i++) {
                is >> figure.points[i].first >> figure.points[i].second;
            }
            return is;
        }

        std::ostream& operator<<(std::ostream& os, Figure *figure) {
            for (int i = 0; i < figure -> angles; i++) {
                os << i + 1 << ": " << figure -> points[i].first << " "<<  figure -> points[i].second <<std::endl;
            }
            return os;
        }

        bool Figure::operator==(const Figure& other) {
            return static_cast<double>(*this) == static_cast<double>(other);
        }

        Figure& Figure::operator=(Figure& other) {
            if (!(this == &other)) {
                for (int i = 0; i < angles; i++) {
                    this->points[i] = other.points[i];
                }
                this->angles = other.angles;
            }
            return *this;                      
        }

        Figure& Figure::operator=(Figure&& other) {
            if (!(this == &other)) {
                for (int i = 0; i < angles; i++) {
                    this->points[i] = std::move(other.points[i]);
                }
                this->angles = other.angles;
                delete[] points;
            }
            return *this;
        }

        std::pair<float, float> Figure::center() {
            float x_sum = 0, y_sum = 0;
            for (int i = 0; i < angles; i++) {
                x_sum += points[i].first;
                y_sum += points[i].second;
            }
            std::pair<float, float> cnt(x_sum / angles, y_sum / angles);
            return cnt;
        }

        

// double orientation(Point& p1, Point& p2, Point& p3) {
//     double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
//     if (val == 0) {
//         return 0;
//     }
//     else if (val > 0) {
//         return 1;
//     }
//     else {
//         return 2;
//     }
// }

// bool Figure::is_correct() {
//     if (n < 3) {
//         return false;
//     }
//     double OrientationVal = orientation(p[0], p[1], p[2]);
//     for (int i = 1; i < n; i++) {
//         int nextIdx = (i + 1) % n;
//         if (OrientationVal != orientation(p[i], p[nextIdx], p[(nextIdx + 1) % n])) {
//             return false;
//         }
//     }
//     return true;
// }
