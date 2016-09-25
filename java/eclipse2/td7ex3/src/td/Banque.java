package td;

public class Banque {
	private String nom;
	private String adresse;
	
	public Banque(String n, String a) {
		nom = n;
		adresse = a;
	}
	
	boolean transfert(int somme, Compte compteEnv, Compte compteRec) {
		if(compteEnv.autorisationRetrait(somme)) {
			compteEnv.retrait(somme);
			compteRec.depot(somme);
			return true;
		}			
		return false;
	}
}
