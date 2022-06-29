public class Codec {
    Map<String, String> map = new HashMap<>();
    static final String INDEX = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static final String PREFIX = "http://tinyurl.com";

    // Encodes a URL to a shortened URL.
    public String encode(String longUrl) {
        char[] chs = new char[6];
        while(true) {
            for(int i = 0; i < 6; i++) {
                chs[i] = INDEX.charAt((int)(Math.random() * 62));
            }
            String shortUrl = PREFIX + chs;
            if(!map.containsKey(shortUrl)) {
                map.put(shortUrl, longUrl);
                return shortUrl;
            }
        }
    }

    // Decodes a shortened URL to its original URL.
    public String decode(String shortUrl) {
        return map.get(shortUrl);
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.decode(codec.encode(url));