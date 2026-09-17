#include "Validate.h"

bool validLatitude(double latitude){
    return latitude >=-90 && latitude <=90;
};

bool validLongitude(double longitude){
    return longitude >= -180 && longitude <=180;
};

bool validSeverity(const string& severity){
    return severity =="LOW" || severity=="HIGH" ||
    severity =="CRITICAL";
};

bool validEvent(const Event& event){
    return validLatitude(event.latitude) &&
    validLongitude(event.longitude) && 
    validSeverity(event.severity);
};