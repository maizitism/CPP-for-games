#include <iostream>
#include <fstream>
#include <string>

int main() {

	struct Highscore {
		char name[4];
		uint32_t score;
	};

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

	// read ascii files
	{
		std::ifstream highscores(fileName);
		if (!highscores) {
			std::cerr << "Error: failed to open file for reading." << std::endl;
			return 1;
		}

		char name[4];
		int score;
		while (highscores >> name >> score) {
			std::cout << "Name: " << name << ", Score: " << score << std::endl;
		}
		if(highscores.bad()){
			std::cerr << "Error: File could not be read." << std::endl;
			return 1;
		}
		highscores.close();
	}

	// writing binary files
	{
		std::ofstream highscores("highscores.bin", std::ios::binary);
		if (!highscores) {
			std::cerr << "Error: Error while opening file" << std::endl;
			return 1;
		}

		Highscore scores[] = {
			{"DAN", 2014},
			{"TOM", 2012},
			{"LUC", 2009},
			{"SUZ", 1978},
			{"JER", 1977}
		};
		auto numScores = std::size(scores);
		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores)); // writes the number of elements at top of file
		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(Highscore)); // writes all entries of struct in order

		if (highscores.bad()) {
			std::cerr << "Error: File could not be written to." << std::endl;
			return 1;
		}
		highscores.close(); 
	}

	// reading binary files

	{
		std::ifstream highscores("highscores.bin", std::ios::binary);
		if (!highscores) {
			std::cerr << "Error: Could not read the file." << std::endl;
			return 1;
		}

		// read first 8 bytes of file
		size_t numEntries;
		highscores.read(reinterpret_cast<char*>(&numEntries), sizeof(numEntries)); // now we know how many entries to read

		Highscore* scores = new Highscore[numEntries];
		highscores.read(reinterpret_cast<char*>(scores), numEntries * sizeof(Highscore));

		if (highscores.bad()) {
			std::cerr << "Error: Failed to read from file." << std::endl;
			return 1;
		}

		for (int i = 0; i < numEntries; i++) {
			std::cout << "Name: " << scores[i].name << ", Score: " << scores[i].score << std::endl;
		}
		delete[] scores; // delete memory after dynamic allocation in line 108
		
		highscores.close();
	}
	return 0;
}