import java.lang.StringBuffer;

public class Main {
	public static void main(String[] args) {
		String str = Saisie.lireChaine("Mot à traiter ?");
		StringBuffer strVoy = new StringBuffer();
		StringBuffer strCons = new StringBuffer();
		char c;
		for(int i=0; i<str.length();i++){
			c= str.charAt(i);
			if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')
				strVoy.append(c);
			else if ((c>='A'&& c<='Z')||(c>='a'&& c<='z'))
				strCons.append(c);
		}
		System.out.println("Les voyelles : " + strVoy);
		System.out.println("Les consonnes : " + strCons);
	}
}
