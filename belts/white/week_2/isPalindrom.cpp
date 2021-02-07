bool IsPalindrom(string s) {
   	// Определяет, является ли слово палиндромом или нет:)
  	 for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) {
            return false;
        }
    }
    return true;
}