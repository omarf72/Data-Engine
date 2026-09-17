#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
#include "Event.h"
#include "Validate.h"

vector<Event> loadEvents(std::ifstream& file, const string& filename)
{

    string line;
    vector<Event> events;
    
    

    file.open(filename, std::ios::in);
    if (file.is_open())
    {
        getline(file, line);
        while (getline(file, line))
        {
            std::istringstream ss(line);
            string timestamp, latitude, longitude, event_type, severity;
            if (getline(ss, timestamp, ',') &&
                getline(ss, latitude, ',') &&
                getline(ss, longitude, ',') &&
                getline(ss, event_type, ',') &&
                getline(ss, severity, ','))
            {
                try
                {
                    Event event;

                    event.timestamp = timestamp;
                    event.latitude = stod(latitude);
                    event.longitude = stod(longitude);
                    event.event_type=event_type;
                    event.severity = severity;

                    if(validEvent(event)){
                        std::cout<< "Valid event"<<std::endl;
                        events.push_back(event);
                    }
                    else{
                        std::cout<< "Invalid event"<<std::endl;
                    }

                    
                }
                catch (const std::invalid_argument &e)
                {
                    std::cerr << "Skipping row due to invalid numeric data in line: " << line << "\n";
                }
                catch (const std::out_of_range &e)
                {
                    std::cerr << "Skipping row due to number being too larage or small in line:" << line << "\n";
                }
            }
        }
        file.close();
    }
    else{
        std::cerr << "Error: Could not open " << filename << "\n";
        return events;
    }

    // for (const auto &event : events)
    // {
    //    cout << "Timestamp: " << event.timestamp << " | latitdue: " << event.latitude << " longitude: " << event.longitude << " event type: " << event.event_type << " severity: " << event.severity;
    // }

    return events;

}