package etudiant;

import java.lang.Comparable;

public class Etudiant implements Comparable<Etudiant>{
	private String nom;
	
	public Etudiant(String nom) {
		this.nom = nom;
	}
	
	public String getNom() {
		return nom;
	}
	
	public int compareTo(Etudiant etu) {
		return nom.compareTo(etu.getNom());
	}
}
