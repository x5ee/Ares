#include "Utils.h"

std::string Utils::debugPath = Utils::getRoamPath();

auto Utils::getDll(void) -> HMODULE {

    MEMORY_BASIC_INFORMATION info;
	size_t len = VirtualQueryEx(GetCurrentProcess(), (void*)getDll, &info, sizeof(info));
	assert(len == sizeof(info));
	return len ? (HMODULE)info.AllocationBase : NULL;

};

auto Utils::getRoamPath(void) -> std::string {

	char* path = NULL;
	size_t length;

	_dupenv_s(&path, &length, "appdata");

	if (path == NULL)
		return "";

	return std::string(path) + "\\..\\Local\\Packages\\Microsoft.MinecraftUWP_8wekyb3d8bbwe\\RoamingState";

};

auto Utils::getDebugPath(void) -> std::string {

	auto f = std::filesystem::path(Utils::debugPath);

	if (!std::filesystem::exists(f))
		std::filesystem::create_directories(f);

	return Utils::debugPath;

};

auto Utils::setDebugPath(std::string path) -> void {

	Utils::debugPath = std::string(Utils::getRoamPath() + "\\" + path);

	if(!std::filesystem::exists(Utils::debugPath))
		std::filesystem::create_directories(Utils::debugPath);

};

auto Utils::debugOutput(std::string output) -> void {

	static bool init = false;
	static auto path = Utils::getDebugPath();

	auto file = std::string(path + "\\Output.txt");

	if (!init) {
		auto f = std::filesystem::path(file);

		if (std::filesystem::exists(f))
			std::filesystem::remove(f);

		init = true;
	};

	CloseHandle(CreateFileA(file.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL));

	std::ofstream fStream;
	fStream.open(file.c_str(), std::ios::app);

	if (fStream.is_open())
		fStream << output << "\n" << std::endl;

	return fStream.close();

};