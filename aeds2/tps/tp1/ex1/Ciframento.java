import java.util.Scanner;

public class Ciframento {

        //metodo para pegar o caracter lido e pular 3 posicoes
	public static void cifrar(String in) {
		int n = in.length();

		for(int i = 0; i < n; i++) {
			char nl = (char) + (in.charAt(i) + 3);
			System.out.print(nl);
		}
		System.out.println();
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String f = sc.nextLine();
		while(!(f.length() == 3 && f.charAt(0) == 'F' && f.charAt(1) == 'I' && f.charAt(2) == 'M')) {

		cifrar(f);

		f = sc.nextLine();

		}
	
	}
}

/* testes:
 * aca = dfd
 * amor = dpru
 * Leal Lael = Ohdo#Odho
 * Isabela Silva = Lvdehod#Vloyd
 * programa deu certo, mas acho para melhorar ele seria verificando se tem linha pra ler antes de entrar no metodo para cifrar.
 */
