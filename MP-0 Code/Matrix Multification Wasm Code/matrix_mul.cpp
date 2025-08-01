extern "C" {
void multiplyMatrix(double* A, double* B, double* C, int size) {
  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      double sum = 0.0;
      for (int k = 0; k < size; ++k) {
        sum += A[i * size + k] * B[k * size + j];
      }
      C[i * size + j] = sum;
    }
  }
}
}
