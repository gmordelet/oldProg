package world;

//import java.lang.Math;

public class Ray {
	private float x0, x1x0, y0, y1y0, z0, z1z0;
	//private float k;
	int curVoxelX, curVoxelY, curVoxelZ;
	private static WorldMatrix worldMatrix;

	public Ray(Point p0, Point p1) {
		//float max;
		int[] curVoxelXYZ;
		x0 = p0.getX();
		x1x0 = p1.getX() - p0.getX();
		y0 = p0.getY();
		y1y0 = p1.getY() - p0.getY();
		z0 = p0.getZ();
		z1z0 = p1.getZ() - p0.getZ();
		curVoxelXYZ = worldMatrix.getVoxelXYZ(p1.getX(), p1.getY(), p1.getZ());
		if(curVoxelXYZ != null) {
			curVoxelX = curVoxelXYZ[0];
			curVoxelY = curVoxelXYZ[1];
			curVoxelZ = curVoxelXYZ[2];
		}
		/*
		max = Math.max(Math.max(x1x0, y1y0), z1z0);
		x1x0 /= max;
		y1y0 /= max;
		z1z0 /= max;
		 */
		//this.k = max;	
	}

	public Ray(Point p0, Point p1, boolean dP0) {
		//float max;
		int[] curVoxelXYZ;
		x0 = p0.getX();
		x1x0 = p1.getX() - p0.getX();
		y0 = p0.getY();
		y1y0 = p1.getY() - p0.getY();
		z0 = p0.getZ();
		z1z0 = p1.getZ() - p0.getZ();
		if(dP0) {
			curVoxelXYZ = worldMatrix.getVoxelXYZ(p0.getX(), p0.getY(), p0.getZ());
			if(curVoxelXYZ != null) {
				curVoxelX = curVoxelXYZ[0];
				curVoxelY = curVoxelXYZ[1];
				curVoxelZ = curVoxelXYZ[2];
			}
		}
		else {
			curVoxelXYZ = worldMatrix.getVoxelXYZ(p1.getX(), p1.getY(), p1.getZ());
			if(curVoxelXYZ != null) {
				curVoxelX = curVoxelXYZ[0];
				curVoxelY = curVoxelXYZ[1];
				curVoxelZ = curVoxelXYZ[2];
			}
		}
	}


	/*	
	public Ray(Point p0, Point p1, float k) {
		float max;
		x0 = p0.getX();
		x1x0 = p1.getX() - p0.getX();
		y0 = p0.getY();
		y1y0 = p1.getY() - p0.getY();
		z0 = p0.getZ();
		z1z0 = p1.getZ() - p0.getZ();
		max = Math.max(Math.max(x1x0, y1y0), z1z0);
		x1x0 /= max;
		y1y0 /= max;
		z1z0 /= max;
		this.k = k;
	}
	 */

	public Voxel rayCasting(/*float precision*/){
		int stepX, stepY, stepZ, voxelLength;
		float kX, kY, kZ;

		voxelLength = worldMatrix.getVoxelLength();
		stepX = (x1x0 >= 0) ? 1 : -1;
		stepY = (y1y0 >= 0) ? 1 : -1;
		stepZ = (z1z0 >= 0) ? 1 : -1;

		kX = (curVoxelX + stepX * voxelLength + x0) / x1x0;
		kY = (curVoxelY + stepY * voxelLength + y0) / y1y0;
		kZ = (curVoxelZ + stepZ * voxelLength + z0) / z1z0;

		if(kX < kY) {
			if(kX < kZ) {
				curVoxelX += stepX * voxelLength;
				return worldMatrix.returnVoxelFromXYZ(curVoxelX, curVoxelY, curVoxelZ);
			}
			else {
				curVoxelZ += stepZ * voxelLength;
				return worldMatrix.returnVoxelFromXYZ(curVoxelX, curVoxelY, curVoxelZ);
			}
		}
		else {
			if(kY < kZ) {
				curVoxelY += stepY * voxelLength;
				return worldMatrix.returnVoxelFromXYZ(curVoxelX, curVoxelY, curVoxelZ);
			}
			else {
				curVoxelZ += stepZ * voxelLength;
				return worldMatrix.returnVoxelFromXYZ(curVoxelX, curVoxelY, curVoxelZ);
			}
		}

		/*
		float currentX, currentY, currentZ, dk;
		int[] currentVoxelIndex, newVoxelXYZ;
		Voxel currentVoxel, newVoxel;
		dk = precision * worldMatrix.getVoxelLength();
		currentX = k * (x1x0) + x0;
		currentY = k * (y1y0) + y0;
		currentZ = k * (z1z0) + z0;
		currentVoxel = worldMatrix.returnVoxelFromXYZ(currentX, currentY, currentZ);

		do {
			k += dk;
			newVoxel = worldMatrix.returnVoxelFromXYZ(k * (x1x0) + x0,
					k * (y1y0) + y0,
					k * (z1z0) + z0);
			if(newVoxel == null) {
				return null;
			}
		}while(currentVoxel == newVoxel);

		return newVoxel;
		 */

	}

	public static void setWorldMatrix(WorldMatrix worldMatrixSrc) {
		worldMatrix = worldMatrixSrc;
	}

	public Point interRayVoxel(Voxel voxel) {
		float xLim, yLim, zLim, k, kTemp;
		int voxelLength;
		Point point;

		k = 0;
		voxelLength = worldMatrix.getVoxelLength();

		if(this.getX0() < voxel.getX() || this.getX0() > voxel.getX() + voxelLength) {
			xLim = (this.getX1x0() > 0) ? voxel.getX() : voxel.getX() + voxelLength;
			k = (xLim - this.getX0()) / this.getX1x0();
		}

		if(this.getZ0() < voxel.getZ() || this.getZ0() > voxel.getZ() + voxelLength) {
			zLim = (this.getZ1z0() > 0) ? voxel.getZ() : voxel.getZ() + voxelLength;
			kTemp = (zLim - this.getZ0()) / this.getZ1z0();	
			k = (kTemp > k) ? kTemp : k;
		}

		if(this.getY0() < voxel.getY() || this.getY0() > voxel.getY() + voxelLength) {
			yLim = (this.getY1y0() > 0) ? voxel.getY() : voxel.getY() + voxelLength;
			kTemp = (yLim - this.getY0()) / this.getY1y0();
			k = (kTemp > k) ? kTemp : k;
		}

		point = new Point(this.getX1x0() * k + this.getX0(),
				this.getY1y0() * k + this.getY0(),
				this.getZ1z0() * k + this.getZ0());

		return point;
	}

	public String displayRay() {
		return "x0 = " + x0 + " x1x0 = " + x1x0 + " | y0 = " + y0 + " y1y0 = " + y1y0 + " | z0 = " + z0 + " z1z0 = " + z1z0 /*+ " | k = " + k*/;
	}

	public float getX0(){
		return x0;
	}

	public float getX1x0(){
		return x1x0;
	}

	public float getY0(){
		return y0;
	}

	public float getY1y0(){
		return y1y0;
	}

	public float getZ0(){
		return z0;
	}

	public float getZ1z0(){
		return z1z0;
	}

	public int getCurVoxelX() {
		return curVoxelX;
	}
	
	public int getCurVoxelY() {
		return curVoxelY;
	}
	
	public int getCurVoxelZ() {
		return curVoxelZ;
	}
	/*
	public float getK(){
		return k;
	}
	 */
}