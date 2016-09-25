public class Trinome {

	private double a,b,c;
	private double delta;
	private double r1, r2;

	public Trinome(double c1,double c2, double c3)
	{
		a = c1;
		b = c2;
		c = c3;
	}

	public void calculRacines()
	{
		delta = b * b - 4 * a * c;
		if(delta >= 0)
		{
			r1 = (-b - Math.sqrt(delta)) / (2 * a);
			r2 = (-b + Math.sqrt(delta)) / (2 * a);
		}
		else
			r1 = r2 = -1;
	}

	public void afficheRacines()
	{
		if(r1 == -1)
			System.out.println("Pas de racines");
		else
			System.out.println("r1 = " + r1 + " " + "r2 = " + r2);
	}
	
	public double getR1()
	{
		return this.r1;
	}
	public double getR2()
	{
		return this.r2;
	}
	
}