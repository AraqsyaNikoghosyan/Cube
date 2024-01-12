#include "cube.h"
#include <iostream>
Cube::Cube(const std::string& txt) {
	if (txt.size() > 8) {
		throw std::invalid_argument {"more than 8 symbol!!"};
	}
	text = txt;
	for (int i = 0; i < 8 - txt.size(); ++i) {
		text = text + "~";
	}
}	
void Cube::Up() {
	std::string newStr = "00000000";
	newStr[0] = text[3];
	newStr[1] = text[2];
	newStr[2] = text[6];
	newStr[3] = text[7];
	newStr[4] = text[0];
	newStr[5] = text[1];
	newStr[6] = text[5];
	newStr[7] = text[4];
	text = newStr;
}
void Cube::Down() {
	std::string newStr = "00000000";
	newStr[0] = text[4];
	newStr[1] = text[5];
	newStr[2] = text[1];
	newStr[3] = text[0];
	newStr[4] = text[7];
	newStr[5] = text[6];
	newStr[6] = text[2];
	newStr[7] = text[3];
	text = newStr;
}
void Cube::Left() {
	std::string newStr = "00000000";
	newStr[0] = text[1];
	newStr[1] = text[5];
	newStr[2] = text[6];
	newStr[3] = text[2];
	newStr[4] = text[0];
	newStr[5] = text[4];
	newStr[6] = text[7];
	newStr[7] = text[3];
	text = newStr;
}
void Cube::Right() {
	std::string newStr = "00000000";
	newStr[0] = text[4];
	newStr[1] = text[0];
	newStr[2] = text[3];
	newStr[3] = text[7];
	newStr[4] = text[5];
	newStr[5] = text[1];
	newStr[6] = text[2];
	newStr[7] = text[6];
	text = newStr;
}
