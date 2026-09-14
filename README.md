# Data Engine

A C++ command-line data processing application designed to load, filter, and analyze event datasets efficiently.

The project is being developed as a hands-on exploration of modern C++ software development, with an emphasis on clean architecture, data processing, testing, build systems, and performance.

## Current Features

### Data Processing

* Load event data from CSV files
* Process datasets using C++ data structures
* Display event records

### Filtering

* Filter events by severity
* Filter events by event type
* Filter numeric fields such as latitude and longitude
* Support comparison operators including `=`, `!=`, `>`, `<`, `>=`, and `<=`

### Statistics

* Calculate total number of events
* Calculate average latitude
* Calculate average longitude
* Count events by severity
* Count events by event type
* Calculate statistics on filtered datasets

### Using the Makefile

The Makefile provides commands for building, running, and cleaning the application:

```bash
make build
make run ARGS="--stats"
make clean
```

Use `ARGS` to pass command-line options to the application when running it.

### Command-Line Interface

The application supports command-line operations for interacting with the dataset.

Example:

```bash
make run ARGS="--stats"
```

Filter events:

```bash
make run ARGS="--filter severity = HIGH"
```

Filter events and calculate statistics:

```bash
make run ARGS="--filter severity = HIGH --stats"
```

## Example Output

```text
Filtered events: 37

Statistics
----------
Total Events: 37
Average Latitude: 42.651
Average Longitude: -73.756

Severity:
  HIGH: 37

Event Types:
  FIRE: 18
  FLOOD: 12
  STORM: 7
```

## Project Structure

```text
Data-Engine/
├── Event.h
├── Filter.h
├── Statistics.h
├── Event.cpp
├── Filter.cpp
├── Statistics.cpp
├── main.cpp
└── events.csv
```

## Technologies

* **C++**
* **Standard Template Library (STL)**
* **Git / GitHub**
* **CSV Data Processing**

Additional development tools and technologies will be introduced as the project evolves.

## Project Goals

The long-term goal of this project is to develop a more complete C++ data processing system while gaining practical experience with software engineering concepts.

Planned areas of development include:

* Input validation
* Unit testing with GoogleTest
* CMake build configuration
* Continuous Integration with GitHub Actions
* Performance benchmarking
* Large dataset processing
* Multithreaded processing
* Improved command-line argument handling
* Cross-platform development considerations

## Motivation

This project was created as a hands-on way to strengthen my C++ development skills and gain experience designing, building, testing, and improving a software application from the ground up.


## Status

**In active development.**

The current version supports CSV data loading, filtering, statistics, and command-line operations. Additional validation, testing, build automation, and performance features will be added as development continues.
