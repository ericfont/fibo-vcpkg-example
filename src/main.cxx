#include <cxxopts.hpp>
#include <fmt/format.h>
#include <range/v3/view.hpp>
#include <cstdint>

namespace view = ranges::views;

uintmax_t fib(uintmax_t x) {
  uintmax_t a = 0, b = 1;

  for (int it : view::repeat(0) | view::take(x)) {
    (void)it;
    uintmax_t tmp = a;
    a += b;
    b = tmp;
  }

  return a;
}

int main(int argc, char** argv) {
  cxxopts::Options options("fibo", "Print the fibonacci sequence up to a value 'n'");
    options.add_options()
      ("n,value", "The value to print to", cxxopts::value<uintmax_t>()->default_value("1000"));

  uintmax_t max = UINTMAX_MAX / 2;
  auto result = options.parse(argc, argv);
  auto n = result["value"].as<uintmax_t>();

  for (int x : view::iota(1) | view::take(n)) {
    if (fib(x) > max) {
      fmt::print("exceeded maximum for uintmax_t / 2 = {}.\n", max);
      break;
    }
    fmt::print("fib({}) = {}\n", x, fib(x));
  }
}
