import java.util.Scanner;

public class Valid {
        //metodo que testa se a senha contem todos os carecteres necessarios para ser valida
	public static boolean valida (String in) {
		boolean resp = true;
		int n = in.length();
		int c1 = 0;
		int c2 = 0;
		int c3 = 0;
		int c4 = 0;
		for(int i=0; i<n; i++) {
			char a = in.charAt(i);
			if( a>= 'A' && a<= 'Z') {
				c1++;
			}
			if( a>= 'a' && a<= 'z') {
				c2++;
			}
			if( a >= '0' && a<= '9') {
				c3++;
		       	}
			if( !(a>= 'A' && a<= 'Z') && !(a>='a' && a<='z') && !(a>='0' && a<='9')) {
				c4++;
			}
		}
			if(n<8)
			{ resp = false;
			}else if( c1 == 0 || c2 == 0 || c3 == 0 || c4 == 0)
			{ resp = false;
			}
		
			//System.out.println("c1:" + c1);
			//System.out.println("c2:" + c2);
			//System.out.println("c3:" + c3);
			//System.out.println("c4:" + c4);
		
		return resp;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String f = sc.nextLine();
		while( !(f.length() == 3 && f.charAt(0) == 'F' && f.charAt(1) == 'I' && f.charAt(2) == 'M')){
			if(valida(f)) {
				System.out.println("SIM");
			}else {
				System.out.println("NAO");
			}
		f = sc.nextLine();
		}
	}
}
/*Testes:
 * Senha123! = SIM
 * Senha1222 = NAO
 * SENHA12@2 = NAO
 * senha123$ = NAO
 * obs: tinha colocado parra ver quanto saia o c1,c2,c3 ec4 pois estava sempre dando nao, mas era porque o if com as condicoes estava dentro do for.
 */			

