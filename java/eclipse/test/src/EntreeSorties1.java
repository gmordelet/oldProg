import java.io.*;

public class EntreeSorties1 {
	public static void main (String [] args) {
		File f = new File("test");
		try {
			FileWriter fw = new FileWriter(f);
			OutputStream os = new OutputStream();
			fw.write("salut");
			fw.flush();
			fw.close();
		}
		catch(IOException e) {
			System.out.println(e.toString());
		}
	}
}
