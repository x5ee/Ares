#ifndef CLIENT_SDK_CLASSES_GAMEMODE
#define CLIENT_SDK_CLASSES_GAMEMODE

#include "../../Utils/Utils.h"

class GameMode {
public:
    class Player* player;
private:
    virtual ~GameMode();
public:
    virtual auto startDestroyBlock(Vec3<int>*, unsigned char, bool) -> bool;
    virtual auto destroyBlock(Vec3<int>*, unsigned char) -> bool;
    virtual auto continueDestroyBlock(Vec3<int>*, unsigned char, Vec3<float>*, bool*) -> bool;
    virtual auto stopDestroyBlock(Vec3<int>*) -> void;
    virtual auto startBuildBlock(Vec3<int>*) -> void;
    virtual auto buildBlock(Vec3<int>*, unsigned char, bool) -> bool;
    virtual auto continueBuildBlock(Vec3<int>*, unsigned char) -> void;
    virtual auto stopBuildBlock(void) -> void;
    virtual auto tick(void) -> void;
    virtual auto getPickRange(enum InputMode*, bool) -> float;
    virtual auto useItem(class ItemStack*) -> bool;
    virtual auto useItemOn(class ItemStack*, Vec3<int>*, unsigned char, Vec3<float>*, class Block*) -> class InteractionResult*;
    virtual auto interact(class Actor*, Vec3<float>*) -> bool;
    virtual auto attack(class Actor*) -> bool;
    virtual auto releaseUsingItem(void) -> void;
    virtual auto setTrialMode(bool) -> void;
    virtual auto isInTrialMode(void) -> bool;
};

#endif /* CLIENT_SDK_CLASSES_GAMEMODE */