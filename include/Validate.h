# pragma once
#include <string>
#include "Event.h"
using std::string;

bool validLatitude(double latitude);

bool validLongitude(double longitude);

bool validSeverity(const string& severity);

bool validEvent(const Event& event);

bool allFields(const Event& event);
