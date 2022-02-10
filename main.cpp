#include <array>
#include <string>

using namespace std;

constexpr wchar_t HexintToHexwchar(int8_t num)
{
	constexpr std::array<wchar_t, 16> HEX_TABLE = {
		L'0', L'1', L'2', L'3', L'4', L'5', L'6', L'7',
		L'8', L'9', L'A', L'B', L'C', L'D', L'E', L'F' 
	};
	return HEX_TABLE.at(num);
}

constexpr std::array<wchar_t, 6> WideCharToUnicodeTable(wchar_t ch)
{
	int8_t low = static_cast<int8_t>(ch & 0x00FF);
	int8_t high = static_cast<int8_t>((ch & 0xFF00) >> 8);

	return std::array<wchar_t, 6>{
		L'U', L'+',
		HexintToHexwchar((high & 0xF0) >> 4),
		HexintToHexwchar(high & 0x0F),
		HexintToHexwchar((low & 0xF0) >> 4),
		HexintToHexwchar(low & 0x0F)
	};
}

int main()
{
	constexpr auto a0 = WideCharToUnicodeTable(L' '); // U+0020

	auto b0 = WideCharToUnicodeTable(L' '); // U+0020
}
