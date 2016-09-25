package etudiant;
import notation.Notation;

public class Etudiant {
	private String nom;
	private double moyenne;
	private String avis;
	private Notation []notes;
	
	public Etudiant(String nom, Notation []notes)
	{
		this.nom = nom;
		this.notes = notes;
		moyenne = moyenne(notes);
		this.avis = Etudiant.avis(moyenne);
	}
	
	private double moyenne(Notation []notes)
	{
		int i = notes.length - 1;
		double sumNote = 0;
		int sumCoef = 0;
		
		while(i >= 0)
		{		
			sumNote += notes[i].getNote() * notes[i].getCoef();
			sumCoef += notes[i].getCoef();
			--i;
		}
		
		return sumNote / sumCoef;
	}
	
	static String avis(double moyenne)
	{
		if(moyenne < 10)
			return "passable";
		if(moyenne >= 10 && moyenne < 12)
			return "assez bien";
		if(moyenne >= 12 && moyenne < 14)
			return "bien";
		return "très bien";
	}
	
	public void afficher()
	{
		System.out.println(nom + ", Moyenne : " + moyenne + ", avis :" + avis);
	}
	
}
