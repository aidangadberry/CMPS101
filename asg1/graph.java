// Figure A.1

import	java.io.BufferedReader;

public class graph{
	public static void main(String[] argv){
		int	m, n;
		IntList[] adjVertices;

		if (argv.length == 0){
			System.out.println("Usage: java graph input.data");
			System.exit(0);
		}
		String infile = argv[0];
		BufferedReader inbuf = InputLib.fopen(infile);
		System.out.println("Opened " + infile + " for input.");
		String line = InputLib.getLine(inbuf);
		n = LoadGraph.parseN(line);
		System.out.println("n = " + n);

		adjVertices = LoadGraph.initEdges(n);
		m = LoadGraph.loadEdges(inbuf, adjVertices);
		InputLib.fclose(inbuf);
		System.out.println("m = " + m);

		for (int i = 1; i <= n; i ++){
			System.out.println(i + "\t" + adjVertices[i]);
		}
		return;
	}
}