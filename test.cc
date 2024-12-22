#include "emscripten.h"

#include <unordered_map>

extern "C" {

// WASM doesn't like uint64_t, so an ugly workaround is to use double instead.
double EMSCRIPTEN_KEEPALIVE fibonacci(double idx) {
    static std::unordered_map<double, double> cache{};

    if (auto iter = cache.find(idx); iter != cache.end()) {
        return iter->second;
    } else if (idx < 0) {
        if (cache.find(idx) == cache.end()) {
            cache.insert(std::make_pair(idx, 0));
        }
        return 0;
    } else if (idx < 2) {
        if (cache.find(idx) == cache.end()) {
            cache.insert(std::make_pair(idx, 1));
        }
        return 1;
    } else {
        double f_number = fibonacci(idx - 1) + fibonacci(idx - 2);
        if (cache.find(idx) == cache.end()) {
            cache.insert(std::make_pair(idx, f_number));
        }
        return f_number;
    }
}

}
