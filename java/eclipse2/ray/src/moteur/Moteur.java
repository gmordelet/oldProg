package moteur;

import world.*;
import graphic.*;

public class Moteur {
	public static void main(String[] args) {
		test(false);
		WorldMatrix worldMatrix = new WorldMatrix(50, 40, 40, 100);
		Ray.setWorldMatrix(worldMatrix);
		worldMatrix.createWorld();
		Screen screen = new Screen(800, 800, 500, worldMatrix);
		screen.printScreen();

		System.out.println("ok");
	}

	static void test(boolean b) {
		if(!b) {
			return;
		}
		Point pRay1, pRay2, pInter;
		Ray ray;
		WorldMatrix worldMatrix = new WorldMatrix(2, 4, 4, 4);
		Ray.setWorldMatrix(worldMatrix);
		pRay1 = new Point(1, 0, 0);
		pRay2 = new Point(2, 0, 1);
		ray = new Ray(pRay1, pRay2);
		System.out.println(ray.displayRay());
		pInter = ray.interRayVoxel(worldMatrix.getMatrix()[3][2][1]);
		System.out.println(worldMatrix.getMatrix()[3][2][1].displayVoxelCoordinates());
		pInter.displayPoint();
		
		System.exit(0);
	}

}
