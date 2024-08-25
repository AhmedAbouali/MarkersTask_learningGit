#include "MarkerManager.h"
#include "MarkersParser.h"

#include <sstream>
#include <memory>  // For std::unique_ptr
#include <stdexcept>  // For std::out_of_range exception

MarkerManager::MarkerManager()
{
    parser = std::make_unique<MarkersParser>();
    markers = parser->parse();
}

std::string MarkerManager::getMarker(int i)
{
    if (i < 0 || i >= markers.size()) {
        return "Invalid marker index!";
    }

    std::stringstream stream;
    Marker marker = markers.at(i);

    stream << marker.type << " - ";
    stream << "(" << marker.startPosition.x;
    stream << ", " << marker.startPosition.y;
    stream << ", " << marker.startPosition.z << ")";

    return stream.str();
}

int MarkerManager::numMarkers()
{
    return markers.size();
}

bool MarkerManager::addMarker(Marker marker)
{
    markers.push_back(marker);
    return true;  // Successfully added the marker
}

bool MarkerManager::removeMarker()
{
    if (!markers.empty()) {
        markers.pop_back();
        return true;  // Successfully removed the last marker
    }
    return false;  // No markers to remove
}
