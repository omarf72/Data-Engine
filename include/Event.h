#pragma once
#include <fstream>
#include <string>
#include <ostream>
#include <vector>
using std::string;
using std::vector;

struct Event{
    string timestamp;
    double latitude;
    double longitude;
    string event_type;
    string severity;

};

vector<Event> loadEvents(std::ifstream& file, const string& filename);




