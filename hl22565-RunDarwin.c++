// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Darwin.h"

// ----
// main
// ----

int main() {
  using namespace std;

  // ----
  // food
  // ----

  /*
   0: left
   1: go 0
  */
  Species food('f');
  food.addInstruction("left");
  food.addInstruction("go 0");

  // ------
  // hopper
  // ------

  /*
   0: hop
   1: go 0
  */
  Species hopper('h');
  hopper.addInstruction("hop");
  hopper.addInstruction("go 0");

  // -----
  // rover
  // -----

  /*
   0: if_enemy 9
   1: if_empty 7
   2: if_random 5
   3: left
   4: go 0
   5: right
   6: go 0
   7: hop
   8: go 0
   9: infect
  10: go 0
  */
  Species rover('r');
  rover.addInstruction("if_enemy 9");
  rover.addInstruction("if_empty 7");
  rover.addInstruction("if_random 5");
  rover.addInstruction("left");
  rover.addInstruction("go 0");
  rover.addInstruction("right");
  rover.addInstruction("go 0");
  rover.addInstruction("hop");
  rover.addInstruction("go 0");
  rover.addInstruction("infect");
  rover.addInstruction("go 0");

  // ----
  // trap
  // ----

  /*
   0: if_enemy 3
   1: left
   2: go 0
   3: infect
   4: go 0
  */
  Species trap('t');
  trap.addInstruction("if_enemy 3");
  trap.addInstruction("left");
  trap.addInstruction("go 0");
  trap.addInstruction("infect");
  trap.addInstruction("go 0");

  // ----------
  // darwin 8x8
  // ----------

  cout << "*** Darwin 8x8 ***" << endl;
  /*
  8x8 Darwin
  Food,   facing east,  at (0, 0)
  Hopper, facing north, at (3, 3)
  Hopper, facing east,  at (3, 4)
  Hopper, facing south, at (4, 4)
  Hopper, facing west,  at (4, 3)
  Food,   facing north, at (7, 7)
  Simulate 5 moves.
  Print every grid.
  */
  Darwin d(8, 8);

  Creature food1(8, 8, food, 1, 0, 0);
  Creature Hopper1(8, 8, hopper, 0, 3, 3);
  Creature Hopper2(8, 8, hopper, 1, 4, 3);
  Creature Hopper3(8, 8, hopper, 2, 4, 4);
  Creature Hopper4(8, 8, hopper, 3, 3, 4);
  Creature food2(8, 8, food, 0, 7, 7);
  d.addCreature(0, 0, food1);
  d.addCreature(3, 3, Hopper1);
  d.addCreature(4, 3, Hopper2);
  d.addCreature(4, 4, Hopper3);
  d.addCreature(3, 4, Hopper4);
  d.addCreature(7, 7, food2);

  cout << "Turn = "
       << "0." << endl;
  d.printBoard();
  cout << endl;
  for (int i = 1; i <= 5; ++i) {
    cout << "Turn = " << i << "." << endl;
    d.game_step();
    d.printBoard();
    cout << endl;
  }

  // ----------
  // darwin 7x9
  // ----------

  cout << "*** Darwin 7x9 ***" << endl;
  srand(0);
  /*
  7x9 Darwin
  Trap,   facing south, at (0, 0)
  Hopper, facing east,  at (3, 2)
  Rover,  facing north, at (5, 4)
  Trap,   facing west,  at (6, 8)
  Simulate 5 moves.
  Print every grid.
  */

  Darwin d1(9, 7);
  Creature trap1(9, 7, trap, 2, 0, 0);
  Creature trap2(9, 7, trap, 3, 8, 6);
  Creature Hopper5(9, 7, hopper, 1, 2, 3);
  Creature Rover1(9, 7, rover, 0, 4, 5);

  d1.addCreature(0, 0, trap1);
  d1.addCreature(8, 6, trap2);
  d1.addCreature(2, 3, Hopper5);
  d1.addCreature(4, 5, Rover1);

  cout << "Turn = "
       << "0." << endl;
  d1.printBoard();
  cout << endl;
  for (int i = 1; i <= 5; ++i) {
    cout << "Turn = " << i << "." << endl;
    d1.game_step();
    d1.printBoard();
    cout << endl;
  }
  // ------------
  // darwin 72x72
  // without best
  // ------------

  cout << "*** Darwin 72x72 without Best ***" << endl;
  srand(0);
  /*
  Randomly place the following creatures facing randomly.
  Call rand(), mod it with 5184 (72x72), and use that for the position
  in a row-major order grid.
  Call rand() again, mod it with 4 and use that for it's direction with
  the ordering: west, north, east, south.
  Do that for each kind of creature.
  10 Food
  10 Hopper
  10 Rover
  10 Trap
  Simulate 1000 moves.
  Print the first 10 grids          (i.e. 0, 1, 2...9).
  Print every 100th grid after that (i.e. 100, 200, 300...1000).
  */

  Darwin d2(72, 72);
  int r = rand() % 5184;
  int rh = r / 72;
  int rw = r % 72;
  r = rand() % 4;
  Creature food10(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food10);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food11(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food11);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food12(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food12);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food13(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food13);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food14(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food14);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food15(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food15);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food16(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food16);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food17(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food17);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food18(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food18);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature food19(72, 72, food, r, rw, rh);
  d2.addCreature(rw, rh, food19);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper10(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper10);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper11(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper11);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper12(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper12);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper13(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper13);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper14(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper14);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper15(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper15);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper16(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper16);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper17(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper17);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper18(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper18);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature hopper19(72, 72, hopper, r, rw, rh);
  d2.addCreature(rw, rh, hopper19);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover10(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover10);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover11(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover11);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover12(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover12);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover13(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover13);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover14(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover14);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover15(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover15);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover16(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover16);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover17(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover17);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover18(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover18);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature rover19(72, 72, rover, r, rw, rh);
  d2.addCreature(rw, rh, rover19);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap10(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap10);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap11(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap11);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap12(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap12);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap13(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap13);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap14(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap14);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap15(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap15);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap16(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap16);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap17(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap17);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap18(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap18);
  r = rand() % 5184;
  rh = r / 72;
  rw = r % 72;
  r = rand() % 4;
  Creature trap19(72, 72, trap, r, rw, rh);
  d2.addCreature(rw, rh, trap19);

  cout << "Turn = "
       << "0." << endl;
  d2.printBoard();
  cout << endl;
  for (int i = 1; i <= 1000; ++i) {
    if (i < 10 || (i > 99 && i % 100 == 0))
      cout << "Turn = " << i << "." << endl;
    d2.game_step();
    if (i < 10 || (i > 99 && i % 100 == 0)) {
      d2.printBoard();
      cout << endl;
    }
  }

  // ------------
  // darwin 72x72
  // with best
  // ------------

  cout << "*** Darwin 72x72 with Best ***" << endl;
  srand(0);
  /*
  Randomly place the following creatures facing randomly.
  Call rand(), mod it with 5184 (72x72), and use that for the position
  in a row-major order grid.
  Call rand() again, mod it with 4 and use that for it's direction with
  the ordering: 0:west, 1:north, 2:east, 3:south.
  Do that for each kind of creature.
  10 Food
  10 Hopper
  10 Rover
  10 Trap
  10 Best
  Simulate 1000 moves.
  Best MUST outnumber ALL other species for the bonus pts.
  Print the first 10 grids          (i.e. 0, 1, 2...9).
  Print every 100th grid after that (i.e. 100, 200, 300...1000).
  */

  return 0;
}
