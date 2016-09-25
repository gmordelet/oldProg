package main;
import extract.Chaine;

public class Test {
	public static void main(String[] argv)
	{
		String s = "salut salut ca va ? va ca, bye, bisous, bye";
		Chaine test = new Chaine(s);
		System.out.println("s = " + s);
		test.afficherMots();
	}
}
