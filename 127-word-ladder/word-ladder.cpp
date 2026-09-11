class Solution {
public:

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // Put all valid words into a set
        // so we can check a word quickly
        unordered_set<string> st(wordList.begin(), wordList.end());

        // If endWord is not present, transformation is impossible
        if(st.find(endWord) == st.end())
            return 0;

        // Queue for BFS
        queue<string> q;

        // Start from beginWord
        q.push(beginWord);

        // Number of words in the current sequence
        int level = 1;

        while(!q.empty()) {

            // Number of words at this BFS level
            int size = q.size();

            while(size--) {

                // Take the current word
                string word = q.front();
                q.pop();

                // Try changing every character
                for(int i = 0; i < word.size(); i++) {

                    // Save the original character
                    char original = word[i];

                    // Try all 26 letters
                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        // Change one character
                        word[i] = ch;

                        // If we reached endWord
                        if(word == endWord)
                            return level + 1;

                        // If the new word exists in the set
                        if(st.find(word) != st.end()) {

                            // Add it to the queue
                            q.push(word);

                            // Remove it so we don't visit it again
                            st.erase(word);
                        }
                    }

                    // Restore original character
                    word[i] = original;
                }
            }

            // Move to the next level
            level++;
        }

        // No transformation possible
        return 0;
    }
};