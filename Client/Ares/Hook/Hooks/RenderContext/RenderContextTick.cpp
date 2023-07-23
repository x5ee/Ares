#include "RenderContextTick.h"
#include "../../../Category/Module/Module.h"

typedef void (__thiscall* RenderCtx)(void*, void*);
RenderCtx _RenderCtx;

Manager* rndrCtxMgr = nullptr;

auto RenderCtxCallback(void* p1, void* ctx) -> void {

    static int frameCount = 0;

    if(rndrCtxMgr) {

        frameCount++;

        if(frameCount >= 3) {

            frameCount = 0;

            for(auto category : rndrCtxMgr->categories) {

                for(auto module : category->modules) {
                    if(module->isEnabled)
                        module->onRenderCtx(ctx);
                };
            };

            auto instance = *(ClientInstance**)((uintptr_t)(ctx) + 0x8);
            
            auto player = (instance ? instance->getPlayer() : nullptr);
            auto level = (player ? player->getLevel() : nullptr);

            if(level != nullptr) {

                for(auto [ runtimeId, entity ] : rndrCtxMgr->entityMap) {

                    auto ent = level->getRuntimeEntity(runtimeId);

                    if(ent == nullptr)
                        rndrCtxMgr->entityMap.erase(runtimeId);

                };

            } else {

                if(!rndrCtxMgr->entityMap.empty())
                    rndrCtxMgr->entityMap.clear();

            };

        };

    };

    _RenderCtx(p1, ctx);

};

auto RenderCtxHook::init(void) -> void {

    rndrCtxMgr = this->mgr;

    auto sig = Mem::findSig("48 8B C4 48 89 58 ? 55 56 57 41 54 41 55 41 56 41 57 48 8D A8 ? ? ? ? 48 81 EC ? ? ? ? 0F 29 70 ? 0F 29 78 ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 85 ? ? ? ? 4C 8B F2 48 89 54 24 ? 4C 8B E9");

    if(!sig)
        return Utils::debugOutput("Failed to find signature for RenderContext hook!");
    
    if(MH_CreateHook((void*)sig, &RenderCtxCallback, reinterpret_cast<LPVOID*>(&_RenderCtx)) == MH_OK)
        MH_EnableHook((void*)sig);
    else
        Utils::debugOutput("Failed to create detour for RenderContext hook!");

};