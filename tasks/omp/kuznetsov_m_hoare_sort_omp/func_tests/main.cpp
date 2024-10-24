// Copyright 2024 Kuznetsov Mikhail
#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "../include/hoare_sort_omp.hpp"

using namespace kuznetsov_omp;

TEST(kuznetsov_m_hoare_sort_omp, Const_Array) {
  std::vector<int> inputArray = {6, 3, 2, 0, 5, 1, 9, 7, 4, 8};

  std::vector<int> outputArraySeq(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortSeq = std::make_shared<ppc::core::TaskData>();
  hoareSortSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortSeq->inputs_count.emplace_back(inputArray.size());
  hoareSortSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArraySeq.data()));
  hoareSortSeq->outputs_count.emplace_back(inputArray.size());

  HoareSortSequential hoareSortSequential(hoareSortSeq);
  ASSERT_TRUE(hoareSortSequential.validation());
  hoareSortSequential.pre_processing();
  hoareSortSequential.run();
  hoareSortSequential.post_processing();

  std::vector<int> outputArrayOMP(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortOMP = std::make_shared<ppc::core::TaskData>();
  hoareSortOMP->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortOMP->inputs_count.emplace_back(inputArray.size());
  hoareSortOMP->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArrayOMP.data()));
  hoareSortOMP->outputs_count.emplace_back(inputArray.size());

  HoareSortOMP hoareSortOMPParallel(hoareSortOMP);
  ASSERT_TRUE(hoareSortOMPParallel.validation());
  hoareSortOMPParallel.pre_processing();
  hoareSortOMPParallel.run();
  hoareSortOMPParallel.post_processing();

  ASSERT_EQ(outputArrayOMP, outputArraySeq);
}

TEST(kuznetsov_m_hoare_sort_omp, Random_Array) {
  std::vector<int> inputArray = {593, 834, -590, -483, 329,  -39,  -228, 788, 971,  306, 320, -409, 655, 237,
                                 865, 2,   -740, -619, -530, 819,  4,    387, -642, 772, 103, -644, 843, 587,
                                 314, 952, 870,  93,   309,  -150, 733,  929, -730, 81,  949, -465};

  std::vector<int> outputArraySeq(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortSeq = std::make_shared<ppc::core::TaskData>();
  hoareSortSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortSeq->inputs_count.emplace_back(inputArray.size());
  hoareSortSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArraySeq.data()));
  hoareSortSeq->outputs_count.emplace_back(inputArray.size());

  HoareSortSequential hoareSortSequential(hoareSortSeq);
  ASSERT_TRUE(hoareSortSequential.validation());
  hoareSortSequential.pre_processing();
  hoareSortSequential.run();
  hoareSortSequential.post_processing();

  std::vector<int> outputArrayOMP(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortOMP = std::make_shared<ppc::core::TaskData>();
  hoareSortOMP->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortOMP->inputs_count.emplace_back(inputArray.size());
  hoareSortOMP->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArrayOMP.data()));
  hoareSortOMP->outputs_count.emplace_back(inputArray.size());

  HoareSortOMP hoareSortOMPParallel(hoareSortOMP);
  ASSERT_TRUE(hoareSortOMPParallel.validation());
  hoareSortOMPParallel.pre_processing();
  hoareSortOMPParallel.run();
  hoareSortOMPParallel.post_processing();

  ASSERT_EQ(outputArrayOMP, outputArraySeq);
}

