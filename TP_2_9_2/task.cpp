#include "task.h"

bool isSplitterSuggestion(const char& ch) {
	return ch == '.' || ch == '?' || ch == '!' || ch == ')' || ch == '(' || ch == '\n' || ch == '\0';
}


bool isSplitterWord(const char& ch) {
	return isSplitterSuggestion(ch) || ch == ',' || ch == ' ' || ch == ':';
}

std::string findSuggestoins(const std::string& s, int countFindSuggestion) {
	std::string ans = "";
	bool isWord = false, isSuggestion = false;
	int countWord = 0;
	int startSuggestoin = 0;
	int number = 1;
	for (int i = 0; i < s.size(); i++) {
		if (isSplitterWord(s[i])) {
			isWord = false;
			if (isSplitterSuggestion(s[i])) {
				if (countWord == countFindSuggestion)
					ans
					.append(std::to_string(number++) + ") ")
					.append(s.substr(startSuggestoin, i + 1 - startSuggestoin))
					.append("\n");					
				startSuggestoin = i + 1;
				countWord = 0;
			}
		}
		else {
			if (!isWord) {
				isWord = true;
				countWord++;
			}
		}
	}
	return !ans.empty() ? ans : "В файле нет предложений заданной длины\n";
}