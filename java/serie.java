public class serie
{
    public static void main(String args[])
    {
	int n = Clavier.lireInt();
	float serie = 0;

	while(n > 0)
	    serie += 1f/n--;

	System.out.println("serie = " + serie);
    }
}