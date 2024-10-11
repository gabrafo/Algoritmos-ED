package implementacao_algoritmos;

import java.util.ArrayList;
import java.util.List;

public class dc_recursao{
    public static int soma(List<Integer> lista){

        if(lista.isEmpty()){ // Caso-base: Tamanho zero
            return 0;
        }

        List<Integer> sublista = lista.subList(1, lista.size());

        // Linhas 16-21 servem apenas para debug do método e podem ser ignoradas
        System.out.println("Valor do primeiro elemento de 'lista': " + lista.get(0));
        System.out.println("Valor dos elementos restantes de 'lista': ");
        for(int i = 0; i<lista.subList(1, lista.size()).size(); i++){
            System.out.println(sublista.get(i));
        }
        System.out.println();

        return lista.get(0) + soma(sublista); // Caso-recursivo: Passo uma sublista como parâmetro que vai do segundo elemento até o último
    }

    public static void main(String[] args) {
        List<Integer> lista = new ArrayList<>();
        lista.add(0, 2); // Index, Elemento
        lista.add(1, 4);
        lista.add(2, 6);
        System.out.println("Resultado final = " + soma(lista));
    }
}