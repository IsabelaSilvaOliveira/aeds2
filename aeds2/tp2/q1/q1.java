import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

class Data {
	private int dia;
	private int mes;
	private int ano;
	Data parseData(String in) {
		Data a = new Data();
		String[] b = in.split("-");
		a.ano = Integer.parseInt(b[0]);
		a.mes = Integer.parseInt(b[1]);
		a.dia = Integer.parseInt(b[2]);
		
		return a;	
	} 
        String format(){
		String resp = String.format("%02d/%02d/%d",dia,mes,ano);

		return resp;
	}

}

class Veiculo {
	private int id;
	private String marca;
	private String modelo;
	private int ano;
	private String categoria;
	private String[] combustivel;
	private int cilindros;
	private double cilindrada;
	private String transmissao;
	private String tracao;
	private double consumoCidade;
	private double consumoEstrada;
	private double co2;
	private boolean turbo;
	private Data dataRegistro;
	Veiculo parseVeiculo( String in) {
		Veiculo a = new Veiculo();
		String b[] = in.split(",");
		a.id = Integer.parseInt(b[0]);
		a.marca = b[1];
		a.modelo = b[2];
		a.ano = Integer.parseInt(b[3]);
		a.categoria = b[4];
		a.combustivel = b[5].split(";");
		a.cilindros = Integer.parseInt(b[6]);
		a.cilindrada = Double.parseDouble(b[7]);
		a.transmissao = b[8];
		a.tracao = b[9];
		a.consumoCidade = Double.parseDouble(b[10]);
		a.consumoEstrada = Double.parseDouble(b[11]);
		a.co2 = Double.parseDouble(b[12]);
		a.turbo = Boolean.parseBoolean(b[13]);
		Data d = new Data();
		a.dataRegistro = d.parseData(b[14]);

		return a;
	}
	int getid () {
		return id;
	}
	String format() {
		String a = dataRegistro.format();
		String c = "";
		for(int i = 0; i < combustivel.length; i++) {
			c = c + combustivel[i];
			if( i < combustivel.length - 1) {
				c = c + ", ";
			}
		}

		String resp = String.format("[%d ## %s ## %s ## %d ## %s ## [%s] ## %d ## %f ## %s ## %s ## %f ## %f ## %f ## %b ## %s]",id,marca,modelo,ano,categoria,c,cilindros,cilindrada,transmissao,tracao,consumoCidade,consumoEstrada,co2,turbo,a);

		return resp;
	}
}

	 class LeitorCsv {
		Veiculo [] ler ( String carq) throws FileNotFoundException {
			File arq = new File(carq);
			if(arq.exists()){
				Scanner sc = new Scanner(arq);
				int c =0;
				sc.nextLine();
				for(c = 0; sc.hasNextLine(); c++)
				{ sc.nextLine();}
				sc.close();
				sc = new Scanner(arq);
				sc.nextLine();
				Veiculo[]  a = new Veiculo[c];
				int i =0;
				while(sc.hasNextLine()){
					String l = sc.nextLine();
					Veiculo b = new Veiculo();
					a[i] = b.parseVeiculo(l);
					i++;
				}
				return a;	


			}else{
				System.out.println("ERRO: Nao existe arquivo");
				return null;
			}
		}
	}


public class q1 {
public static void main (String[] args) throws FileNotFoundException {
	LeitorCsv b = new LeitorCsv();
	Veiculo[] a = b.ler("/tmp/veiculos.csv");
	Scanner sc = new Scanner(System.in);
	int f = sc.nextInt();
	while(f != -1){
		for(int i = 0; i< a.length; i++)
		{
			if(f == a[i].getid()) {
				String r = a[i].format();
				System.out.println(r);
			}
		}
		f = sc.nextInt();
	}
}
}
