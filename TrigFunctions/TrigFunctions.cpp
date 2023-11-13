//
//  main.cpp
//  1136_Labs
//
//  Created by Danyal Rehan on 9/25/22.
//

#include <iostream>
#include <math.h>
#include <iomanip>

int main(int argc, const char * argv[]) {
    double degrees;
    double pi;
    double radian;
    pi = 3.14159265358979323846;
    std::cout << "Enter the angle in degree form: \n";
    std::cin >> degrees;
    radian = degrees * (pi/180);
    std::cout << "sine(" << radian << ") = " << sin(radian) << std::endl;
    std::cout << "cosine(" << radian << ") = " << cos(radian) << std::endl;
    std::cout << "tangent(" << radian << ") = " << tan(radian) << std::endl;
    return 0;
}
