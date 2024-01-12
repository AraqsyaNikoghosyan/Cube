#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

char getRandomFaceMove() {
	char faces[] = {'U', 'D', 'L', 'R'};
	int randomIndex = rand() % 4;
	return faces[randomIndex];
}

int getRandomRotations() {
	return rand() % 3 + 1;
}

std::string generateRandomKey(int maxLength, int numSegments) {

	srand(static_cast<unsigned int>(time(nullptr)));
	if (numSegments <= 0) {
		return "";
	}

	std::string encryptionKey = "";

	for (int i = 0; i < numSegments; ++i) {
		if (!encryptionKey.empty()) {
			encryptionKey += ":";
		}

		int segmentLength = rand() % (maxLength / numSegments) + 1;
		for (int j = 0; j < segmentLength; ++j) {
			char randomFaceMove = getRandomFaceMove();
			int randomRotations = getRandomRotations();
			encryptionKey += randomFaceMove;
			encryptionKey += std::to_string(randomRotations);
		}
	}

	return encryptionKey;
}

#endif //KEY_H

