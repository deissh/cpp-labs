// Кудявцев К. А. ИПБ-20; 3.10 #5

/*
Задача 6.
Сравнить по реальному времени работы алгоритмы линейного поиска,
поиска с барьером и двоичного поиска при разной размерности n случайного массива.
*/
// WARNING
// для бенчмарков использовал https://github.com/google/benchmark
// brew install google-benchmark
// и потом в CMakeLists.txt
//   target_link_libraries(cpp_labs_3_10__6 benchmark::benchmark)

/* output
/Users/deissh/work/RGATU/cpp-labs/cmake-build-debug/cpp_labs_3_10__6
2021-06-06T15:17:52+03:00
Running /Users/deissh/work/RGATU/cpp-labs/cmake-build-debug/cpp_labs_3_10__6
Run on (4 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x2)
  L1 Instruction 32 KiB (x2)
  L2 Unified 256 KiB (x2)
  L3 Unified 3072 KiB (x1)
Load Average: 3.72, 3.38, 3.07
--------------------------------------------------------
Benchmark              Time             CPU   Iterations
--------------------------------------------------------
seekLineBench  139025571 ns    133537000 ns            5
seekBarBench   118075759 ns    116407000 ns            6
seekBinRBench   92364744 ns     91705875 ns            8  <- как и ожидалось, самый быстрый алгоритм
*/

#include <benchmark/benchmark.h>
#include <ctime>
#include <cstdlib>

#define ARR_SIZE 10000000

bool seekLine(int* a, int n, int k, int& ind) {
    ind = 0;
    while (ind < n && a[ind] != k) ind++;

    return ind < n;
}

bool seekBar(int* arr, int n, int k, int& idx) {
    arr[n] = k;
    idx = 0;
    while (arr[idx] != k) idx++;

    return idx < n;
}

bool seekBinR(int* arr, int l, int r, int k, int& idx) {
    idx = (l + r) / 2;
    if (arr[idx] == k) return true;
    else if (l > r) return false;
    else if (arr[idx] < k)
        return seekBinR(arr, idx + 1, r, k, idx);
    else
        return seekBinR(arr, l, idx - 1, k, idx);
}

void randArr(int* arr, int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = rand();
}

// можно закоментировать что бы скомпилировать локально
/// BENCHMARKS
static void seekLineBench(benchmark::State& state) {
    // set random seed
    std::srand(0); // NOLINT(cert-msc51-cpp)

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = new(int[ARR_SIZE]);
        int ind;
        state.ResumeTiming();

        randArr(arr, ARR_SIZE);

        seekLine(arr, ARR_SIZE, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekLineBench);

static void seekBarBench(benchmark::State& state) {
    // set random seed
    std::srand(0); // NOLINT(cert-msc51-cpp)

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = new(int[ARR_SIZE]);
        int ind;
        state.ResumeTiming();

        randArr(arr, ARR_SIZE);

        seekBar(arr, ARR_SIZE, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekBarBench);

static void seekBinRBench(benchmark::State& state) {
// set random seed
    std::srand(0); // NOLINT(cert-msc51-cpp)

    for (auto _ : state) {
        state.PauseTiming();
        int* arr = new(int[ARR_SIZE]);
        int ind;
        state.ResumeTiming();

        randArr(arr, ARR_SIZE);

        seekBinR(arr, ARR_SIZE, ARR_SIZE / 2, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekBinRBench);
/// BENCHMARK end

BENCHMARK_MAIN();