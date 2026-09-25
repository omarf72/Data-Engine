#include <benchmark/benchmark.h>

#include "Event.h"
#include "Validate.h"
#include <fstream>
#include <string>
#include <vector>
#include "Filter.h"
#include "Statistics.h"


static void BM_LoadEvents(benchmark::State &state)
{
    std::string filename;

    if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    for (auto _ : state)
    {
        std::ifstream file;

        auto events=loadEvents(file,filename);

        benchmark::DoNotOptimize(events);
    }
    state.SetItemsProcessed(state.iterations()*state.range(0));
}

BENCHMARK(BM_LoadEvents)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);

static void BM_FilterBySeverity(benchmark::State& state)
{
    std::string filename;

     if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    // Load the dataset once.
    std::ifstream file;
    std::vector<Event> events = loadEvents(file, filename);

    for (auto _ : state)
    {
        std::vector<Event> result =
            filter(events, "severity", "=", "HIGH");

        benchmark::DoNotOptimize(result);
    }

    state.SetItemsProcessed(
        state.iterations() * state.range(0)
    );
}

BENCHMARK(BM_FilterBySeverity)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);

static void BM_FilterByEventType(benchmark::State& state)
{
    std::string filename;

     if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    // Load the dataset once.
    std::ifstream file;
    std::vector<Event> events = loadEvents(file, filename);

    for (auto _ : state)
    {
        std::vector<Event> result =
            filter(events, "event_type", "=", "LOGIN");

        benchmark::DoNotOptimize(result);
    }

    state.SetItemsProcessed(
        state.iterations() * state.range(0)
    );
}

BENCHMARK(BM_FilterByEventType)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);

static void BM_FilterByLatitude(benchmark::State& state)
{
    std::string filename;

     if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    // Load the dataset once.
    std::ifstream file;
    std::vector<Event> events = loadEvents(file, filename);

    for (auto _ : state)
    {
        std::vector<Event> result =
            filter(events, "latitude", ">", "43");

        benchmark::DoNotOptimize(result);
    }

    state.SetItemsProcessed(
        state.iterations() * state.range(0)
    );
}

BENCHMARK(BM_FilterByLatitude)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);

static void BM_FilterByLongitude(benchmark::State& state)
{
    std::string filename;

     if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    // Load the dataset once.
    std::ifstream file;
    std::vector<Event> events = loadEvents(file, filename);

    for (auto _ : state)
    {
        std::vector<Event> result =
            filter(events, "longitude", ">", "87");

        benchmark::DoNotOptimize(result);
    }

    state.SetItemsProcessed(
        state.iterations() * state.range(0)
    );
}

BENCHMARK(BM_FilterByLongitude)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);



static void BM_Statistics(benchmark::State& state)
{
    std::string filename;

     if (state.range(0) == 1000)
        filename = "data/events_1k.csv";
    else if (state.range(0) == 10000)
        filename = "data/events_10k.csv";
    else if (state.range(0) == 100000)
        filename = "data/events_100k.csv";

    // Load the dataset once.
    std::ifstream file;
    std::vector<Event> events = loadEvents(file, filename);

    for (auto _ : state)
    {
        int total = totalEvents(events);
        double latitude = averageLatitude(events);
        double longitude = averageLongitude(events);
        auto eventTypes = numberOfEventTypes(events);
        auto severities = countBySeverity(events);

        benchmark::DoNotOptimize(total);
        benchmark::DoNotOptimize(latitude);
        benchmark::DoNotOptimize(longitude);
        benchmark::DoNotOptimize(eventTypes);
        benchmark::DoNotOptimize(severities);
    }

    state.SetItemsProcessed(
        state.iterations() * state.range(0)
    );
}

BENCHMARK(BM_Statistics)
    ->Arg(1000)
    ->Arg(10000)
    ->Arg(100000);

BENCHMARK_MAIN();