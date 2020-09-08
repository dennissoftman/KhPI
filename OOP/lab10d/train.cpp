#include "train.hpp"

Train::Train()
    : Train("", 0, 0)
{

}

Train::Train(const std::string &_dest, int _t_id, hm_t _d_time)
{
    dest = _dest;
    t_id = _t_id;
    d_time = _d_time;
}

void Train::SetDest(const std::string &_dest)
{
    dest = _dest;
}

void Train::SetTID(int _t_id)
{
    t_id = _t_id;
}

void Train::SetDT(hm_t _d_time)
{
    d_time = _d_time;
}

const std::string &Train::GetDest() const
{
    return dest;
}

int Train::GetTID() const
{
    return t_id;
}

hm_t Train::GetDT() const
{
    return d_time;
}

std::string Train::GetInfo() const
{
    int mins  = d_time & 0x3F;
    int hours = (d_time & 0x7C0) >> 6;

    return std::string("Train №" + std::to_string(t_id) +
                       " going to " + dest +
                       " departure at " + std::to_string(hours) +
                       ":" + (mins<10?"0":"") + std::to_string(mins));
}
