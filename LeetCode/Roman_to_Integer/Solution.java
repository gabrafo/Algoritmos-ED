package leetcode.Roman_to_Integer;

import java.util.HashMap;

class Solution {
    public int romanToInt(String s) {
        HashMap<String, Integer> map = new HashMap<>();
        map.put("I", 1);
        map.put("V", 5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);

        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            String key = s.substring(i, i+1); // Pega apenas o primeiro caractére
            int value = map.get(key);
            // Verifica se existe um próximo caractere antes de acessá-lo
            if (i + 1 < s.length()) {
                String nextKey = s.substring(i+1, i+2); // Pega o próximo caractere
                if (map.get(nextKey) != null && map.get(nextKey) > value) {
                    value *= -1;
                }
            }
            sum+=value;
        }

        return sum;
    }
}