#include "Filter.h"
#include <string>
#include <vector>

#include <iostream>
using namespace std;

bool compareStrings(const string &eventValue, const string &operation, const string &targetValue)
{
    if (operation == "=")
    {
        return eventValue == targetValue;
    }
    else if (operation == "!=")
    {
        return eventValue != targetValue;
    }
    return false;
};

bool compareNumbers(double eventValue, const string &operation, double targetValue)
{

    if (operation == "=")
    {
        return eventValue == targetValue;
    }
    else if (operation == "!=")
    {
        return eventValue != targetValue;
    }
    else if (operation == ">")
    {
        return eventValue > targetValue;
    }
    else if (operation == "<")
    {
        return eventValue < targetValue;
    }
    else if (operation == ">=")
    {
        return eventValue >= targetValue;
    }
    else if (operation == "<=")
    {
        return eventValue <= targetValue;
    }

    return false;
};

vector<Event> filter(const vector<Event> &events, const string &field, const string &operation, const string &value)
{
    vector<Event> filteredEvents;

    if (field == "severity")
    {
        for (const Event &event : events)
        {

            if (compareStrings(
                    event.severity,
                    operation,
                    value))
            {
                filteredEvents.push_back(event);
            }
        }
    }
    else if (field == "event_type")
    {
        for (const Event &event : events)
        {

            if (compareStrings(
                    event.event_type,
                    operation,
                    value))
            {
                filteredEvents.push_back(event);
            }
        }
    }
    else if (field == "latitude")
    {

        try
        {

            double targetValue = stod(value);

            for (const Event &event : events)
            {

                if (compareNumbers(
                        event.latitude,
                        operation,
                        targetValue))
                {
                    filteredEvents.push_back(event);
                }
            }
        }
        catch (const invalid_argument &)
        {

            cerr << "Error: Invalid latitude value: "
                 << value << endl;
        }
        catch (const out_of_range &)
        {

            cerr << "Error: Latitude value is out of range: "
                 << value << endl;
        }
    }
    else if (field == "longitude")
    {

        try
        {

            double targetValue = stod(value);

            for (const Event &event : events)
            {

                if (compareNumbers(
                        event.longitude,
                        operation,
                        targetValue))
                {
                    filteredEvents.push_back(event);
                }
            }
        }
        catch (const invalid_argument &)
        {

            cerr << "Error: Invalid longitude value: "
                 << value << endl;
        }
        catch (const out_of_range &)
        {

            cerr << "Error: Longitude value is out of range: "
                 << value << endl;
        }
    }
    else
    {

        cerr << "Error: Unknown field: "
             << field << endl;
    }
    return filteredEvents;
}
