// Marker_Application_1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "stdio.h"
#include "MarkersParser.h"
#include "MarkerManager.h"
#include "Marker.h"
#include <string>
#include <sstream>
#include <iostream>

int _tmain()
{
	MarkerManager Obj_Marker_Manager;
	string s;
	for (int i = 0; i < Obj_Marker_Manager.numMarkers(); i++)
	{
		s = Obj_Marker_Manager.getMarker(i);
		cout << " " + s+"\n";
	}
	cout << "Displayed " + s;
	
	Obj_Marker_Manager.removeMarker();
}

