import csv 
import random
from datetime import datetime,timedelta
import argparse

random.seed(42)

EVENT_TYPES=[
    "LOGIN",
    "LOGOUT",
    "PURCHASE",
    "ERROR",
    "UPLOAD"
]

SEVERITIES=[
    "LOW",
    "HIGH",
    "CRITICAL"
]

def generate_event(start_time):
    timestamp=start_time + timedelta(
        seconds=random.randint(0,31536000)
    )

    latitude=random.uniform(-90,90)
    longitude=random.uniform(-180,180)

    event_type=random.choice(EVENT_TYPES)
    severity=random.choice(SEVERITIES)


    return[
        timestamp.isoformat(),
        latitude,
        longitude,
        event_type,
        severity
    ]

def generate_csv(filename,number_of_events):

    

    start_time=datetime(2026, 1, 1)

    with open(filename,"w",newline="")as file:
        writer=csv.writer(file)

        writer.writerow([
            "timestamp",
            "latitude",
            "longitude",
            "event_type",
            "severity"
        ])
        for _ in range(number_of_events):
            writer.writerow(
                generate_event(start_time)
            )

def main():
    parser=argparse.ArgumentParser(
        description="Generate event datasets for Data-Engine"
    )

    parser.add_argument(
        "--rows",
        type=int,
        required=True,
        help="Number of events to generate"
    )

    parser.add_argument(
        "--output",
        required=True,
        help="Output CSV filename"
    )

    args=parser.parse_args()

    generate_csv(args.output,args.rows)

    print(
        f"Generated {args.rows} events in {args.output}"
    )

if __name__ == "__main__":
    main()