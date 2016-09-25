import javax.swing.JOptionPane;

public class TestTrinome {
	public static void main(String[] args) 
	{
		double a, b, c, r1, r2;
		
		a = b = c = r1 = r2 = 0;

		System.out.println("Utilisation de la classe JOptionPane !!!");
		String s = JOptionPane.showInputDialog("Valeur de a ?");
		if(s!=null){
		a = Integer.parseInt(s);// conversion d'une chaine en entier
		}
		System.out.println("Utilisation de la classe JOptionPane !!!");
		s = JOptionPane.showInputDialog("Valeur de b ?");
		if(s!=null){
		b = Integer.parseInt(s);// conversion d'une chaine en entier
		}
		System.out.println("Utilisation de la classe JOptionPane !!!");
		s = JOptionPane.showInputDialog("Valeur de c ?");
		if(s!=null){
		c = Integer.parseInt(s);// conversion d'une chaine en entier
		}
		
		Trinome tri = new Trinome(a, b, c);
		tri.calculRacines();
		r1 = tri.getR1();
		r2 = tri.getR2();
		
		JOptionPane.showMessageDialog(null, "Racine1 = " + r1 + "\n" + "Racine2 = " + r2);
	}

}
