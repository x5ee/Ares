#include "Mem.h"

auto Mem::findSig(const char* signature) -> unsigned long long {
	static auto pattern_to_byte = [](const char* pattern) {

		auto bytes = std::vector<std::optional<uint8_t>>{};
		auto start = const_cast<char*>(pattern);
		auto end = const_cast<char*>(pattern) + strlen(pattern);
		bytes.reserve(strlen(pattern) / 2);

		for (auto current = start; current < end; ++current) {
			if (*current == '?') {
				++current;
				if (*current == '?')
					++current;
				bytes.push_back(std::nullopt);
			}
			else bytes.push_back((uint8_t)strtoul(current, &current, 16));
		}
		return bytes;

	};

	auto gameModule = (unsigned long long)(GetModuleHandleA("Minecraft.Windows.exe"));
	auto* const scanBytes = reinterpret_cast<uint8_t*>(gameModule);
	auto* const dosHeader = reinterpret_cast<PIMAGE_DOS_HEADER>(gameModule);
	auto* const ntHeaders = reinterpret_cast<PIMAGE_NT_HEADERS>(scanBytes + dosHeader->e_lfanew);
	const auto sizeOfCode = ntHeaders->OptionalHeader.SizeOfImage;

	const auto pattern = pattern_to_byte(signature);
	const auto end = scanBytes + sizeOfCode;

	auto it = std::search(
		scanBytes, end,
		pattern.cbegin(), pattern.cend(),
		[](auto byte, auto opt) {
			return !opt.has_value() || *opt == byte;
		});

	auto ret = it != end ? (unsigned long long)it : 0u;
	if (!ret)
		return 0;

	return ret;
};

auto Mem::findMultiLvlPtr(unsigned long long baseAddr, std::vector<unsigned int> offsets, bool basePure) -> unsigned long long {

	auto ptr = (unsigned long long)NULL;
	auto i = 0;

	if (basePure) {
		ptr = baseAddr;
	}
	else {
		auto hwnd = GetModuleHandleA("Minecraft.Windows.exe");
		ptr = (unsigned long long)(hwnd)+baseAddr;
	};

	do {

		if (*(unsigned long long*)ptr + offsets[i] == offsets[i] || *(unsigned long long*)ptr + offsets[i] > 0xFFFFFFFFFFFF)
			break;

		ptr = *(unsigned long long*)ptr + offsets[i];

		if (ptr == NULL)
			break;

		i++;

	} while (i < offsets.size());

	return (i == offsets.size() ? ptr : NULL);

};