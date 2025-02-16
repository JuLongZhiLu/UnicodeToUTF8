#include <iostream>
#include <iomanip>
#include <string>

std::string unicodeToUTF8(uint32_t unicode) {
	std::string utf8;
	if (unicode <= 0x7F) {
		utf8 += static_cast<char>(unicode);
	} else if (unicode <= 0x7FF) {
		utf8 += static_cast<char>(0xC0 | ((unicode >> 6) & 0x1F));
		utf8 += static_cast<char>(0x80 | (unicode & 0x3F));
	} else if (unicode <= 0xFFFF) {
		utf8 += static_cast<char>(0xE0 | ((unicode >> 12) & 0x0F));
		utf8 += static_cast<char>(0x80 | ((unicode >> 6) & 0x3F));
		utf8 += static_cast<char>(0x80 | (unicode & 0x3F));
	} else if (unicode <= 0x10FFFF) {
		utf8 += static_cast<char>(0xF0 | ((unicode >> 18) & 0x07));
		utf8 += static_cast<char>(0x80 | ((unicode >> 12) & 0x3F));
		utf8 += static_cast<char>(0x80 | ((unicode >> 6) & 0x3F));
		utf8 += static_cast<char>(0x80 | (unicode & 0x3F));
	}
	return utf8;
}

int main() {
	uint32_t unicode = 0x528c;
	std::string utf8 = unicodeToUTF8(unicode);
	
	std::cout << "Unicode: U+" << std::hex << unicode << std::endl;
	std::cout << "UTF-8: ";
	for (unsigned char c : utf8) {
		std::cout << "0x" << std::hex << std::setw(2) << std::setfill('0') << (int)c << " ";
	}
	std::cout << std::endl;
	
	return 0;
}

