#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <vector>

#include "Event.h"
#include "Validate.h"

TEST(ValidatorTest, ValidEvent)
{
    Event event{
        "2026-01-01",
        42.0,
        -73.0,
        "LOGIN",
        "HIGH"
    };

    const auto errors = validateEvent(event);

    EXPECT_TRUE(errors.empty());
}

TEST(ValidatorTest, InvalidLatitude)
{
    Event event{"2026-01-01", 100.0, -73.0, "LOGIN", "HIGH"};

    const auto errors = validateEvent(event);

    ASSERT_EQ(errors.size(), 1);
    EXPECT_NE(errors[0].find("Invalid latitude"), std::string::npos);
}

TEST(ValidatorTest, InvalidLongitude)
{
    Event event{"2026-01-01", 42.0, 200.0, "LOGIN", "HIGH"};

    const auto errors = validateEvent(event);

    ASSERT_EQ(errors.size(), 1);
    EXPECT_NE(errors[0].find("Invalid longitude"), std::string::npos);
}

TEST(ValidatorTest, InvalidLatitudeAndLongitude)
{
    Event event{"2026-01-01", 100.0, 200.0, "LOGIN", "HIGH"};

    const auto errors = validateEvent(event);

    ASSERT_EQ(errors.size(), 2);

    EXPECT_NE(
        std::find_if(errors.begin(), errors.end(), [](const std::string& error) {
            return error.find("Invalid latitude") != std::string::npos;
        }),
        errors.end()
    );

    EXPECT_NE(
        std::find_if(errors.begin(), errors.end(), [](const std::string& error) {
            return error.find("Invalid longitude") != std::string::npos;
        }),
        errors.end()
    );
}

TEST(ValidatorTest, ReportsAllInvalidFields)
{
    Event event{
        "",
        100.0,
        200.0,
        "",
        "EXTREME"
    };

    const auto errors = validateEvent(event);

    ASSERT_EQ(errors.size(), 5);

    EXPECT_NE(std::find_if(errors.begin(), errors.end(), [](const auto& error) {
        return error.find("Invalid latitude") != std::string::npos;
    }), errors.end());

    EXPECT_NE(std::find_if(errors.begin(), errors.end(), [](const auto& error) {
        return error.find("Invalid longitude") != std::string::npos;
    }), errors.end());

    EXPECT_NE(std::find_if(errors.begin(), errors.end(), [](const auto& error) {
        return error.find("Invalid severity") != std::string::npos;
    }), errors.end());

    EXPECT_NE(std::find_if(errors.begin(), errors.end(), [](const auto& error) {
        return error.find("Event type was not entered") != std::string::npos;
    }), errors.end());

    EXPECT_NE(std::find_if(errors.begin(), errors.end(), [](const auto& error) {
        return error.find("Timestamp was not entered") != std::string::npos;
    }), errors.end());
}