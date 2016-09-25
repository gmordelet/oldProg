public class Individu {
	private String nom, prenom;
	private Individu conjoint;
	
	public Individu(String nom, String prenom, Individu conjoint)
	{
		this.nom = nom;
		this.prenom = prenom;
		this.conjoint = conjoint;
	}
	
	public Individu(String nom, String prenom)
	{
		this(nom, prenom, null);
	}
	public Individu()
	{
		this(null, null, null);
	}
	
	void marier(Individu ind)
	{
		this.conjoint = ind;
		ind.conjoint = this;
	}
	
	void afficheInfo()
	{
		System.out.println(prenom + " " + nom + " conjoint : " + conjoint.nom + " " + conjoint.prenom);
	}
}
