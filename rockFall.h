#ifndef rockFall_h
#define rockFall_h
#include "gameObject.h"
#include "stdint.h"
/* 
*   Implementation of an abstract class to control different game modes. 
*   Must provide certain base functionality that I have not yet decided in order
*   to allow the necessary switching behavior. 
*/
class Controller
{
public:
  virtual void render() = 0;
  virtual void update(float dt) = 0;
  virtual void preUpdate() = 0;
  virtual void draw(GameBoard &board) = 0;

private:
  GameBoard board;
};

/**
 * Implementation of Controller to run the main game.
 */
class GameController : public Controller
{
public:
  Player *player;
  Rock *rocks;
  Coin *coins;
  unsigned int coinsCollected;
  void render();
  void update(float dt);
  void preUpdate();
  void draw(GameBoard &board);
  GameController(GameBoard &board_ref);

private:
  GameBoard board;
  uint8_t numCoins;
  uint8_t numRocks;
  uint16_t rockCount;
  uint16_t coinCount;
  uint16_t maxRockCount;
  uint16_t maxCoinCount;
};

/* 
*   Implementation of a class (rockFall) to run the main game. This class
*   assigns controllers to write output to the board, and processes requests
*   to switch controllers.
*/
class RockFall
{
public:
  void run();
  RockFall();
  GameBoard *board;

private:
  GameController *game;
};

#endif