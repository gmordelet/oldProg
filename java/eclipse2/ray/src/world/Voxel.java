package world;

import java.awt.Color;

public class Voxel {
	private int x1, y1, z1;
	private Color color;
	
	public Voxel(int x1, int y1, int z1) {
		this.x1 = x1;
		this.y1 = y1;
		this.z1 = z1;
		color = null;
	}
	
	public Voxel(int x1, int y1, int z1, Color color) {
		this(x1, y1, z1);
		this.color = color;
	}
	
	public String displayVoxelCoordinates() {
		return "x1 = " + x1 + " y1 = " + y1 + " z1 = " + z1;
	}
	
	public int getX() {
		return x1;
	}
	
	public int getY() {
		return y1;
	}
	
	public int getZ() {
		return z1;
	}
	
	public void setColor(Color color) {
		this.color = color;
	}
	
	public Color getColor() {
		return color;
	}
}