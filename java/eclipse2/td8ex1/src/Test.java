
public class Test {
	public static void main(String[] args) {
		Point[] sommets = new Point[4];
		sommets[0] = new Point(-1, -1);
		sommets[1] = new Point(0, 0);
		Rectangle r = new Rectangle(sommets[0], sommets[1]);
		System.out.println(r.perimetre());
	}
}
