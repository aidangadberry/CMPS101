// Figure A.9

public class WgtEdge implements Comparable{
	public int from, to;
	public double weight;

	public WgtEdge(int f, int t, double w){
		from = f; to = t; weight = w;
	}
	public WgtEdge(int f, int t){
		from = f; to = t; weight = 0.0;
	}
	public int compareTo(Object e2){
		Double e1wgt = new Double(weight);
		Double e2wgt = new Double(((WgtEdge)e2).weight);
		return e1wgt.compareTo(e2wgt);
	}
	public String toString(){
		return "(" + from + ", " + to + ", " + weight + ")";
	}
}