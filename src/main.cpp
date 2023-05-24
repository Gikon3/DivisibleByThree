#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <sstream>
#include "divisibleByThreeResolve.h"

#if !defined(SEED)
#define SEED    0
#endif

#if !defined(N_TESTS)
#define N_TESTS 5
#endif

#define MAX_SIZE    static_cast<long>(1e9)
#define MAX_VALUE   99
#define USER_TESTS  0

static void test(const std::vector<int>& m, long answer);
static std::vector<int> genM(std::mt19937& engine);
static std::ostream& operator<<(std::ostream& os, const std::vector<int>& m);

int main()
{
#if SEED == 0
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
#else
    auto seed = SEED;
#endif
    std::mt19937 engine(seed);

#if USER_TESTS == 1
    test({ 3, 1, 2, 3, 1 }, 3);
    test({ 1, 1, 1, 1, 1, 2, 2 }, 3);
    test({ 1, 5, 4, 3, 9, 1, 8, 7 }, 4);
    test({ 13, 4, 12, 8, 10, 5, 4, 4 }, 4);
    test({ 12, 9, 5, 13, 7 }, 3);
#endif

    for (int i = 0; i < N_TESTS; ++i) {
        const std::vector<int> m = genM(engine);
        test(m, -1);
    }

    std::cout << "Seed: " << seed << std::endl;

    return 0;
}

static void test(const std::vector<int>& m, long answer)
{
    auto begin = std::chrono::steady_clock::now();
    const long result = divisibleByThreeResolve(m);
    auto end = std::chrono::steady_clock::now();
    const long timeMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();

    std::stringstream ss;
    if (m.size() > 10)
        ss << "Size:\t" << m.size() << "\n";
    else
        ss << "M:\t" << m << "\n";
    if (result == answer)
        ss << answer << " == " << result << "\t++++++++++\n";
    else
        ss << answer << " != " << result << "\t----------\n";
    ss << "Time: " << timeMs << " ms\n\n";

    std::cout << ss.str();


    //std::cout << "Size:\t" << m.size() << std::endl <<
    //    "Ref:\t" << answer << std::endl <<
    //    "Result:\t" << result << (result == answer ? " OK" : " ERROR") << std::endl <<
    //    "Time:\t" << timeMs << " ms" << std::endl;
    //if (m.size() < 10)
    //    std::cout << "M:\t" << m << std::endl;
    //std::cout << std::endl;
}

static std::vector<int> genM(std::mt19937& engine)
{
    const long size = 1 + engine() % MAX_SIZE;
    std::vector<int> m;
    for (long i = 0; i < size; ++i)
        m.push_back(engine() % MAX_VALUE);
    return m;
}

static std::ostream& operator<<(std::ostream& os, const std::vector<int>& m)
{
    for (const auto val : m)
        os << val << " ";
    return os;
}
