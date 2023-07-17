#ifndef CLIENT_MEM_MEM
#define CLIENT_MEM_MEM

#include <Windows.h>
#include <algorithm>
#include <optional>
#include <vector>

#define INRANGE(x,a,b) (x >= a && x <= b)
#define GET_BYTE( x )  (GET_BITS(x[0]) << 4 | GET_BITS(x[1]))
#define GET_BITS( x )  (INRANGE((x&(~0x20)),'A','F') ? ((x&(~0x20)) - 'A' + 0xa) : (INRANGE(x,'0','9') ? x - '0' : 0))

class Mem {
public:
    static auto findSig(const char*) -> unsigned long long;
    static auto findMultiLvlPtr(unsigned long long, std::vector<unsigned int>, bool) -> unsigned long long;
};

#endif /* CLIENT_MEM_MEM */