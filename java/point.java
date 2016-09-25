public class point
{
    private double x, y, z;
    
    public void init(double px, double py, double pz)
    {
	x = px;
	y = py;
	z = pz;
    }

    public static int visible(point a, point b)
    //retourne 0 si les 2 points sont visibles
    //1 si le point a est devant le point b
    //-1 si le point b est devant le point b
    {
	double div;

	div = a.x / b.x;
	
	if(b.y * div != a.y)
	    return 0;
	if(b.z * div != a.z)
	    return 0;
	if(div < 1)
	    return 1;
	if(div > 1)
	    return -1;
	return 2;
    }
}