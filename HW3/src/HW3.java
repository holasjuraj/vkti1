import java.util.Scanner;

class HW3 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int m = in.nextInt();
		int[][] dist = new int[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dist[i][j] = (i == j) ? 0 : 11111;
			}
		}
		for(int i = 0; i < m; i++){
			int a = in.nextInt(), b = in.nextInt();
			dist[a][b] = dist[b][a] = 1;
		}
		
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}

		int max = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				max = Math.max(max, dist[i][j]);
			}
		}
		
		in.close();
		
		System.out.println(max);
	}

}
