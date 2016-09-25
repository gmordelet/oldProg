public class Personnel {
	private String nom;
	private int annee;
	private String situation;
	private String adresse;
	private String sexe;
	
	public Personnel(String nom, int annee, String situation, 
			String adresse, String sexe)
	{
		this.nom = nom;
		this.annee = annee;
		this.situation = situation;
		this.adresse = adresse;
		this.sexe = sexe;
	}
	
	public void afficheInfo()
	{
		String pronom, ne;
		if(sexe.equals("homme"))
		{
			pronom = "il";
			ne = "ne";
		}
		else
		{
			pronom = "elle";
			ne = "nee";
		}
		System.out.println(nom + " est " + ne + " en " + annee + ", " + pronom + " est "
				+ situation + " et habite à " + adresse);
	}
	
	public int age()
	{
		return 2014 - annee;
	}
}
