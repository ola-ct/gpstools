// $Id$
// Copyright (c) 2008 Oliver Lau <oliver@ersatzworld.net>
// Alle Rechte vorbehalten.

#include "Waypoint.h"
#include "Timestamp.h"

#include <cmath>

namespace GPS {

    Waypoint::Waypoint(void)
        : GeoCoord(), _Timestamp(), _HDOP(), _VDOP(), _PDOP()
    { /* ... */ }


    Waypoint::Waypoint(double lon, double lat, DoubleValue ele, Timestamp timestamp)
        : GeoCoord(lon, lat, ele),
        _Timestamp(timestamp),
        _HDOP(), _VDOP(), _PDOP()
    { /* ... */ }

};
