#pragma once

#include "Event.h"
#include <string>
#include <vector>
#include "Event.h"
using namespace std;




bool compareStrings(const string& eventValue,const string& operation,const string& targetValue);

bool compareNumbers(double eventValue,const string& operation,double targetValue);

vector <Event> filter(const vector<Event> &events,const string& field,const string& operation,const string& value);
