#include "Statistics.h"
#include <map>
#include <iostream>
using std::cout;
using std::map;
using std::endl;


int totalEvents( const vector<Event>& events){
    return events.size();


};

 double averageLatitude(const vector<Event>& events){
    double sum=0;
    for(auto const &e :events){
       sum= sum+ e.latitude;
    }
    return sum/events.size();
 };

 double averageLongitude( const vector<Event>& events){
    double sum=0;
    for(auto const &e :events){
       sum= sum+ e.longitude;
    }
    return sum/events.size();
 };

 map<string,int> countBySeverity(const vector<Event>& events){
   map<string,int> severities;
   for(auto const &e:events){
       severities[e.severity]++;
    }
    
   return severities;
 };

map<string,int>  numberOfEventTypes(const vector<Event>&events){
    map<string,int> eventTypes;
    for(auto const &e:events){
       eventTypes[e.event_type]++;
    }
    return eventTypes;
 };

 void printStats(const vector<Event>&events){
    cout << "Statistics\n";
        cout << "----------\n";

        cout << "Total Events: "
             << totalEvents(events) << endl;

        cout << "Average Latitude: "
             << averageLatitude(events) << endl;

        cout << "Average Longitude: "
             << averageLongitude(events) << endl;

        map<string, int> eventTypes =
            numberOfEventTypes(events);

        map<string, int> severities =
            countBySeverity(events);

        cout << "\nSeverity:\n";

        for (const auto& [severity, count] : severities)
        {
            cout << "  " << severity << ": "
                 << count << endl;
        }

        cout << "\nEvent Types:\n";

        for (const auto& [eventType, count] : eventTypes)
        {
            cout << "  " << eventType << ": "
                 << count << endl;
        }

 };