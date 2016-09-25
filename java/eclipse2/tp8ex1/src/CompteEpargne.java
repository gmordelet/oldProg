
public class CompteEpargne extends Compte{
	//Attributs
	private int annees;
	private float taux;
	//Constructeur
	public CompteEpargne (String identifiant,float solde,int annees,float taux){
		super(identifiant, solde);
		this.annees = annees;
		this.taux = taux;
	}
	//gets et sets
	public int getAnnees() {
		return annees;
	}
	public void setAnnees(int a) {
		annees = a;
	}
	public float getTaux() {
		return taux;
	}
	public void setTaux(float taux) {
		this.taux = taux;
	}
	//Méthode getSolde
	public float getSolde(){
		float solde = this.getSolde();
		return solde;
	}
}
