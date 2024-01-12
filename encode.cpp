#include <iostream>
#include <fstream>
#include <vector>
#include "cube.h"
#include "key.h"

void tokenize (std::vector<Cube> *allText, const std::string& fname) {
	std::ifstream inputFile(fname);
	
	if (!inputFile) {
		std::cerr << "Error opening file." << std::endl;
		std::exit(1);
	}
	const int chunkSize = 8;

	while (true) {
		char buffer[chunkSize + 1];
		inputFile.read(buffer, chunkSize);
		int bytesRead = inputFile.gcount();
		if (bytesRead > 0) {
			buffer[bytesRead] = '\0';
			allText->push_back(Cube((std::string)buffer));
			
		} else {
			break;
		}
	}

	inputFile.close();

}

void encoder(std::vector<Cube>& allText, const std::string& key) {
	int i = 0;
	int n = 0;
	const char *p = key.c_str();
	while(*p != '\0'){
		if(*p == ':') {
			++i;
			p++;
		}
		else 
		{
			if(*(p + 1) == '1') {
				n = 1;
			}
			else if(*(p + 1) == '2') {
				n = 2;
			}
			else if(*(p + 1) == '3') {
				n = 3;
			}

			if(*p == 'U') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Up();
				}
			}
			else if(*p == 'D') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Down();
				}
			}
			else if(*p == 'L') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Left();
				}
			}
			else if(*p == 'R') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Right();
				}
			}
			p = p + 2;
		}
	}
}
void decoder(std::vector<Cube>& allText, const std::string& key) {
	int i = 0;
	int n = 0;
	const char *p = key.c_str();
	while(*p != '\0'){
		if(*p == ':') {
			++i;
			p++;
		}
		else 
		{
			if(*(p + 1) == '1') {
				n = 1;
			}
			else if(*(p + 1) == '2') {
				n = 2;
			}
			else if(*(p + 1) == '3') {
				n = 3;
			}

			if(*p == 'D') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Up();
				}
			}
			else if(*p == 'U') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Down();
				}
			}
			else if(*p == 'R') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Left();
				}
			}
			else if(*p == 'L') {
				for(int j = 0; j <  n; ++j) {
					allText[i].Right();
				}
			}
			p = p + 2;
		}
	}
}
void encStore (std::vector<Cube>& allText, const std::string& key) {	
	std::ofstream outputFile("shrift.txt");
	if (!outputFile) {
		std::cerr << "Error opening file." << std::endl;
		std::exit(1);
	}
	for(auto ob : allText) {
		outputFile << ob.Read();
	}
	outputFile.close();
	std::ofstream outFile("key.txt");
	if (!outFile) {
		std::cerr << "Error opening file." << std::endl;
		std::exit(1);
	}
	outFile << key;
	outFile.close();
}
void DecStore (std::vector<Cube>& allText) {	
	std::ofstream outputFile("decoded.txt");
	if (!outputFile) {
		std::cerr << "Error opening file." << std::endl;
		std::exit(1);
	}
	for(auto ob : allText) {
		outputFile << ob.Read();
	}
	outputFile.close();

}

int main() {
	std::vector<Cube> allText;
	const int maxLength = 15;
	bool ch = 0;
	std::cout << "encode:0, decode:1" << std::endl;
	std::cin >> ch;
	if(!ch) {
		tokenize(&allText, "example.txt");
		std::string key = generateRandomKey(maxLength, allText.size());
		encoder(allText, key);
		encStore(allText, key);
	}
	else {
		std::ifstream inputFile("key.txt");
		if (!inputFile) {
			std::cerr << "Error opening file." << std::endl;
			std::exit(1);
		}
		std::string key;
	        getline(inputFile, key);
		inputFile.close();
		tokenize(&allText, "shrift.txt");
		decoder(allText, key);
		DecStore(allText);


	}
	return 0;
}
