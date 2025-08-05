# Sorting Algorithm Evaluation Project

This project benchmarks six sorting algorithms using random test data.

## Algorithms Supported
- Merge Sort
- Quick Sort
- Randomized Quick Sort
- Heap Sort
- Bubble Sort
- Selection Sort

## Project Structure
- `main.cpp` – Main codebase with sorting algorithms and random input generation.
- `Makefile` – Compiles and runs each sorting algorithm using compile-time flags.
- `process_data.sh` – Averages the execution time and memory usage from results.
- `plot.gnuplot` – Generates a comparative plot from the averaged results.
- `results/` – Folder to store raw and processed timing data.
- `plots/` – Folder to store the final PNG plot.

## How to Use

### 1. Compile & Run All Algorithms
```bash
make run ARGS=10000
```
This will:
- Compile six versions of the executable
- Run each of them 5 times
- Collect time and memory usage using `/usr/bin/time`

### 2. Process Results
```bash
bash process_data.sh
```
This will generate `results/avg.csv` with averaged time and memory usage.

### 3. Plot Results
```bash
gnuplot plot.gnuplot
```
This will generate `plots/performance.png`.

### 4. Clean Project
```bash
make clean
```

## Dependencies
- g++
- bash
- GNU `time` (`/usr/bin/time`)
- gnuplot

## Notes
- You can change the number of elements via the `ARGS` parameter.
- Make sure `process_data.sh` is executable: `chmod +x process_data.sh`
