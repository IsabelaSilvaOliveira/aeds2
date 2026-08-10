import java.util.Scanner;

public class Exercicio2 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
                int num1 = input.nextInt();
		int num2 = input.nextInt();
		int resultado = num1 + num2;
		System.out.printf("Soma=%d\n", resultado);
		input.close();
	}
}
