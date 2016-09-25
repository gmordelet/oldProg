public class Triangle {
	private Point a, b, c;
	
	public Triangle(double xA, double yA, double xB, double yB, double xC, double yC)
	{
		a = new Point(xA, yA);
		b = new Point(xB, yB);
		c = new Point(xC, yC);
	}
	
	public void afficherTriangle()
	{
		System.out.print("a : ");
		a.afficherXY();
		System.out.print("b : ");
		b.afficherXY();
		System.out.print("c : ");
		c.afficherXY();
	}
	
	public boolean estIsocele()
	{
		double dAB, dAC, dCB, xA, yA, xB, yB, xC, yC;
		
		xA = this.a.getX();
		yA = this.a.getY();
		xB = this.b.getX();
		yB = this.b.getY();
		xC = this.c.getX();
		yC = this.c.getY();
				
		dAB = Math.sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
		dAC = Math.sqrt((xA - xC) * (xA - xC) + (yA - yC) * (yA - yC));
		dCB = Math.sqrt((xC - xB) * (xC - xB) + (yC - yB) * (yC - yB));		
		
		return dAB == dAC || dAB == dCB || dAC == dCB;
	}
}