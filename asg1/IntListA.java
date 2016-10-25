// Figure A.12

public class IntListA extends IntList{
	// Redefine all members whose result type becomes intListA.
	public static final IntListA nil = (IntListA) IntList.nil;
	public static IntListA rest(IntListA aList){
		return (IntListA) IntList.rest(aList);
	}
	public static IntListA cons(int newElement, IntListA oldList){
		return new IntListA(newElement, oldList);
	}
	// the real constructor, but we want cons for interface.
	protected	IntListA(int newElement, IntListA oldList){
		super(newElement, oldList);
	}

	/** append1 is new in the extended class.
	 *  Precondition: aList != nil.
	 *  Postcondition: aList has newE as additional element at
	 *  the end, after the previous last element.
	 *  That is, suppose previously endL was the suffix of aList
	 *  for which rest(endL) == nil.  Now first(rest(endL)) == newE
	 *  and rest(rest(endL)) == nil.
	 */

	public static void append1(IntListA aList, int newE){
		if (rest(aList) == nil){
			IntListA newLast = cons(newE, nil);
			aList.next = newLast;
		}else{
			append1(rest(aList), newE);
		}
	}
}