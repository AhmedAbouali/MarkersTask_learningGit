#include "stdio.h"
#include "Markersparser.h"
#include "MarkerManager.h"
#include "Marker.h"
#include <string>
#include <sstream>
#include <iostream>

int main()
{
	std::string something;
	std::cout << "Helloooooooooooooooooooooooooooo\n Please enter something\n";
 Marker M;
 M.type = Marker::Type::DRAWING;
 M.startPosition.x = 0;
 M.startPosition.y = 2;
 M.startPosition.z = 4;
 std::cout<<" Marker type is:\n "+std::to_string(M.type);
 MarkersParser MParser;
 MarkerManager Manager;
 Manager.addMarker(M);
 MParser.parse();

    return 0;
}
