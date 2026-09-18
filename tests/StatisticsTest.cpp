#include <gtest/gtest.h>
#include "Event.h"
#include "Statistics.h"
#include <vector>
#include <map>

TEST(StatisticsTest, TotalEvents)
{
    std::vector<Event> events = {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}};

    int total = totalEvents(events);

    EXPECT_EQ(total, 3);
}

TEST(StatisticsTest, AverageLatitude)
{
    std::vector<Event> events = {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}};

    double average = averageLatitude(events);

    EXPECT_EQ(average, 43);
}
TEST(StatisticsTest, AverageLongitude)
{
    std::vector<Event> events =
        {
            {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
            {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
            {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}};

    double average = averageLongitude(events);

    EXPECT_EQ(average, -74.0);
}

TEST(StatisticsTest, NumberOfEventTypes)
{
    std::vector<Event> events =
        {
            {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
            {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
            {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}};

    std::map<std::string, int> totalTypes = numberOfEventTypes(events);

    EXPECT_EQ(totalTypes.size(), 2);
    EXPECT_EQ(totalTypes["LOGIN"], 2);
    EXPECT_EQ(totalTypes["LOGOUT"], 1);
}

TEST(StatisticsTest, CountBySeverity)
{
    std::vector<Event> events =
        {
            {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
            {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
            {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}};

    std::map<std::string, int> result = countBySeverity(events);

    EXPECT_EQ(result["HIGH"], 2);
    EXPECT_EQ(result["LOW"], 1);
}

// ====================
// Edge Case Tests
// ====================

TEST(StatisticsTest, TotalEventsEmpty)
{
    std::vector<Event> events;

    int total = totalEvents(events);

    EXPECT_EQ(total, 0);
}

TEST(StatisticsTest, SingleEvent)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"}
    };

    EXPECT_EQ(totalEvents(events), 1);
    EXPECT_EQ(averageLatitude(events), 42.0);
    EXPECT_EQ(averageLongitude(events), -73.0);

    std::map<std::string, int> result = numberOfEventTypes(events);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result["LOGIN"], 1);
}

TEST(StatisticsTest, SameEventType)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGIN", "HIGH"}
    };

    std::map<std::string, int> result = numberOfEventTypes(events);

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result["LOGIN"], 3);
}

TEST(StatisticsTest, SameSeverity)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGOUT", "HIGH"},
        {"2026-01-03", 44.0, -75.0, "LOGIN", "HIGH"}
    };

    std::map<std::string, int> result = countBySeverity(events);

    EXPECT_EQ(result["HIGH"], 3);
}

TEST(StatisticsTest, NegativeCoordinates)
{
    std::vector<Event> events =
    {
        {"2026-01-01", -10.0, -100.0, "LOGIN", "HIGH"},
        {"2026-01-02", -20.0, -120.0, "LOGIN", "LOW"}
    };

    EXPECT_EQ(averageLatitude(events), -15.0);
    EXPECT_EQ(averageLongitude(events), -110.0);
}