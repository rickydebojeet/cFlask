#!/bin/bash

read -p "Enter the port: " PORT
read -p "Enter the request: " URL_REQ
read -p "Enter the thread pool size: " THREAD_POOL_SIZE

# Different Sizes of concurrent requests
CONCURRENT_REQUESTS='
1
2
3
4
5
6
7
8
9
10
'

# Variables
BENCHMARK_EXECUTABLE="ab"
REQ="100000"
BENCHMARK_CPU="6-15"
URL="http://localhost:"

rm -rf results


# Make directory for results and generate the data file
if [ -d "results" ]; then
    echo "Folder already exists"
else
    mkdir -p results
fi

# Run the benchmark for different Concurrent Requests
for i in $CONCURRENT_REQUESTS
do
    echo "Running benchmark for $i concurrent requests"
    taskset -ac $BENCHMARK_CPU $BENCHMARK_EXECUTABLE -c $i -n $REQ -t 60 "$URL""$PORT""$URL_REQ" > results/loadtest${THREAD_POOL_SIZE}_c${i}.dat 
done

# For each data file, find Requests per second and put the values in a csv file
for i in $CONCURRENT_REQUESTS
do
    echo "Parsing results for $i concurrent requests"
    grep "Requests per second" results/loadtest${THREAD_POOL_SIZE}_c${i}.dat | awk '{print $4}' >> results/results_throughput.csv
    grep '..(mean)' results/loadtest${THREAD_POOL_SIZE}_c${i}.dat | grep "Time" | awk '{print $4}' >> results/results_response_time.csv
done

echo Done!!