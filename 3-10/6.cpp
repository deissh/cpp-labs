// Кудявцев К. А. ИПБ-20; 3.10 #5

/*
Задача 6.
Сравнить по реальному времени работы алгоритмы линейного поиска,
поиска с барьером и двоичного поиска при разной размерности n случайного массива.
*/

// warning: я не умею правильно готовить бенчмарки под cpp поэтому вот
// https://quick-bench.com/q/UqJMbIwGAcsCKdbwezDW-jO839o

// импорт для бенчмарков
// https://github.com/google/benchmark
// можно запустить по ссылке выше
#include <benchmark/benchmark.h>
#include <ctime>
#include <cstdlib>

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

bool seekBin(const int* arr, int n, int k, int& idx) {
    int l = 0;
    int r = (n - 1);
    do {
        idx = (l + r) / 2;
        if (arr[idx] < k) l = ++idx;
        else r = --idx;
    } while (l <= r && arr[idx] != k);

    return arr[idx] == k;
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

// можно закоментировать что бы скомпилировать локально
/// BENCHMARKS
static void seekLineBench(benchmark::State& state) {
    int arr[5] = {1, 2, 3, 4, 5};
    int ind;

    for (auto _ : state) {
        seekLine(arr, 5, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekLineBench);

static void seekBarBench(benchmark::State& state) {
    int arr[5] = {1, 2, 3, 4, 5};
    int ind;

    for (auto _ : state) {
        seekBar(arr, 5, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekBarBench);

static void seekBinBench(benchmark::State& state) {
    int arr[5] = {1, 2, 3, 4, 5};
    int ind;

    for (auto _ : state) {
        seekBin(arr, 5, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekBinBench);

static void seekBinRBench(benchmark::State& state) {
    int arr[5] = {1, 2, 3, 4, 5};
    int ind;

    for (auto _ : state) {
        seekBinR(arr, 3, 5, 5, ind);

        benchmark::DoNotOptimize(ind);
        benchmark::DoNotOptimize(arr);
    }
}
BENCHMARK(seekBinRBench);
/// BENCHMARK end

BENCHMARK_MAIN();