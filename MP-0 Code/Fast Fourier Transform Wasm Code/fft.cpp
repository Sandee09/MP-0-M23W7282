// fft.cpp
#include <cmath>

extern "C" {

void fft(double* real, double* imag, int n) {
  if (n <= 1) return;

  int half = n / 2;

  double* evenReal = new double[half];
  double* evenImag = new double[half];
  double* oddReal  = new double[half];
  double* oddImag  = new double[half];

  for (int i = 0; i < half; ++i) {
    evenReal[i] = real[i * 2];
    evenImag[i] = imag[i * 2];
    oddReal[i]  = real[i * 2 + 1];
    oddImag[i]  = imag[i * 2 + 1];
  }

  fft(evenReal, evenImag, half);
  fft(oddReal, oddImag, half);

  for (int k = 0; k < half; ++k) {
    double angle = -2 * M_PI * k / n;
    double cosA = cos(angle);
    double sinA = sin(angle);

    double tre = cosA * oddReal[k] - sinA * oddImag[k];
    double tim = sinA * oddReal[k] + cosA * oddImag[k];

    real[k]       = evenReal[k] + tre;
    imag[k]       = evenImag[k] + tim;
    real[k+half]  = evenReal[k] - tre;
    imag[k+half]  = evenImag[k] - tim;
  }

  delete[] evenReal;
  delete[] evenImag;
  delete[] oddReal;
  delete[] oddImag;
}
}
