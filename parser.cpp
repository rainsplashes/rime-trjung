#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Helper that splits a string by a delimiter
// Parameters: const string s and char delimiter
// Returns: vector of strings that were split
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> parts;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        parts.push_back(item);
    }
    return parts;
}

int main() {
    // open input file
    std::ifstream fin("input.txt");
    if (!fin) {
        std::cerr << "Failed to open input.txt\n";
        return 1;
    }

    // open output file
    std::ofstream fout("output.txt");
    if (!fout) {
        std::cerr << "Failed to create output.txt\n";
        return 1;
    }

    // mappings, can be expanded and customized to any scheme
    std::map<std::string, std::string> initial_map = {
        {"匣", "gh"},
        {"端", "t"}
    };

    std::map<std::string, std::string> final_map = {
        {"開|庚二", "rang"},
        {"東一", "ung"}
    };

    // read one line from input at a time
    std::string line;
    while (std::getline(fin, line)) {
        // skip empty lines
        if (line.empty()) continue;

        // extract first character (most CJK UTF-8 are 3 bytes)
        // the first character is the character to be romanized
        std::string han_char = line.substr(0, 3);

        // find the bracketed section to extract fanqie spellings
        size_t start = line.find('【');
        size_t end = line.find('】');
        // if bracketed section was not found, skip the section
        if (start == std::string::npos || end == std::string::npos || end <= start) continue;

        // clip the section inside of the brackets
        std::string inside = line.substr(start + 1, end - start - 1);
        // split section into different parts
        std::vector<std::string> parts = split(inside, '|');

        // store the initial, final, and tone
        std::string initial, final, tone;

        // e.g. 【端|東一|平】
        if (parts.size() == 3) {
            initial = parts[0];
            final = parts[1];
            tone = parts[2];
        }
        // e.g. 【匣|開|庚二|平】
        else if (parts.size() == 4) {
            initial = parts[0];
            final = parts[1] + "|" + parts[2]; // fuse the two
            tone = parts[3];
        }
        // skip lines with unexpected format
        else {
            continue;
        }

        // look up mappings to convert to spelling
        std::string initial_mc = initial_map.count(initial) ? initial_map[initial] : "ERROR! INITIAL NOT FOUND";
        std::string final_mc = final_map.count(final) ? final_map[final] : "ERROR! FINAL NOT FOUND";

        if (!initial_mc.empty() && !final_mc.empty()) {
            fout << han_char << " " << initial_mc << final_mc << "\n";
        }
    }

    std::cout << "Parsing complete. Results written to output.txt\n";
    return 0;
}
