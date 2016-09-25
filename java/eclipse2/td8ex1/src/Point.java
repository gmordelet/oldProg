import java.lang.Math;

public class Point {
	//Attributs
	private float x;
	private float y;
	//Constructeurs
	public Point(float x, float y) {
		this.x = x;
		this.y = y;
	}
	public Point() {
		this(0, 0);
	}
	//get
	public float getX() {
		return x;
	}
	public float getY() {
		return y;
	}
	//Autres méthodes
	//Distance entre le point courant et le point passé en argument
	public float distance(Point p) {
		return (float)Math.sqrt(Math.pow(x - p.x, 2) + Math.pow(y - p.y, 2));
	}
	//Redéfinition de la méthode toString() (de la classe Object)
	//pour avoir une chaine de la forme "(x,y)"
	public String toString() {
		String s = new String("(" + x + ", " + y + ")");
		return s;
	}
	public void affiche() {
		System.out.println(this.toString());
	}
}


