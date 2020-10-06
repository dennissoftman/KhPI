#include "deltatime.hpp"
#include <cmath>

DeltaTime::DeltaTime()
{

}

void DeltaTime::SetHours(int h)
{
    int secs = d_time % 60;
    int mins = (d_time / 60) % 60;
    d_time = secs + mins * 60 + (h%24) * 3600;
}

void DeltaTime::SetMinutes(int m)
{
    int secs  = d_time % 60;
    int hours = (d_time / 3600) % 24;
    d_time = secs + (m%60) * 60 + hours * 3600;
}

void DeltaTime::SetSeconds(int s)
{
    int mins  = (d_time / 60) % 60;
    int hours = (d_time / 3600) % 24;
    d_time = s%60 + mins*60 + hours*3600;
}

std::string DeltaTime::GetTime() const
{
    int secs  =  d_time % 60;
    int mins  = (d_time / 60) % 60;
    int hours = (d_time / 3600) % 24;

    return (hours< 10 ? "0" : "") + std::to_string(hours) + ":" +
           (mins < 10 ? "0" : "") + std::to_string(mins) + ":" +
            (secs < 10 ? "0" : "") + std::to_string(secs);
}

float DeltaTime::GetAngle() const
{
    int mins  = (d_time / 60) % 60;
    int hours = (d_time / 3600) % 12;
    return fabs(mins * 6.f - hours * 30.f);
}

DeltaTime DeltaTime::operator -(const DeltaTime &other) const
{
    DeltaTime t;
    t.d_time = (d_time>other.d_time?d_time-other.d_time:other.d_time-d_time);
    return t;
}

bool DeltaTime::operator >(const DeltaTime &other) const
{
    return (d_time > other.d_time);
}

bool DeltaTime::operator >=(const DeltaTime &other) const
{
    return (d_time >= other.d_time);
}

bool DeltaTime::operator <(const DeltaTime &other) const
{
    return (d_time < other.d_time);
}

bool DeltaTime::operator <=(const DeltaTime &other) const
{
    return (d_time <= other.d_time);
}

bool DeltaTime::operator ==(const DeltaTime &other) const
{
    return (d_time == other.d_time);
}
