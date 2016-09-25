package etudiant;

public class testEtudiant {
	public static void main(String[] args) {
		Etudiant etu1, etu2, etu3;
		
		etu1 = new Etudiant("Jean");
		etu2 = new Etudiant("François");
		etu3 = new Etudiant("Jean");
		
		System.out.println(etu1.compareTo(etu2));
		System.out.println(etu1.compareTo(etu3));
		System.out.println(etu2.compareTo(etu3));

	}
}
