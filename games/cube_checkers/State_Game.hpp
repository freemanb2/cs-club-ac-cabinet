#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "State_Base.hpp"
#include "Player.hpp"

struct SharedContext;

class State_Game : public State_Base {
public:
  State_Game(SharedContext & ctx);
  ~State_Game();

  void handleEvent(sf::Event e);
  void update();
  void render();
private:
  void selectPiece();
  void incrementPiece();
  Tile getTileAtIndex(int i);
  void calcallowedMoves(Player & currentPlayer, Player & otherPlayer);
  void getPotentialJumps();
  void getPotentialJumpsForTile(Tile tile);

  std::vector<Tile> board;
  std::vector<Tile> allowedMoves;
  std::vector<Tile> potentialJumps;
  Player player1, player2, winner;
  bool madeJumps, incrementing, gameOver;
  int indexOfMovedPiece;
};
