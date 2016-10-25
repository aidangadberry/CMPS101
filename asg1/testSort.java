// Figure A.10

public class testSort{
	public static void main(String argv[]){
		Integer	i88 = new Integer(88), i66 = new Integer(66);
		WgtEdge	e88 = new WgtEdge(1, 2, 88.0);
		WgtEdge	e66 = new WgtEdge(2, 3, 66.0);
		WgtEdge	e54 = new WgtEdge(1, 4, -54.0);
		WgtEdge	e33 = new WgtEdge(4, 2, 33.0);
		List x1;

		x1 = List.cons(e88, List.nil);
		x1 = List.cons(e66, x1);
		x1 = List.cons(e54, x1);
		System.out.println(x1);
		System.out.println(e33);
		List x2 = Sort.insert1(e33, x1);
		System.out.println(x2);
		System.out.println(Sort.greater("abc", "ab"));
		System.out.println(Sort.greater(i66, i88));
	}
}