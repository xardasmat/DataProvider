#include <iostream>
#include <cmath>
#include "DP.hpp"

class Xd
{
public:
    Xd(const std::string& str)
        : str(str)
    {}
    double operator()(double x, const DPView<>& dp) const
    {
        return x;
    }

    std::string str;
};

class Sqrt
{
public:
    double operator()(double x, const DPView<Xd>& dp) const
    {
        return sqrt(dp.get<Xd>(x));
    }
};

class Sqr
{
public:
    double operator()(double x, const DPView<>& dp) const
    {
        return x*x;
    }
};

class Dist
{
public:
    double operator()(double x, double y, const DPView<Sqr, Sqrt, Xd>& dp) const
    {
        return dp.get<Sqrt>(dp.get<Sqr>(x) + dp.get<Sqr>(y));
    }
};

double calcSqrt(double x, DPView<Xd, Sqrt> dp)
{
    return dp.get<Sqrt>(x);
}

int main(int argc, char** argv)
{
    Sqrt sqrt;
    Sqr sqr;
    Dist dist;
    Xd xd("xD");
    DPView<Sqrt, Sqr, Dist, Xd> dp(sqrt, sqr, dist, xd);
    std::cout << "sqrt 4 = " << dp.get<Sqrt>(4.0) << std::endl;
    std::cout << "sqr 4 = " << dp.get<Sqr>(4.0) << std::endl;
    std::cout << "dist 3 4 = " << dp.get<Dist>(3.0, 4.0) << std::endl;
    std::cout << "calcSqrt 16 = " << calcSqrt(16.0, dp) << std::endl;
    return 0;
}