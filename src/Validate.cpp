#include "Validate.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
 

std::vector<std::string> validateEvent(const Event& event)
{
    std::vector<std::string> errors;

    if (event.latitude < -90 || event.latitude > 90) {
        errors.push_back(
            "Invalid latitude: " + std::to_string(event.latitude) +
            " (must be between -90 and 90)\n"
        );
    }

    if (event.longitude < -180 || event.longitude > 180) {
        errors.push_back(
            "Invalid longitude: " + std::to_string(event.longitude) +
            " (must be between -180 and 180)"
        );
    }

    if (event.severity != "LOW" &&
        event.severity != "HIGH" &&
        event.severity != "CRITICAL") {
        errors.push_back(
            "Invalid severity: " + event.severity +
            " (must be LOW, HIGH, or CRITICAL)"
        );
    }

    if (event.event_type.empty()) {
        errors.push_back("Event type was not entered");
    }

    if (event.timestamp.empty()) {
        errors.push_back("Timestamp was not entered");
    }

    return errors;
}