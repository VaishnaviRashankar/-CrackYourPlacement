 class Solution {
 public:
 	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
 		unordered_set<string> set(wordList.begin(), wordList.end());
 		if(set.find(endWord) == set.end()) return 0;
 		set.erase(endWord);
 		unordered_set<string> first{beginWord}, second{endWord};
 		int len = endWord.length();
 		int step = 0;
 		while(!first.empty() && !second.empty()){
 			++step;
 			if(first.size() > second.size())
 				std::swap(first, second);
 			unordered_set<string> next;
 			for(string cur: first){
 				for(int i = 0; i < len; ++i){
 					char origin = cur[i];
 					for(char c = 'a'; c <= 'z'; ++c){
 						cur[i] = c;
 						if(second.find(cur) != second.end())    return step + 1;
 						if(set.find(cur) != set.end()){
 							next.emplace(cur);
 							set.erase(cur);
 						}
 						cur[i] = origin;
 					}
 				}
 			}
 			std::swap(next, first);
 		}
 		return 0;
 	}
 };