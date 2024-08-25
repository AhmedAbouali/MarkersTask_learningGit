#include "MarkersParser.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

#define NUM_SAVED_MARKERS 8

const char* SAVED_MARKERS[] = {
    // markerType	positionX	positionY	positionZ
    "0			 10.5		    7		  0.005	\0",
    "1			  0.02          0.1       2.4	\0",
    "1			  2.02          2         3.05	\0",
    "0			  0.02         12         0.0	\0",
    "0			  0.5		   17		  0.005	\0",
    "1			  0.02          4         1.8	\0",
    "0			  0.75         25         1.2	\0",
    "1			  0.02 dddfd         2         7.231	\0",
};

std::vector<Marker> MarkersParser::parse()
{
    std::vector<Marker> parsedMarkers;

    std::string str;
    for (int i = 0; i < NUM_SAVED_MARKERS; ++i)
    {
        const char* markerBuffer = SAVED_MARKERS[i];
        std::stringstream stream;
        stream << markerBuffer;

        Marker marker;
        int markerType;

        // Parse marker type
        if (!(stream >> markerType)) {
            std::cerr << "Error parsing marker type in line " << i + 1 << std::endl;
            continue;  // Skip this entry and continue with the next one
        }
        marker.type = (Marker::Type)markerType;

        // Parse position
        if (!(stream >> marker.startPosition.x >> marker.startPosition.y >> marker.startPosition.z)) {
            std::cerr << "Error parsing position in line " << i + 1 << std::endl;
            continue;  // Skip this entry and continue with the next one
        }

        parsedMarkers.push_back(marker);
    }

    return parsedMarkers;
}

void MarkersParser::save2()
{
    std::cout << "I am at save function";
    // Not implemented yet.
}

void MarkersParser::save(const std::vector<Marker>&)
{
    // Not implemented yet.
}
