public class Test {
	public static void main(String[] args)
	{
		Liste l = new Liste();
		
		for(int i = 0; i <= 10; ++i)
		{
			l.addNum(i * i);
		}
		
		l.affList();
	}
}
