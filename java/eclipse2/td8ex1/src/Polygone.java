public class Polygone {
	//Attribut
	private Point[] sommets;
	//Constructeurs
	public Polygone(Point[] sommets) {
		this.sommets = sommets;
	}
	public Polygone(int nbSommets) {
		sommets = new Point[nbSommets];
	}
	//Méthodes
	//Ajoute un sommet dans le tableau sommets
	public void setUnSommet(Point p, int pos){
		sommets[pos] = p;
	}
	//mettre à jour tous les sommets
	public void setSommets(Point[] sommets){
		this.sommets = sommets;
	}
	//Retourne le nom de la figure (Polygone dans le cas présent)
	protected String nomFigure() {
		String s = new String("Polygone");
		return s;
	}
	//Retourne le nombre de sommets
	public int nombreDeSommets() {
		return sommets.length;
	}
	//retourne une chaine contenant les coordonnées des sommets
	//Elle se présente sous la forme : "Polygone : [(0.0,0.0) (2.0,0.0)
	//(2.0,2.0) (0.0,2.0) ]"
	public String toString() {
		StringBuffer s = new StringBuffer("Polygone : [");
		for(int i = 0; i < sommets.length; ++i) {
			s.append("(" + sommets[i].toString() + ") ");			
		}
		s.append("]");
		return s.toString();
			
	}
	//Affiche les coordonnées des sommets
	public void affiche(){
		System.out.println(this.toString());
	}
	//Calcul le périmètre (somme des côtés) du polygone
	public float perimetre() {
		float p = 0;
		int i;
		for(i = 0; i < sommets.length - 1; ++i) {
			p += sommets[i].distance(sommets[i + 1]);
		}
		p += sommets[i].distance(sommets[0]);
		return p;
	}
}

class Rectangle extends Polygone{
	public Rectangle(Point p1, Point p2) {
		super(4);
		Point[] sommets = new Point[4];
		sommets[0] = p1;
		sommets[1] = new Point(p2.getX(), p1.getY());
		sommets[2] = p2;
		sommets[3] = new Point(p1.getX(), p2.getY());
		this.setSommets(sommets);
	}
}