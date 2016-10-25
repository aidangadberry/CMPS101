// Figures A.2-A.4

import java.io.BufferedReader;
import java.util.StringTokenizer;

public class LoadGraph{
	public static IntList[] initEdges(int n){
		IntList[] adjVertices = new IntList[n+1];
		for (int i = 1; i <= n; i++){
			adjVertices[i] = IntList.nil;
		}
		return adjVertices;
	}

	public static int loadEdges(BufferedReader inbuf, IntList[] adjVertices){
		int	num;
		String line;

		num = 0;
		line = InputLib.getLine(inbuf);
		while (line != null){
			Edge e = parseEdge(line);
			adjVertices[e.from] = IntList.cons(e.to, adjVertices[e.from]);
			num++;
			line = InputLib.getLine(inbuf);
		}
		return num;
	}

	static Edge parseEdge(String line){
		StringTokenizer	sTok = new StringTokenizer(line);
		int	numWords = sTok.countTokens();
		if (numWords < 2 || numWords > 3){
			System.err.println("Bad edge: " + line);
			System.exit(1);
		}

		Edge newE = new Edge();
		newE.from = Integer.parseInt(sTok.nextToken());
		newE.to = Integer.parseInt(sTok.nextToken());
		if (numWords == 3){
			newE.weight = Double.parseDouble(sTok.nextToken());
		}else{
			newE.weight = 0.0;
		}
		return newE;
	}

	static class Edge extends Organizer{
		int	from, to;
		double weight;

		public static Edge copy(Edge oldE){
			return (Edge)copy1level(oldE);
		}
	}

	public static int parseN(String line){
		StringTokenizer	sTok = new StringTokenizer(line);
		if (sTok.countTokens() != 1){
			System.err.println("Bad line 1: " + line);
			System.exit(1);
		}

		int	n = Integer.parseInt(sTok.nextToken());
		return n;
	}
}