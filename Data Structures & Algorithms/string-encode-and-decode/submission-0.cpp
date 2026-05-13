class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        // always encode start of string with the length
        // end the length with a NULL char
        for (int i = 0; i < strs.size(); i++) {
            res += std::to_string(strs[i].length()) + '\0';
            res += strs[i];
        }

        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;

        // we are guarenteed the start of a string contains the length + NULL
        int idx = 0;
        while (idx < s.length()) {
            string length;
            // get length
            while (s[idx] != '\0') {
                length += s[idx++];
            }
            // currently on NULL char
            idx++;

            string str;
            // build the string 
            for (int i = 0; i < std::stoi(length); i++) {
                str += s[idx++];
            }

            // push string to vector
            res.push_back(str);
        }

        return res;
    }
};
