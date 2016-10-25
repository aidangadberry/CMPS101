public class IntListLib{
	/** Precondition: none.
	 *  Postcondition: Returns true if and only if L1 and L2
	 *      are equal element by element.
	 */
	public static boolean equal(IntList L1, IntList L2){
		boolean	ans;

		if (L1 == IntList.nil){
			ans = (L2 == IntList.nil);
		}else if (L2 == IntList.nil){
			ans = false;
		}else if (IntList.first(L1) != IntList.first(L2)){
			ans = false;
		}else{
			ans = equal(IntList.rest(L1), IntList.rest(L2));
		}
		return ans;
	}

	/** Precondition: none.
	 *  Postcondition: Returns true if and only if L1 is a
	 *  list suffix of L2.
	 */

	public static boolean suffix(IntList L1, IntList L2){
		boolean	ans;

		if (equal(L1, L2)){
			ans = true;
		}else if (L2 == IntList.nil){
			ans = false;
		}else{
			ans = suffix(L1, IntList.rest(L2));
		}
		return ans;
	}

	// convert IntList to string, similar to prolog, ML style.

	public static String toString(IntList L){
		return "[" + toStringR("", L);
	}

	static String toStringR(String prefix, IntList L){
		String s;

		if (L == IntList.nil){
			s = "]";
		}else{
			s = prefix + IntList.first(L) + toStringR(", ", IntList.rest(L));
		}
		return s;
	}
}