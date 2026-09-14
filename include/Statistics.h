#pragma once
#include "Event.h"
#include <map>
using std::map;

int totalEvents(const vector<Event>& events);

double averageLatitude(const vector<Event>& events);

double averageLongitude(const vector<Event>& events);

map<string,int> countBySeverity(const vector<Event>& events);

map<string,int>  numberOfEventTypes(const vector<Event>&events);

void printStats(const vector<Event>&events);