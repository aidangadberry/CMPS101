// Figure A.13

public class testA{
	public static void main(String argv[]){
		int	n;
		if (argv.length > 0){
			n = argv[0].length();
		}else{
			n = 0;
		}
		IntListA a = IntListA.cons(1, IntListA.nil);
		IntListA end = a;
		for (int i = 0; i < n; i++){
			IntListA.append1(end, i+2);
			end = IntListA.rest(end);
		}
		System.out.println(a);
		System.out.println(IntListA.first(a));
		System.out.println(IntListA.rest(a));
	}
}