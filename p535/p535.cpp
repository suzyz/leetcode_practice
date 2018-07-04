class Solution {
public:
    Solution() {
        srand(time(0));
    }
    
    const string BASE_HOST = "http://tinyurl/";

    map<string, string> longToShort;
    map<string, string> shortToLong;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (longToShort.count(longUrl)) {
            return longToShort[longUrl];
        }

        string tmp;

        do {
            tmp = BASE_HOST;
            for (int i = 0; i < 6; ++i)
            {
                int k = rand() % 62;
                if (k < 10) {
                    tmp += (k + '0');
                } else if (k < 36) {
                    tmp += (k - 10 + 'A');
                } else {
                    tmp += (k - 36 + 'a');
                }
            }
            
        } while(shortToLong.count(tmp));

        shortToLong[tmp] = longUrl;
        longToShort[longUrl] = tmp;

        return tmp;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortToLong.find(shortUrl) == shortToLong.end())
            return "";
        else
            return shortToLong[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
