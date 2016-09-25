package td;

public class TestBanque {
	public static void main(String[] argv) {
		Compte c1 = new Compte("Roger Con", 1, 200);
		Compte c2 = new Compte("Momo Gay", 2, 300);
		Banque queban = new Banque("BNP", "Paris");
		System.out.println("Opé 1 : " + queban.transfert(150, c1, c2));
		System.out.println("Opé 2 : " + queban.transfert(50, c1, c2));
		System.out.println("Opé 3 : " + queban.transfert(2000, c2, c1));
	}
}
