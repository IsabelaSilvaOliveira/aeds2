import java.util.Scanner;

public class Is {
	public static boolean vogais(String in) {
		boolean resp = true;
		int n = in.length();
		for(int i = 0; i<n; i++) {
			char a = in.charAt(i);
			if( (a >= '0' && a <= '9') || ( a!= 'a' && a!='e' &&  a!='i' && a!='o' &&  a!='u'))  {
						resp = false;
			}
		}
		return resp;
	}
	public static boolean consoantes(String in) {
		boolean resp = true;
		int n = in.length();
		for (int i = 0; i < n; i++) {
			char a = in.charAt(i);
			if((a>= '0' && a<= '9') || a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ) {
				resp = false;
			}
		}
		return resp;
	}
	public static boolean inteiro(String in) {
		boolean resp = true;
		int n = in.length();
		for ( int i =0; i < n; i++ ) {
			char a = in.charAt(i);
			if( !(a >= '0' && a <= '9')) {
				resp = false;
			}
		}
		return resp;
	}
	public static boolean real(String in) {
                boolean resp = true;
		int c = 0;
		int n = in.length();
		for( int i = 0;i< n; i++) {
			char a = in.charAt(i);
			if( a == '.' || a == ',') {
				c++;
			}
			else if( !(a >= '0' && a<= '9')) {
				resp = false;
			}
		}
		if ( c > 1) {
		resp = false;
		}
		return resp;
	}
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String f = sc.nextLine();
		while(!(f.length() == 3 && f.charAt(0) == 'F' && f.charAt(1) == 'I' && f.charAt(2) == 'M')) {
			if(vogais(f)){
				System.out.print("SIM");
				System.out.print(" ");
			}
			else { System.out.print("NAO");
		               System.out.print(" ");	}
			if(consoantes(f)) {
				System.out.print("SIM");
				System.out.print(" ");
			}
			else { System.out.print("NAO");
		               System.out.print(" ");	}
			if(inteiro(f)) {
				System.out.print("SIM");
				System.out.print(" ");
			}
			else { System.out.print("NAO");
		               System.out.print(" ");	}
			if(real(f)) {
				System.out.print("SIM");
				System.out.print(" ");
				System.out.println();
			}
			else {System.out.print("NAO");
		              System.out.println();	}
			f = sc.nextLine();
		}
	}
}



				

