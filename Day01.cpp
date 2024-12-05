#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int main()
{

	std::ifstream iFile;
	iFile.open("C:\\Users\\brend\\Documents\\input.txt", std::ios::in);
	if (iFile.fail()) {
		std::cerr << "File not found\n";
	}
	else {
		std::string input;
		std::vector<int> l;
		std::vector<int> r;
		std::map<int, int> freq;
		while (std::getline(iFile, input)) {
			int temp = 0;
			for (auto c : input) {
				if (isdigit(c)) {
					temp *= 10;
					temp += c - 48;
				}
				else if(temp != 0){
					l.push_back(temp);
					temp = 0;
				}
			}
			r.push_back(temp);
			freq[temp]++;
		}

		int total = 0;

		std::sort(l.begin(), l.end());
		std::sort(r.begin(), r.end());

		for (int i = 0; i < l.size(); i++)
		{
			total += abs(l[i] - r[i]);
		}

		std::cout << "Part 1:\n";
		std::cout << "\nTotal: " << total << std::endl << std::endl;



		total = 0;
		for (auto n : l) {
			total += n * freq[n];
		}

		std::cout << "Part 2:\n";
		std::cout << "Total: " << total << std::endl << std::endl;

	}
	return 0;
}
