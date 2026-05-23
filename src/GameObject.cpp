#include "GameObject.h"
#include "Game.h"
#include <vector>
#include <memory>



GameObject::GameObject(){
    Game::gameObjects.push_back(std::unique_ptr<GameObject> (this));
}