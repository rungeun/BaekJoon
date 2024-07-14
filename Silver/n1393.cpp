#include <iostream>
using namespace std;

int main(void) {
    double xs, ys, xe, ye, dx, dy;
    cin >> xs >> ys >> xe >> ye >> dx >> dy;

    // 기울기, 절편
    double m1 = dy / dx;
    double b1 = ye - m1 * xe;
    
    double m2 = -dx / dy;
    double b2 = ys - m2 * xs;

    // 교점
    double x= (b2 - b1) / (m1 - m2);
    double y= m1 * x + b1;

    cout << static_cast<int>(x) << " " << static_cast<int>(y) << endl;

    return 0;
}          