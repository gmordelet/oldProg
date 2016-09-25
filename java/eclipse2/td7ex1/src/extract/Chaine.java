package extract;

import java.util.Vector;
import java.util.StringTokenizer;

public class Chaine {
	private String phrase;
	private Vector<String> mots;
	
	public Chaine(String phrase) {
		this.phrase = phrase;
		mots = new Vector<String>();
		extraireMots();
	}
	
	public void extraireMots() {
		StringTokenizer st = new StringTokenizer(phrase, " ,;?");
		String s;
		boolean isIn;
		
		while(st.hasMoreElements()) {
			s = st.nextToken();
			isIn = false;
			for(int i = 0; i < mots.size() && !isIn; ++i) {
				isIn = s.equals(mots.get(i));
			}
			if(!isIn) {
				mots.add(s);
			}
		}
	}
	
	public void afficherMots() {
		for(int i = 0; i < mots.size(); ++i) {
			System.out.print(mots.get(i) + " ");
		}			
		System.out.println();
	}
}
