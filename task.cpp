#include <cmath>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <unordered_map>
#include <vector>

int det(int n, std::vector<std::vector<double>> matrix) {
  const double eps = 0.000000001;
  double det = 1;
  for (int i = 0; i < n; ++i) {
    int k = i;
    for (int j = i + 1; j < n; ++j) {
      if (std::abs(matrix[k][i]) < std::abs(matrix[j][i])) {
        k = j;
      }
    }
    if (std::abs(matrix[k][i]) < eps) {
      det = 0;
      break;
    }
    std::swap(matrix[i], matrix[k]);
    if (i != k)
      det = -det;
    det *= matrix[i][i];
    for (int j = i + 1; j < n; ++j)
      matrix[i][j] /= matrix[i][i];
    for (int j = 0; j < n; ++j)
      if (j != i && std::abs(matrix[j][i]) > eps)
        for (int k = i + 1; k < n; ++k)
          matrix[j][k] -= matrix[i][k] * matrix[j][i];
  }
  return det;
}
void find_ans(int n, std::vector<std::vector<double>>& matrix) {

}

int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<double>> matrix(n, std::vector<double>(n));
  int temp;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }
  find_ans(n, matrix);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << matrix[i][j] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}
