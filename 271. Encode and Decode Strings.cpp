class Codec {
public:
    //method1: length + @ + str
    //method2: Double any hashes inside the strings and add a space between words

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto str : strs){
            res += to_string(str.size()) + "@" + str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        if (s == "") return {};
        vector<string> res;
        int i = 0;
        int j = 0;
        while (j < s.size()){
            i = j;
            while (s[j] != '@') j++;
            int len = atoi(s.substr(i, j-i).c_str());
            res.push_back(s.substr(++j, len));
            j += len;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));