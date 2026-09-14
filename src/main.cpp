#include <iostream>
#include <fstream>
#include "Event.h"
#include "Filter.h"
#include "Statistics.h"
#include <map>
using std::cout;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: ./bin/data-engine <csv-file> <command> [arguments]\n"
                  << "Available commands: --filter, --stats, --print-data\n"
                  << "Example: ./bin/data-engine data/events.csv --filter event_type = LOGIN\n";
        return 1;
    }

    std::ifstream file;
    string filename = argv[1];
    vector<Event> events = loadEvents(file, filename);
    string method = argv[2];

    if (method == "--print-data")
    {
        for(const auto& e:events){
            cout << "Timestamp: " << e.timestamp
                 << " | Latitude: " << e.latitude
                 << " | Longitude: " << e.longitude
                 << " | Event Type: " << e.event_type
                 << " | Severity: " << e.severity
                 << endl;
        }
        return 1;
    }

    // -------------------------
    // FILTER
    // -------------------------
    if (method == "--filter")
    {
        if (argc != 6 && argc != 7)
        {
            std::cerr << "Invalid number of arguments for filter.\n"
                      << "Required agruments for filter :\n"
                      << "./bin/data-engine <csv-file> --filter field operation value\n"
                      << "./bin/data-engine <csv-file> --filter field operation value --stats\n"
                      << "Examples: ./bin/data-engine data/events.csv --filter event_type = LOGIN\n"
                      << " ./bin/data-engine data/events.csv --filter event_type = LOGIN --stats\n";

            return 1;
        }

        string field = argv[3];
        string operation = argv[4];
        string value = argv[5];

        vector<Event> filteredEvents =
            filter(events, field, operation, value);

        cout << "Filtered events: "
             << filteredEvents.size() << endl;

        for (const auto &e : filteredEvents)
        {
            cout << "Timestamp: " << e.timestamp
                 << " | Latitude: " << e.latitude
                 << " | Longitude: " << e.longitude
                 << " | Event Type: " << e.event_type
                 << " | Severity: " << e.severity
                 << endl;
        }
        if (argc == 7 && string(argv[6]) == "--stats")
        {
            // calculate stats on filteredEvents
            printStats(filteredEvents);
        }

        return 0;
    }

    // -------------------------
    // STATS
    // -------------------------
    if (method == "--stats")
    {
        printStats(events);
        return 0;
    }

    std::cerr << "Unknown command: " << method << endl;
    return 1;
}
