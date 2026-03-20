
#include "ivec2.hpp"

#include <cmath>
#include <cassert>
#include <iostream>




ivec2::ivec2()
    :x(0),y(0)
{}

ivec2::ivec2(int const x_param,int const y_param)
    :x(x_param),y(y_param)
{}

ivec2& operator+=(ivec2& lhs,ivec2 const& rhs)
{
    lhs.x+=rhs.x;
    lhs.y+=rhs.y;
    return lhs;
}

ivec2& operator-=(ivec2& lhs,const ivec2& rhs)
{
    lhs.x-=rhs.x;
    lhs.y-=rhs.y;
    return lhs;
}

ivec2& operator*=(ivec2& v,float const s)
{
    v.x*=s; v.y*=s;
    return v;
}

ivec2& operator/=(ivec2& v,float const s)
{
    assert(fabs(s)>10e-6);
    v.x/=s; v.y/=s;
    return v;
}ivec2& operator*=(ivec2& v,int const s)
{
    v.x*=s; v.y*=s;
    return v;
}

ivec2& operator/=(ivec2& v,int const s)
{
    assert(fabs(s)>10e-6);
    v.x/=s; v.y/=s;
    return v;
}

std::ostream& operator<<(std::ostream& sout,ivec2 const& v)
{
    sout<<"["<<v.x<<";"<<v.y<<"]";
    return sout;
}


int dot(ivec2 const& v0,ivec2 const& v1)
{
    return v0.x*v1.x+v0.y*v1.y;
}



ivec2 operator+(ivec2 const& v0,ivec2 const& v1)
{
    ivec2 temp=v0;
    temp+=v1;
    return temp;
}

ivec2 operator-(ivec2 const& v0,ivec2 const& v1)
{
    ivec2 temp=v0;
    temp-=v1;
    return temp;
}

ivec2 operator*(ivec2 const& v0,float const s)
{
    ivec2 temp=v0;
    temp*=s;
    return temp;
}

ivec2 operator*(float s,ivec2 const& v0)
{
    return v0*s;
}
ivec2 operator*(int s,ivec2 const& v0)
{
    return v0*s;
}

ivec2 operator/(ivec2 const& v0,float const s)
{
    ivec2 temp=v0;temp/=s;
    return temp;
}


