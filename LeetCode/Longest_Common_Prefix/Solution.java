class Solution {

    public int encontrarPosMenorPalavra(String[] strs){
        int posMenor = 0;
        int menor = strs[0].length();
        for(int i = 1; i<strs.length; i++){
            if(strs[i].length() < menor){
                posMenor = i;
                menor = strs[i].length();
            }
        }
        return posMenor;
    }

    public int contadorLetrasIguais(String[] strs) {
        if (strs == null || strs.length == 0) {
            return 0;
        }

        int score = 0;
        int posicaoMax = encontrarPosMenorPalavra(strs);

        for (int i = 0; i < strs[posicaoMax].length(); i++) {
            char charAtual = strs[posicaoMax].charAt(i);

            for (int j = 0; j < strs.length; j++) {
                if (strs[j].charAt(i) != charAtual) {
                    return score;
                }
            }
            score++;
        }
        
        return score;
    }

    public String longestCommonPrefix(String[] strs) {
       int score = contadorLetrasIguais(strs);
        if (score == 0 && strs.length > 0 && strs[0].length() == 0) {
            return ""; // Se a primeira string for vazia, o prefixo comum também é vazio
        } else {
                String prefixo = "";
                for(int i = 0; i<score; i++){
                    prefixo+=strs[0].charAt(i);
                }
                return prefixo;
        }
    }
}

// Complexidade O(n*m), onde n é o número de elementos no vetor e m é o comprimento da menor string no array.