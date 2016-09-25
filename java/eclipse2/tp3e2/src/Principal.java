public class Principal {
	public static void main(String[] args) 
	{
		Individu ind1, ind2;
		ind1 = new Individu("Jean", "Paul");
		ind2 = new Individu("Marie", "Céline");
		
		ind1.marier(ind2);
		ind1.afficheInfo();
		ind2.afficheInfo();
	}

}
