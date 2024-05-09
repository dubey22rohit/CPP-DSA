// Not the solution(The actual solution is below), since isSubsequence required
// the order of the elements to remain unchanged This function can be used to
// check if s can be formed from t. Not a leetcode question solution, just
// leaving this here, because it took me 10 mins to write this.
bool checkStringFormed(string s, string t) {
    unordered_map<char, int> mp;
    for (size_t i = 0; i < s.length(); i++) {
        mp[s[i]]++;
    }

    for (size_t i = 0; i < t.length(); i++) {
        if (mp.find(t[i]) != mp.end()) {
            mp[t[i]]--;
        }
    }

    unordered_map<char, int>::iterator it = mp.begin();
    while (it != mp.end()) {
        if (it->second != 0) {
            return false;
        }
        it++;
    }
    return true;
}