#include "Key.h"
#include "../../../Category/Module/Module.h"

typedef void (__thiscall* Key)(uint64_t, bool);
Key oKey;

Manager* kMgr = nullptr;

auto KeyHookCallback(uint64_t key, bool isDown) -> void {

    auto instance = MC::getClientInstance();
    auto canUseKeys = (instance && (isDown && instance->getTopScreenName().rfind("hud_screen") != std::string::npos));
    
    bool cancel = false;
    
    if(kMgr) {

        kMgr->keyMap[key] = isDown;

        for(auto category : kMgr->categories) {
            
            for(auto module : category->modules) {
                
                if(canUseKeys && module->key == key)
                    module->isEnabled = !module->isEnabled;

                if(module->isEnabled)
                    module->onKey(key, isDown, &cancel);
                
            };

        };

    };
    
    if(!cancel)
        oKey(key, isDown);

};

auto KeyHook::init(void) -> void {

    kMgr = this->mgr;
    
    auto sig = Mem::findSig("48 83 EC 48 0F ? ? 4C 8D 05");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for Key hook!");
    
    if(MH_CreateHook((void*)sig, &KeyHookCallback, reinterpret_cast<LPVOID*>(&oKey)) == MH_OK)
        MH_EnableHook((void*)sig);
    else
        Utils::debugOutput("Failed to create detour for Key hook!");

};