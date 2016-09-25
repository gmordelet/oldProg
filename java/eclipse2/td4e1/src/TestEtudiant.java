import etudiant.Etudiant;
import notation.Notation;



public class TestEtudiant {
	public static void main(String []args)
	{
		int numEtu = 5, numNote = 3;
		Etudiant []tabEtu = new Etudiant[5];
		double []tabNote = new double[numNote];
		int []tabCoef = new int[numNote];
		Notation [][]tabNota = new Notation[numEtu][numNote];
		
		for(int i = 0; i < numNote; ++i)
		{
			tabCoef[i] = (int)(5 * Math.random());
		}
		
		for(int i = 0; i < numEtu; ++i)
		{
			for(int j = 0; j < numNote; ++j)
				tabNote[j] = 20 * Math.random();
			
			for(int j = 0; j < numNote; ++j)
				tabNota[i][j] = new Notation(tabNote[j], tabCoef[j]);
			
			tabEtu[i] = new Etudiant("Etudiant" + (i + 1), tabNota[i]);		
			tabEtu[i].afficher();
		}	
	}
}
