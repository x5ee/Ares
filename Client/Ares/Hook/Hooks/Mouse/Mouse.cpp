#include "Mouse.h"
#include "../../../Category/Module/Module.h"

typedef void(__thiscall* Mouse)(void*, MouseAction, bool, short, short, void*, void*, void*);
Mouse oMouse;

Manager* mhMgr = nullptr;

auto MouseHookCallback(void* p1, MouseAction action, bool isDown, short p4, short p5, void* p6, void* p7, void* p8) -> void {

    bool cancel = false;

	if(ImGui::GetCurrentContext() != nullptr && action != MouseAction::NONE) {

        if(action != MouseAction::NONE && action != MouseAction::WHEEL_SCROLL && action != MouseAction::WHEEL_CLICK)
            ImGui::GetIO().MouseDown[0] = isDown;
        
    };
    
    for(auto category : mhMgr->categories) {

        for(auto module : category->modules) {
            
            if(module->isEnabled)
                module->onMouse(action, isDown, Vec2<short>(p4, p5), &cancel);

        };

    };

	if(!cancel)
        oMouse(p1, action, isDown, p4, p5, p6, p7, p8);

};

auto MouseHook::init(void) -> void {

    mhMgr = this->mgr;
    
    auto sig = Mem::findSig("48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 57 41 54 41 55 41 56 41 57 48 83 EC 60");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for Mouse hook!");
    
    if (MH_CreateHook((void*)sig, &MouseHookCallback, reinterpret_cast<LPVOID*>(&oMouse)) == MH_OK)
        MH_EnableHook((void*)sig);
    else
        Utils::debugOutput("Failed to create detour for Mouse hook!");

};