TEST(kuznetsov_m_hoare_sort_omp, Random_Negative_Array) {
  std::vector<int> inputArray = {
      -979, -971, -904, -409, -436, -940, -267, -586, -470, -223, -710, -835, -972, -583, -670, -178, -997,
      -457, -626, -47,  -944, -916, -933, -632, -958, -536, -692, -398, -489, -514, -434, -733, -470, -948,
      -674, -796, -853, -396, -59,  -159, -362, -749, -901, -99,  -733, -967, -243, -795, -676, -513,
  };

  std::vector<int> outputArraySeq(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortSeq = std::make_shared<ppc::core::TaskData>();
  hoareSortSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortSeq->inputs_count.emplace_back(inputArray.size());
  hoareSortSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArraySeq.data()));
  hoareSortSeq->outputs_count.emplace_back(inputArray.size());

  HoareSortSequential hoareSortSequential(hoareSortSeq);
  ASSERT_TRUE(hoareSortSequential.validation());
  hoareSortSequential.pre_processing();
  hoareSortSequential.run();
  hoareSortSequential.post_processing();

  std::vector<int> outputArrayOMP(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortOMP = std::make_shared<ppc::core::TaskData>();
  hoareSortOMP->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortOMP->inputs_count.emplace_back(inputArray.size());
  hoareSortOMP->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArrayOMP.data()));
  hoareSortOMP->outputs_count.emplace_back(inputArray.size());

  HoareSortOMP hoareSortOMPParallel(hoareSortOMP);
  ASSERT_TRUE(hoareSortOMPParallel.validation());
  hoareSortOMPParallel.pre_processing();
  hoareSortOMPParallel.run();
  hoareSortOMPParallel.post_processing();

  ASSERT_EQ(outputArrayOMP, outputArraySeq);
}

TEST(kuznetsov_m_hoare_sort_omp, Single_Array) {
  std::vector<int> inputArray = {634};

  std::vector<int> outputArraySeq(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortSeq = std::make_shared<ppc::core::TaskData>();
  hoareSortSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortSeq->inputs_count.emplace_back(inputArray.size());
  hoareSortSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArraySeq.data()));
  hoareSortSeq->outputs_count.emplace_back(inputArray.size());

  HoareSortSequential hoareSortSequential(hoareSortSeq);
  ASSERT_TRUE(hoareSortSequential.validation());
  hoareSortSequential.pre_processing();
  hoareSortSequential.run();
  hoareSortSequential.post_processing();

  std::vector<int> outputArrayOMP(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortOMP = std::make_shared<ppc::core::TaskData>();
  hoareSortOMP->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortOMP->inputs_count.emplace_back(inputArray.size());
  hoareSortOMP->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArrayOMP.data()));
  hoareSortOMP->outputs_count.emplace_back(inputArray.size());

  HoareSortOMP hoareSortOMPParallel(hoareSortOMP);
  ASSERT_TRUE(hoareSortOMPParallel.validation());
  hoareSortOMPParallel.pre_processing();
  hoareSortOMPParallel.run();
  hoareSortOMPParallel.post_processing();

  ASSERT_EQ(outputArrayOMP, outputArraySeq);
}

TEST(kuznetsov_m_hoare_sort_omp, Empty_Array) {
  std::vector<int> inputArray = {};

  std::vector<int> outputArraySeq(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortSeq = std::make_shared<ppc::core::TaskData>();
  hoareSortSeq->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortSeq->inputs_count.emplace_back(inputArray.size());
  hoareSortSeq->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArraySeq.data()));
  hoareSortSeq->outputs_count.emplace_back(inputArray.size());

  HoareSortSequential hoareSortSequential(hoareSortSeq);
  ASSERT_TRUE(hoareSortSequential.validation());
  hoareSortSequential.pre_processing();
  hoareSortSequential.run();
  hoareSortSequential.post_processing();

  std::vector<int> outputArrayOMP(inputArray.size());

  std::shared_ptr<ppc::core::TaskData> hoareSortOMP = std::make_shared<ppc::core::TaskData>();
  hoareSortOMP->inputs.emplace_back(reinterpret_cast<uint8_t *>(inputArray.data()));
  hoareSortOMP->inputs_count.emplace_back(inputArray.size());
  hoareSortOMP->outputs.emplace_back(reinterpret_cast<uint8_t *>(outputArrayOMP.data()));
  hoareSortOMP->outputs_count.emplace_back(inputArray.size());

  HoareSortOMP hoareSortOMPParallel(hoareSortOMP);
  ASSERT_TRUE(hoareSortOMPParallel.validation());
  hoareSortOMPParallel.pre_processing();
  hoareSortOMPParallel.run();
  hoareSortOMPParallel.post_processing();

  ASSERT_EQ(outputArrayOMP, outputArraySeq);
}