#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define MAX_ENTRIES 400
#define OPTION_A "OptionA"
#define OPTION_B "OptionB"

using IndexOptionPair = std::pair<uint32_t, std::string>;

class TaskPreferences {
public:
  TaskPreferences(const std::string &input_file) {
    std::ifstream infile(input_file);
    if (!infile) {
      std::cerr << "Error opening file!" << std::endl;
      return;
    }

    infile >> total_entries_ >> total_tasks_;
    preferences_.reserve(total_entries_);

    for (int i = 0; i < total_tasks_; ++i) {
      final_assignment_[i] = OPTION_B;
    }

    parseInput(infile);
    processAssignments();
  }

  void showAssignments() const {
    for (const auto &pair : final_assignment_) {
      std::cout << pair.first << " -> " << pair.second << std::endl;
    }
  }

private:
  void parseInput(std::ifstream &infile) {
    std::string line;
    std::getline(infile, line); // consume newline

    for (uint32_t i = 0; i < total_entries_; ++i) {
      if (std::getline(infile, line)) {
        std::vector<IndexOptionPair> entry;
        std::stringstream ss(line);
        std::string token;

        while (std::getline(ss, token, ',')) {
          std::stringstream pair_stream(token);
          uint32_t idx;
          std::string opt;
          pair_stream >> idx >> opt;
          entry.emplace_back(idx, opt);
        }

        preferences_.push_back(entry);
      }
    }
  }

  void processAssignments() {
    for (const auto &entry : preferences_) {
      for (const auto &p : entry) {
        if (p.second == OPTION_A) {
          final_assignment_[p.first] = OPTION_A;
        }
      }
    }
  }

  uint32_t total_entries_;
  uint32_t total_tasks_;
  std::vector<std::vector<IndexOptionPair>> preferences_;
  std::unordered_map<uint32_t, std::string> final_assignment_;
};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Provide input file as argument" << std::endl;
    return 1;
  }

  TaskPreferences tp(argv[1]);
  tp.showAssignments();
  return 0;
}