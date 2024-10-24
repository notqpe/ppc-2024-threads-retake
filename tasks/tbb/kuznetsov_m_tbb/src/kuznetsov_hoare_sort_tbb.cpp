// Copyright 2024 Kuznetsov Mikhail

#include "tbb/kuznetsov_m_hoare_sort_tbb/include/kuznetsov_hoare_sort_tbb.hpp"

#include <algorithm>
#include <random>
#include <thread>

using namespace std::chrono_literals;

bool kuznetsov_tbb::HoareSortSequential::pre_processing() {
  try {
    internal_order_test();
    array.clear();
    for (size_t i = 0; i < taskData->inputs_count[0]; ++i) {
      int *currentElementPtr = reinterpret_cast<int *>(taskData->inputs[0] + i * sizeof(int));
      array.push_back(*currentElementPtr);
    }
  } catch (...) {
    return false;
  }
  return true;
}

bool kuznetsov_tbb::HoareSortSequential::validation() {
  try {
    internal_order_test();
  } catch (...) {
    return false;
  }
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool kuznetsov_tbb::HoareSortSequential::run() {
  try {
    internal_order_test();
    HoareSortSeq(array, 0, array.size() - 1);
  } catch (...) {
    return false;
  }
  return true;
}

bool kuznetsov_tbb::HoareSortSequential::post_processing() {
  try {
    internal_order_test();
    for (size_t i = 0; i < array.size(); ++i) {
      int *currentElementPtr = reinterpret_cast<int *>(taskData->outputs[0] + i * sizeof(int));
      *currentElementPtr = array[i];
    }
  } catch (...) {
    return false;
  }
  return true;
}

void kuznetsov_tbb::HoareSortSequential::HoareSortSeq(std::vector<int> &arr, size_t l, size_t r) {
  if (arr.size() <= 1) return;
  int n = r - l + 1;
  for (int p = 1; p < n; p += p)
    for (int k = p; k > 0; k /= 2)
      for (int j = k % p; j + k < n; j += (k + k))
        for (int i = 0; i < n - j - k; ++i)
          if ((j + i) / (p + p) == (j + i + k) / (p + p))
            if (arr[l + j + i] > arr[l + j + i + k]) std::swap(arr[l + j + i], arr[l + j + i + k]);
}

bool kuznetsov_tbb::HoareSortTBB::pre_processing() {
  try {
    internal_order_test();
    array.clear();
    for (size_t i = 0; i < taskData->inputs_count[0]; ++i) {
      int *currentElementPtr = reinterpret_cast<int *>(taskData->inputs[0] + i * sizeof(int));
      array.push_back(*currentElementPtr);
    }
  } catch (...) {
    return false;
  }
  return true;
}

bool kuznetsov_tbb::HoareSortTBB::validation() {
  try {
    internal_order_test();
  } catch (...) {
    return false;
  }
  return taskData->inputs_count[0] == taskData->outputs_count[0];
}

bool kuznetsov_tbb::HoareSortTBB::run() {
  try {
    internal_order_test();
    HoareSortParallel(array, 0, array.size() - 1);
  } catch (...) {
    return false;
  }
  return true;
}

bool kuznetsov_tbb::HoareSortTBB::post_processing() {
  try {
    internal_order_test();
    if (array.size() != taskData->outputs_count[0]) {
      throw;
    }
    for (size_t i = 0; i < array.size(); ++i) {
      int *currentElementPtr = reinterpret_cast<int *>(taskData->outputs[0] + i * sizeof(int));
      *currentElementPtr = array[i];
    }
  } catch (...) {
    return false;
  }
  return true;
}

void kuznetsov_tbb::HoareSortTBB::HoareSortParallel(std::vector<int> &arr, size_t l, size_t r) {
  if (arr.size() <= 1) return;
  int n = r - l + 1;

  for (int p = 1; p < n; p += p)
    for (int k = p; k > 0; k /= 2)
      for (int j = k % p; j + k < n; j += (k + k))
        oneapi::tbb::parallel_for(oneapi::tbb::blocked_range<int>(0, n - j - k),
                                  [&](oneapi::tbb::blocked_range<int> &R) {
                                    for (int i = R.begin(); i < R.end(); ++i) {
                                      if ((j + i) / (p + p) == (j + i + k) / (p + p))
                                        if (arr[l + j + i] > arr[l + j + i + k])
                                          std::swap(arr[l + j + i], arr[l + j + i + k]);
                                    }
                                  });
}