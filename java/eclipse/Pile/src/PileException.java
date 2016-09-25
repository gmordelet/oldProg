import java.lang.Exception;

public class PileException extends Exception{
	private int codeErreur;
	
	public PileException(String msg, int code) {
		super(msg);
		codeErreur = code;
	}
	
	public int getCodeErreur() {
		return codeErreur;
	}
}
