// Needed for Sort.java and testSort.java (see also IntList.java)

public class List{
	Object element;
	List next;

	/** The constant nil denotes the empty list.
	 */
	public static final List nil = null;

	/** Precondition: aList != nil.
	 *  Postcondition: Returns first element of aList.
	 */
	public static Object first(List aList){
		return aList.element;
	}

	/** Precondition: aList != nil.
	 *  Postcondition: Returns all elements of aList, except first.
	 */
	public static List rest(List aList){
		return aList.next;
	}

	/** Precondition: None.
	 *  Postcondition: Let newL be the return value.  Then:
	 *      newL refers to a new object, newL != nil,
	 *      first(newL) = newElement, and rest(newL) = oldList.
	 */
	public static List cons(Object newElement, List oldList){
		return new List(newElement, oldList);
	}

	// the real constructor, but we want cons() for interface.
	protected List(Object newElement, List oldList){
		element = newElement;
		next = oldList;
	}

	public String toString(){
		return "[" + toStringR("", this);
	}

	private	static String toStringR(String prefix, List L){
		String s;

		if (L == List.nil){
			s = "]";
		}else{
			s = prefix + List.first(L) + toStringR(", ", List.rest(L));
		}
		return s;
	}
}