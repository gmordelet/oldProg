package world;

public class Light {
	Point coordinates;
	Voxel voxel;
	static WorldMatrix worldMatrix;
	
	public Light(Point p) {
		if(worldMatrix == null) {
			System.out.println("Erreur Light() : worldMatrix == null");
			System.exit(0);
		}
		coordinates = p;
		voxel = worldMatrix.returnVoxelFromXYZ(p.getX(), p.getY(), p.getZ());
	}
	
	public static void setWorldMatrix(WorldMatrix wm) {
		worldMatrix = wm;
	}
	
	public Point getCoordinates() {
		return coordinates;
	}
	
	public Voxel getVoxel() {
		return voxel;
	}
}
