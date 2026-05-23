#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H





class GameObject {
public:
    GameObject();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};





#endif