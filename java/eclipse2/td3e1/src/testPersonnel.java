public class testPersonnel {
	public static void main(String[] args) 
	{
		int age;
		Personnel pers1 = new Personnel("Jean", 1989, "célibataire", "Paris", "homme");
		Personnel pers2 = new Personnel("Cécile", 1980, "en couple", "Versaille", "femme");

		pers1.afficheInfo();
		pers2.afficheInfo();
		
		age = pers1.age();
		System.out.println(age);
	}

}
