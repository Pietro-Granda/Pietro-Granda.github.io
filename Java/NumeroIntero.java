public class NumeroIntero {
    public int numeroIntero;  // Variabile di istanza di tipo int
                              // Le variabili di tipo int non inizializzate valgono 0 per default

    public void stampaNumero() {
        // Metodo che stampa il valore della variabile numeroIntero
        System.out.println(10);
    }

    // Metodo main per eseguire il programma
    public static void main(String[] args) {
        NumeroIntero n = new NumeroIntero(); // Creazione di un oggetto della classe NumeroIntero
        n.stampaNumero();                    // Chiamata del metodo: stampa il valore della variabile
    }
}