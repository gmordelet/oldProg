package notation;

public class Notation {
	private double note;
	private int coef;
	
	public Notation(double note, int coef)
	{
		this.note = note;
		this.coef = coef;
	}
	
	public double getNote()
	{
		return note;
	}
	
	public int getCoef()
	{
		return coef;
	}
	
	public void affNote()
	{
		System.out.println("Note : " + getNote());
	}
	
	public void affCoef()
	{
		System.out.println("Coef : " + getCoef());
	}
	
	
}
