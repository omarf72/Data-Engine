#include <gtest/gtest.h>
#include "Validate.h"
#include "Event.h"

// ====================
// Valid Event Tests
// ====================

TEST(ValidatorTest, ValidEvent)
{
    Event event{
        "2026-01-01",
        42.0,
        -73.0,
        "LOGIN",
        "HIGH"
    };

    EXPECT_TRUE(validEvent(event));
}


// ====================
// Invalid Coordinate Tests
// ====================

TEST(ValidatorTest, InvalidLatitude)
{
    Event event{
        "2026-01-01",
        100.0,
        -73.0,
        "LOGIN",
        "HIGH"
    };

    EXPECT_FALSE(validEvent(event));
}

TEST(ValidatorTest, InvalidLongitude)
{
    Event event{
        "2026-01-01",
        42.0,
        200.0,
        "LOGIN",
        "HIGH"
    };

    EXPECT_FALSE(validEvent(event));
}


// ====================
// Missing Field Tests
// ====================

TEST(ValidatorTest, MissingTimestamp)
{
    Event event{
        "",
        42.0,
        -73.0,
        "LOGIN",
        "HIGH"
    };

    EXPECT_FALSE(validEvent(event));
}

TEST(ValidatorTest, MissingEventType)
{
    Event event{
        "2026-01-01",
        42.0,
        -73.0,
        "",
        "HIGH"
    };

    EXPECT_FALSE(validEvent(event));
}

TEST(ValidatorTest, MissingSeverity)
{
    Event event{
        "2026-01-01",
        42.0,
        -73.0,
        "LOGIN",
        ""
    };

    EXPECT_FALSE(validEvent(event));
}


// ====================
// Invalid Value Tests
// ====================

TEST(ValidatorTest, InvalidSeverity)
{
    Event event{
        "2026-01-01",
        42.0,
        -73.0,
        "LOGIN",
        "EXTREME"
    };

    EXPECT_FALSE(validEvent(event));
}