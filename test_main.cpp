// test_main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"


int _tmain(int argc, _TCHAR* argv[])
{
  printf("Running main() from gtest_main.cc\n");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

