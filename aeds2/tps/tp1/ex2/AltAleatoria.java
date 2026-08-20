import java.util.Scanner;
import java.util.Random;

public class AltAleatoria {
	static Random gerador = new Random();
	//metodo que ira receber a string, gerar 2 letras aleatoria, e ira substituir a primeira letra sorteada pela segunda em todoas suas aparicoes
	public static void alteracao (String in) {
		char l1 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
		System.out.println("Primeira letra sorteada: "+ l1);
		char l2 = (char)('a' + (Math.abs(gerador.nextInt()) % 26));
		System.out.println("Segunda letra sorteada: "+ l2);
		int n = in.length();
		for(int i = 0; i < n; i++) {
			char a = in.charAt(i);
			if( a == l1) {

			System.out.print(l2);
			}
			else {
			System.out.print(a);
			}
		}
		System.out.println();
		
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		gerador.setSeed(4);
		String f = sc.nextLine();
		while(!(f.length() == 3 && f.charAt(0) == 'F' && f.charAt(1) == 'I' && f.charAt(2) == 'M')) {

		alteracao(f);
		
		f = sc.nextLine();
		}
	}

}

/* testes:
 * amor (letra q e m) = amor
 * bariloche (letra r e v) = baviloche
 * lixo (letra v e d) = lixo
 * museu (letra e e u) = musuu
 * as letras aleatorias estavam se repitindo em cada string diferente, porque o new Random e o setSeed estava dentro do metodo que fazia a alteracao, entao deixei o new random como estatico e o setSeed no main e ai deu certo.
 */

