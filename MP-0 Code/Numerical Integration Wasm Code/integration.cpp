// integration.cpp
extern "C" {
  double integrate(double a, double b, int n) {
    auto f = [](double x) -> double {
      return 1.0 / (1.0 + x * x); // f(x) = 1 / (1 + x^2)
    };
    double h = (b - a) / n;
    double sum = 0.5 * (f(a) + f(b));
    for (int i = 1; i < n; ++i) {
      sum += f(a + i * h);
    }
    return sum * h;
  }
}
