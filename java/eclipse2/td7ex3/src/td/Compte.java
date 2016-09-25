package td;

public class Compte {
	private String titulaire;
	private int numero;
	private int solde;
	
	public Compte(String titulaire, int numero, int solde) {
		this.titulaire = titulaire;
		this.numero = numero;
		this.solde = solde;
	}
	
	public void depot(int somme) {
		solde += somme;
	}
	
	public void retrait(int somme) {
		solde -= somme;
	}
	
	public int consulterCompte() {
		return solde;
	}
	
	public boolean autorisationRetrait(int somme) {
		return somme <= solde;
	}
}
