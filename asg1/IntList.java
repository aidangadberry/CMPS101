// Figure A.11

public class IntList{
	protected int element;
	protected IntList next;
	public static final IntList	nil = null;
	public static int first(IntList aList){
		return aList.element;
	}
	public static IntList rest(IntList aList){
		return aList.next;
	}
	public static IntList cons(int newElement, IntList oldList){
		return new IntList(newElement, oldList);
	}
	// the real constructor, but we want cons() for interface.
	protected IntList(int newElement, IntList oldList){
		element = newElement;
		next = oldList;
	}

	/** Convert IntList to String, similar to prolog, ML style. */
	public String toString(){
		return "[" + toStringR("", this);
	}

	static String toStringR(String prefix, IntList L){
		String s;

		if (L == nil){
			s = "]";
		}else{
			s = prefix + first(L) + toStringR(", ", rest(L));
		}
		return s;
	}
}