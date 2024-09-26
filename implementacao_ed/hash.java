package implementacao_ed;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

// Uso simples da ED HashMap.
// A intenção do programa é possibilitar a busca dos valores das recompensas de alguns personagens do mangá "One Piece" a partir de seus nomes.

public class hash{
    public static void main(String[] args) {

        Map<String, Long> hashMap = new HashMap<>();
        Scanner sc = new Scanner(System.in);

        hashMap.put("Gol D. Roger", 5564800000L);
        hashMap.put("Edward Newgate", 5046000000L);
        hashMap.put("Kaidou", 4611100000L);
        hashMap.put("Charlotte Linlin", 4388000000L);
        hashMap.put("Shanks", 4048900000L);
        hashMap.put("Marshall D. Teach", 3996000000L);
        hashMap.put("Dracule Mihawk", 3590000000L);
        hashMap.put("Buggy", 3189000000L);
        hashMap.put("Monkey D. Luffy", 3000000000L);
        hashMap.put("Trafalgar Law", 3000000000L);
        hashMap.put("Eustass Kid", 3000000000L);
        hashMap.put("Crocodile", 1965000000L);
        hashMap.put("Boa Hancock", 1659000000L);
        hashMap.put("King", 1390000000L);
        hashMap.put("Marco", 1374000000L);
        hashMap.put("Queen", 1320000000L);
        hashMap.put("Roronoa Zoro", 1111000000L);
        hashMap.put("Jinbe", 1100000000L);
        hashMap.put("Charlotte Katakuri", 1057000000L);
        hashMap.put("Vinsmoke Sanji", 1032000000L);
        hashMap.put("Jack", 1000000000L);
        hashMap.put("Charlotte Smoothie", 932000000L);
        hashMap.put("Nico Robin", 930000000L);
        hashMap.put("Charlotte Cracker", 860000000L);
        hashMap.put("Charlotte Perospero", 700000000L);
        hashMap.put("Sabo", 602000000L);
        hashMap.put("Charlotte Snack", 600000000L);
        hashMap.put("Portgas D. Ace", 550000000L);
        hashMap.put("Little Oars Jr.", 550000000L);
        hashMap.put("Who’s-Who", 546000000L);
        hashMap.put("Chinjao", 542000000L);
        hashMap.put("Izou", 510000000L);
        hashMap.put("Usopp", 500000000L);
        hashMap.put("Edward Weevil", 480000000L);
        hashMap.put("Black Maria", 480000000L);
        hashMap.put("Sasaki", 472000000L);
        hashMap.put("Belo Betty", 457000000L);
        hashMap.put("Tamago", 429000000L);
        hashMap.put("Karasu", 400000000L);
        hashMap.put("Ulti", 400000000L);
        hashMap.put("Franky", 394000000L);
        hashMap.put("Brook", 383000000L);
        hashMap.put("Pedro", 382000000L);
        hashMap.put("Nami", 366000000L);
        hashMap.put("Scratchmen Apoo", 350000000L);
        hashMap.put("Capone Bege", 350000000L);
        hashMap.put("Donquixote Doflamingo", 340000000L);
        hashMap.put("Cavendish", 330000000L);
        hashMap.put("Pekoms", 330000000L);
        hashMap.put("Basil Hawkins", 320000000L);
        hashMap.put("Gecko Moria", 320000000L);
        hashMap.put("Jewelry Bonney", 320000000L);
        hashMap.put("Lindbergh", 316000000L);
        hashMap.put("Caesar Clown", 300000000L);
        hashMap.put("Charlotte Daifuku", 300000000L);
        hashMap.put("Charlotte Oven", 300000000L);
        hashMap.put("Bartholomew Kuma", 296000000L);
        hashMap.put("Morley", 293000000L);
        hashMap.put("Page One", 290000000L);
        hashMap.put("Fisher Tiger", 230000000L);
        hashMap.put("X Drake", 222000000L);
        hashMap.put("Caribou", 210000000L);
        hashMap.put("Sai", 210000000L);
        hashMap.put("Squard", 210000000L);
        hashMap.put("Bartolomeo", 200000000L);
        hashMap.put("Killer", 200000000L);
        hashMap.put("Bellamy", 195000000L);
        hashMap.put("Coribou", 190000000L);
        hashMap.put("Orlumbus", 148000000L);
        hashMap.put("Charlotte Mont-d'Or", 120000000L);
        hashMap.put("Urouge", 108000000L);
        hashMap.put("Bobbin", 105500000L);
        hashMap.put("Emporio Ivankov", 100000000L);

        System.out.println("Deseja saber a recompensa de algum personagem de One Piece?");
        String personagem = sc.nextLine();
        if(!hashMap.containsKey(personagem)){
            System.out.println("Personagem não encontrado.");
        } else {
            System.out.println(hashMap.get(personagem) + " berrys.");
        }

        sc.close();
    }
}