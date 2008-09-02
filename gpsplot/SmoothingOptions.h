// $Id$
// Copyright (c) 2008 Oliver Lau <oliver@ersatzworld.net>
// Alle Rechte vorbehalten.

#ifndef __SMOOTHINGOPTIONS_H_
#define __SMOOTHINGOPTIONS_H_

#include <map>
#include <string>

#include "gpslib/Track.h"

typedef std::map<std::string, GPS::Track*> smoothedTrack_t;

struct SmoothingOptions
{
    SmoothingOptions(void) : param(0.0), draw(false)
    { /* ... */ }
    std::string id;
    std::string algorithm;
    std::string gnuplotOption;
    double param;
    bool draw;
};

#endif // __SMOOTHINGOPTIONS_H_
