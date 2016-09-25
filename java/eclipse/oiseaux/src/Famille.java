import java.util.ArrayList;
import java.lang.Math;

public class Famille {
	private ArrayList<Oiseau> list;
	
	public Famille() {
		list = new ArrayList<Oiseau>();
		
		for(int i = 0; i < 10; ++i) {
			if(Math.floor(Math.random() * 10) % 3 == 0) {
				list.add(new Merle());
			}
			if(Math.floor(Math.random() * 10) % 3 == 1) {
				list.add(new Pie());
			}
			else {
				list.add(new Corbeau());
			}
		}
	}
	
	public void decrire() {
		for(int i = 0; i < 10; ++i) {
			list.get(i).decrire();
		}
	}
}

interface Oiseau {
	void decrire();
}

class Merle implements Oiseau{
	public void decrire() {
		System.out.println("Je suis un merle");
	}
}

class Pie implements Oiseau{
	public void decrire() {
		System.out.println("Je suis une pie");
	}
}

class Corbeau implements Oiseau{
	public void decrire() {
		System.out.println("Je suis un corbeau");
	}
}