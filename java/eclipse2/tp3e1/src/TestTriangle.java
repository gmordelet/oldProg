public class TestTriangle {
	public static void main(String[] args) 
	{
		Triangle triangle = new Triangle(0, 0, 2, 0, 0, 2);
		triangle.afficherTriangle();
		System.out.println(triangle.estIsocele());
	}
}

