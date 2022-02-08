public class clique{
 
	int MAX = 100,n;
	public int[] store = new int[MAX];
	public int[][] graph = new int[MAX][MAX];
	public int[] d = new int[MAX];
	public int[][] edges = {{1,2},{1,3},{1,4},{2,3},{2,4},{3,4},{3,5},{4,5}};
	int k = 3;
	public int size = edges.length;
	public void checkClique(){
		
	}
	public String toString(){
		int i,j;
		String str = "";
		for(i=1;i<=5;i++){
			for(j=1;j<=5;j++){
				str = str + graph[i][j];
			}
			str = str + "\n";
		}
		return str;
	}	
	
}
class MainClass{
	public static void main(String[] args){
		int i;
		clique c = new clique();
		for (i = 0; i < c.size; i++){
			int m1 = c.edges[i][0];
			int m2 = c.edges[i][1];			
			c.graph[m1][m2] = 1;
			c.graph[m2][m1] = 1;
			c.d[m1]++;
			c.d[m2]++;
		}
		System.out.print(c);
	}	
}