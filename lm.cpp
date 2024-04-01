#include "lm.h"

using namespace lm;


const float PIrad = PI / 180;

float lm::degrees2radians(float angle)
{
    return angle * PIrad;
}

float lm::radians2degrees(float radians)
{
    return radians / PIrad;
}
