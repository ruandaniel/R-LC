class Solution {
public:
    unordered_map<string, string> LtoS;
    unordered_map<string, string> StoL;
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (LtoS.find(longUrl) != LtoS.end()) return LtoS[longUrl];
        string code;
        while(1){
            code = "http://tinyurl.com/";
            for (int i = 0; i < 6; i++){
                code += getChar(rand() % 62);
            }
            if (StoL.find(code) == StoL.end()){
                LtoS[longUrl] = code;
                StoL[code] = longUrl;
                break;
            }
        }
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (StoL.find(shortUrl) != StoL.end()) return StoL[shortUrl];
        else return "";
    }
    
    char getChar(int x){
        if (x < 26) return 'a' + x;
        else if (x < 52) return 'A' + x - 26;
        else return '0' + x - 52;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));