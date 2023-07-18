#ifndef CLIENT_ARES_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN
#define CLIENT_ARES_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN

#include "../../Hook.h"
#include "../../../../../Includes/imgui/imgui.h"
#include "../../../../../Includes/imgui/imgui_impl_dx11.h"
#include "../../../../../Includes/imgui/imgui_impl_dx12.h"
#include "../../../../../Includes/imgui/imgui_impl_win32.h"

class SwapChainHook : public Hook {
public:
    SwapChainHook(Manager* mgr) : Hook(mgr) {
        this->init();
    };
public:
    auto init(void) -> void override;
};

#endif /* CLIENT_ARES_HOOK_HOOKS_SWAPCHAIN_SWAPCHAIN */