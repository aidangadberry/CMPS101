// Figures A.7-A.8

public class Sort{
	public static boolean less(Comparable x, Comparable y){
		return (x.compareTo(y) < 0);
	}

	public static boolean lessEq(Comparable x, Comparable y){
		return (x.compareTo(y) <= 0); 
	}

	public static boolean eq(Comparable x, Comparable y){
		return (x.compareTo(y) == 0);
	}

	public static boolean greater(Comparable x, Comparable y){
		return (x.compareTo(y) > 0);
	}

	public static boolean greaterEq(Comparable x, Comparable y){
		return (x.compareTo(y) >= 0);
	}

	/** Return new List with newElement inserted in order into oldList. */
	public static List insert1(Comparable newElement, List oldList){
		List  ans;

		if (oldList == List.nil){
			ans = List.cons(newElement, oldList);
		}else{
			Comparable oldFirst = (Comparable)List.first(oldList);

			if (lessEq(newElement, oldFirst)){
				ans = List.cons(newElement, oldList);
			}else{
				List oldRest = List.rest(oldList);
				List newRest = insert1(newElement, oldRest);
				ans = List.cons(oldFirst, newRest);
			}
		}
		return  ans;
	}
}