#include <string>
#include <vector>
#include <string>

using namespace std;

bool IsPalindrom(string s) {
   	// Определяет, является ли слово палиндромом или нет:)
  	 for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}


vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector <string> answer;
	for (auto word: words) {
		if (IsPalindrom(word) && (word.size() >= minLength))
			answer.push_back(word);
	}

	return answer;
}
