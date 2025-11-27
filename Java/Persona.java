import java.util.Scanner;

public class Persona {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.print("Inserisci il nome: ");
        String nome = input.nextLine();

        System.out.print("Inserisci il cognome: ");
        String cognome = input.nextLine();

        System.out.println("Nome: " + nome + " | Cognome: " + cognome);

        input.close();
    }
}
