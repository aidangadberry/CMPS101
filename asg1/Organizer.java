// Figure A.14

public class Organizer implements Cloneable{
	protected static Organizer copy1level(Organizer t){
		Organizer tCopy;
		tCopy = null; // needed because of try/catch
		try{
			tCopy = (Organizer)t.clone();
		}
		catch(CloneNotSupportedException e){
		}
		return tCopy;
	}
}