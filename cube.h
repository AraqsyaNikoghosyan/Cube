#ifndef CUBE_H
#define CUBE_H

#include <string>
#include <stdexcept>

class Cube {
public:
	Cube(const std::string&);
	void Up();
	void Down();
	void Left();
	void Right();
	std::string Read() const {
		return text;
	};
private:
	std::string text;
};






#endif //CUBE_H
