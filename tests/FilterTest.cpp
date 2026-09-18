#include <gtest/gtest.h>
#include "Filter.h"
#include "Event.h"
#include <vector>

TEST(FilterTests, HighSeverityFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "severity", "=", "HIGH");

    EXPECT_EQ(result.size(), 2);
}

TEST(FilterTests, NotHighSeverityFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "severity", "!=", "HIGH");

    EXPECT_EQ(result.size(), 1);
}

TEST(FilterTests, LowSeverityFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "severity", "=", "LOW");

    EXPECT_EQ(result.size(), 1);
}

TEST(FilterTests, LatitudeFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "latitude", ">", "43");

    EXPECT_EQ(result.size(), 1);
}

TEST(FilterTests, LongitudeFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "longitude", ">", "-74");

    EXPECT_EQ(result.size(), 1);
}

TEST(FilterTests, EventTypeFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "event_type", "=", "LOGIN");

    EXPECT_EQ(result.size(), 2);
}

TEST(FilterTests, NoReturnFilter)
{
    std::vector<Event> events =
    {
        {"2026-01-01", 42.0, -73.0, "LOGIN", "HIGH"},
        {"2026-01-02", 43.0, -74.0, "LOGIN", "LOW"},
        {"2026-01-03", 44.0, -75.0, "LOGOUT", "HIGH"}
    };

    std::vector<Event> result =
        filter(events, "severity", "=", "EXTREME");

    EXPECT_EQ(result.size(), 0);
}



