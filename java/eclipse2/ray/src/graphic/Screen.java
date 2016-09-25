package graphic;

import world.*;
import javax.swing.JFrame;
import java.awt.Graphics;
import javax.swing.JPanel;
import java.awt.Color;
import java.util.Vector;

public class Screen {
	private int width, height, distZ;
	private Ray[][] screenRays;
	private WorldMatrix worldMatrix;
	
	public Screen(int width, int heigth, int distZ, WorldMatrix worldMatrix) {
		System.out.println("Debut initialisation Screen");
		Point p0, p1;

		this.width = width;
		this.height = heigth;
		this.distZ = distZ;
		this.worldMatrix = worldMatrix;
		p0 = new Point(0, 0, -this.distZ);
		p1 = new Point(0, 0, 0);
		screenRays = new Ray[width][heigth];
		for(int x = 0; x < width; ++x) {
			for(int y = 0; y < heigth; ++y) {
				p1.setXYZ(-width / 2 + x, heigth / 2 - y, 0);
				screenRays[x][y] = new Ray(p0, p1);
			}
		}
		System.out.println("Fin initialisation Screen");
	}

	public void printScreen() {
		JFrame window = new JFrame();
		Graphics g;
		JPanel panel = new JPanel();
		window.setSize(width, height);
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);	
		window.setContentPane(panel);	
		window.setVisible(true);
		g = panel.getGraphics();
		Voxel voxelBuff;
		Color colorBuff;
		float x0, x1x0, y0, y1y0, z0, z1z0, k, curX, curY, curZ;
		int[] firstVoxelIndex;
		Point pointBuff;
		
		System.out.println("Debut printScreen");

		for(int x = 0; x < width; ++x) {
			for(int y = 0; y < height; ++y) {			
				while((voxelBuff = screenRays[x][y].rayCasting()) != null){
					voxelBuff.displayVoxelCoordinates();
					colorBuff = voxelBuff.getColor();					

					if(colorBuff != null) {
						//pointBuff = new Point(screenRays[x][y].getCurVoxelX(), screenRays[x][y].getCurVoxelY(), screenRays[x][y].getCurVoxelZ());
						pointBuff = screenRays[x][y].interRayVoxel(voxelBuff);
						colorBuff = (isLighted(pointBuff)) ? colorBuff : colorBuff.darker();
						g.setColor(colorBuff);
						this.printPoint(x, y, g);
						continue;
					}
				}
			}
		}
		System.out.println("Fin printScreen");
	}

	public Ray[][] getScreenRays() {
		return screenRays;
	}

	void printPoint(int x, int y, Graphics g) {
		g.drawLine(x, y, x, y);
	}

	public boolean isLighted(Point p0) {
		Point p1;
		Ray lightRay;
		Vector<Light> lights = worldMatrix.getLights();
		Voxel voxelLight, rayVoxel;
		
		for(int i = 0; i < lights.size(); ++i) {
			p1 = lights.get(i).getCoordinates();
			voxelLight = lights.get(i).getVoxel();
			lightRay = new Ray(p0, p1, true);
			while((rayVoxel = lightRay.rayCasting()) != voxelLight) {
				if(rayVoxel.getColor() != null) {
					return false;
				}
			}
		}
		
		return true;
	}

	
}

	

