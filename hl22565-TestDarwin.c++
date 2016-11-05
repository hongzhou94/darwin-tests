// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ----
// test
// ----
Species rover('r');
Species food('f');
Species trap('t');
Species hopper('h');
Species xx('x');
Species z();

TEST(DarwinFixture, test) {
  Creature rover1(0, 0, rover, 0, 0, 0);
  ASSERT_TRUE(rover1.specie.type == 'r');
}
TEST(DarwinFixture, test1) {
  Creature rover2(0, 0, rover, 0, 0, 0);
  ASSERT_TRUE(rover2.pc == 0);
}
TEST(DarwinFixture, test2) {
  Creature rover3(0, 0, rover, 0, 0, 0);
  ASSERT_TRUE(rover3.direction == 0);
}
TEST(DarwinFixture, test3) {
  Creature rover4(0, 0, rover, 0, 0, 0);
  ASSERT_TRUE(rover4.width == 0);
}
TEST(DarwinFixture, test4) {
  Creature rover5(0, 0, rover, 0, 0, 0);
  ASSERT_TRUE(rover5.height == 0);
}
TEST(DarwinFixture, test5) {
  Creature food1(0, 0, food, 0, 0, 0);
  ASSERT_TRUE(food1.specie.type == 'f');
}
TEST(DarwinFixture, test6) {
  Creature food1(1, 2, food, 3, 4, 5);
  ASSERT_TRUE(food1.direction == 3);
}
TEST(DarwinFixture, test7) {
  hopper.addInstruction("hop");
  Creature hopper1(0, 0, hopper, 0, 0, 0);
  ASSERT_TRUE(hopper1.specie.instructions[0].compare("hop") == 0);
}
TEST(DarwinFixture, test8) {
  hopper.addInstruction("left");
  hopper.addInstruction("right");
  Creature hopper1(0, 0, hopper, 0, 0, 0);
  ASSERT_TRUE(hopper1.specie.instructions[2].compare("right") == 0);
}
TEST(DarwinFixture, test9) {
  hopper.addInstruction("left");
  hopper.addInstruction("infect");
  Creature hopper1(0, 0, hopper, 0, 0, 0);
  ASSERT_TRUE(hopper1.specie.instructions[4].compare("infect") == 0);
}
TEST(DarwinFixture, test10) {
  Darwin d1(10, 10);
  Creature hopper1(10, 10, hopper, 0, 0, 0);
  d1.addCreature(0, 0, hopper1);
  ASSERT_TRUE(hopper1.height == 10);
}
TEST(DarwinFixture, test11) {
  Darwin d1(10, 10);
  Creature hopper1(10, 10, hopper, 0, 0, 0);
  d1.addCreature(0, 0, hopper1);
  ASSERT_TRUE(hopper1.width == 10);
}
TEST(DarwinFixture, test12) {
  Darwin d1(10, 10);
  Creature hopper1(10, 10, hopper, 0, 0, 0);
  d1.addCreature(0, 0, hopper1);
  ASSERT_TRUE(hopper1.creature_height == 0);
}
TEST(DarwinFixture, test13) {
  Darwin d1(10, 10);
  Creature hopper1(10, 10, hopper, 0, 0, 0);
  d1.addCreature(0, 0, hopper1);
  ASSERT_TRUE(hopper1.creature_width == 0);
}
