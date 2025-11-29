#include <iostream>
#include <fstream>
#include <string>

int main() {

	std::string fileName = "highscores.txt"; // define filename because i cant be bothered to type it everywhere
	//creates scope block for variable containment
	// write ascii files
	{
		std::ofstream highscores(fileName); // will truncate, discard all data within file if file already exists
		if (!highscores) {
			std::cerr << "Error: could not open file for writing." << std::endl;
			return 1;
		}

		highscores << "DAN " << 2014 << std::endl;
		highscores << "TOM " << 2004 << std::endl;
		highscores << "LUC " << 2009 << std::endl;
		highscores << "SUZ " << 1978 << std::endl;

		if (highscores.bad()) {
			std::cerr << "Error: An error occoured while writing to " << fileName << std::endl;
			return 1;
		}

		highscores.close(); // will automatically close if goes out of scope
	}

	// append to ascii files
	{
		std::ofstream highscores(fileName, std::ios::app); // open in appending mode
		if (!highscores) {
			std::cerr << "Error: could not open file for writing.";
			return 1;
		}
		highscores << "JER " << 1977 << std::endl;
		if (highscores.bad()) {
			std::cerr << "Error: failed to write to " << fileName << std::endl;
		}
		highscores.close();
	}
	return 0;
}