#include "Minecraft.h"
#include "../Mem/Mem.h"

auto MC::getClientInstance(void) -> ClientInstance* {

    static uintptr_t sig = NULL;

	if (sig == NULL)
		sig = Mem::findSig("48 8B 05 ? ? ? ? 48 85 C0 74 ? F0 FF 40 ? 48 8B 05 ? ? ? ? 48 8B 0D ? ? ? ? 48 89 43 ? 48 8B C3 48 89 3B C6 43 ? ? 48 89 4B ? 48 8B 5C 24 ? 48 83 C4 ? 5F C3 33 C0 48 8B CF 48 89 03 88 43 ? 48 89 43 ? 48 89 43 ? E8 ? ? ? ? 48 8B C3 48 8B 5C 24 ? 48 83 C4 ? 5F C3 CC CC CC CC CC CC CC CC CC CC CC E9 ? ? ? ? CC CC CC CC CC CC CC CC CC CC CC 48 89 5C 24 ? 48 89 74 24");

	auto offset = *(int*)(sig + 3);
	auto basePtr = (uintptr_t)(uintptr_t**)(sig + offset + 7);

	return ((ClientInstance*)Mem::findMultiLvlPtr(basePtr, { 0x10, 0x58, 0x0, 0x0 }, true));

};