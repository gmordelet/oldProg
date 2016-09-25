package world;

public class Point {
	private float x, y, z;
	
	public Point(float x, float y, float z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public float getX() {
		return x;
	}
	
	public float getY() {
		return y;
	}
	
	public float getZ() {
		return z;
	}
	
	public void setX(float x) {
		this.x = x;
	}
	
	public void setY(float y) {
			this.y = y;
		}
	
	public void setZ(float z) {
		this.z = z;
	}
	
	public void setXYZ(float x, float y, float z) {
		this.x = x;
		this.y = y;
		this.z = z;
	}
	
	public boolean equals(Point p) {
		return x == p.x && y == p.y && z == p.z;
	}
	
	public String displayPoint() {
		return "Point : x = " + x + " y = " + y + " z = " + z;
	}
}
