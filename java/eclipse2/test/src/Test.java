import java.util.Vector;

public class Test {
	public static void main(String[] args) {
		Vector v = new Vector();
		for(int i = 0; i < 5; ++i) {
			v.add(i);
		}
		v.remove(0);
		System.out.println(v.get(4));
	}

}
