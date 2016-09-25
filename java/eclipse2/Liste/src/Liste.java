public class Liste{
	private Element element;
	
	public Liste()
	{
		element = null;
	}
	
	public void addNum(int num)
	{
		Element t1 = element;
		Element t2 = null;
		Element newElement = new Element(num, null);
			
		if(t1 == null)
			this.element = newElement;
		else
			{
				while(t1 != null)
					{
						t2 = t1;
						t1 = t1.getNext();
					}
		
				t2.setNext(newElement);
			}
	}
	
	public void affList()
	{
		Element t = element;
		
		while(t != null)
		{
			System.out.println(t.getNum());
			t = t.getNext();			
		}
	}
	
	public boolean getElement(int numElement)
	{
		
		return true;
	}
}

class Element{
	private int num;
	private Element next;
	
	public Element(int num, Element next)
	{
		this.num = num;
		this.next = next;
	}
	
	void setNext(Element next)
	{
		this.next = next;
	}
	
	void setNum(int num)
	{
		this.num = num;
	}
	
	Element getNext()
	{
		return next;
	}
	
	int getNum()
	{
		return num;
	}
}
