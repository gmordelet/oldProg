import java.util.Vector;

public class Compte {
	//Liste des attributs
	private String identifiant;
	private float solde;
	//cet attribut représente (sous forme d'un vecteur) une liste des mouvements effectués
	// sur le compte càd les retraits et les dépots
	private Vector mouvements;
	//Constructeur
	public Compte(String identifiant, float solde){
		this.identifiant = identifiant;
		this.solde = solde;
	}
	
	//Les get et les set pour accéder ou modifier les attributs privés
	String getIdentifiant() {
		return identifiant;
	}
	public void setIdentifiant(String s) {
		identifiant = s;
	}
	public float getSolde() {
		return solde;
	}
	public void setSolde(float x) {
		solde = x;
	}
	//Les autres méthodes
	//dépot d'un montant
	public void depot(float montant){
		solde += montant;
	}
	//retrait d'un montant
	public void retrait(float montant){
		solde -= montant;
	}
	//Afficher la liste des mouvements réalisés sur le compte
	public void afficherMouvements(){
		for(int i = 0; i < mouvements.size(); ++i) {
			System.out.println(mouvements.get(i));
		}
	}
	//Afficher l'identifiant et le solde du compte
	public void afficherCompte(){
		System.out.println("Identifiant = " + identifiant);
		System.out.println("Solde = " + solde);
	}
}